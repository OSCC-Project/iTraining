// ***************************************************************************************
// Copyright (c) 2023-2025 Peng Cheng Laboratory
// Copyright (c) 2023-2025 Institute of Computing Technology, Chinese Academy of Sciences
// Copyright (c) 2023-2025 Beijing Institute of Open Source Chip
//
// iEDA is licensed under Mulan PSL v2.
// You can use this software according to the terms and conditions of the Mulan PSL v2.
// You may obtain a copy of Mulan PSL v2 at:
// http://license.coscl.org.cn/MulanPSL2
//
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
// EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
// MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
//
// See the Mulan PSL v2 for more details.
// ***************************************************************************************

#include "Tetris.hh"

#include <iostream>
#include <map>

#include "LGDatabase.hh"
#include "LGInstance.hh"
#include "LGInterval.hh"

namespace ieda_solver {

  Tetris::~Tetris()
  {
    for (auto pair : _cluster_map) {
      delete pair.second;
    }
    _cluster_map.clear();
    _inst_belong_cluster.clear();
    _interval_cluster_root.clear();
    _interval_remain_length.clear();
  }

  void Tetris::initDataRequirement(ipl::LGConfig* lg_config, ipl::LGDatabase* lg_database)
  {
    // clean Tetris info first.
    _cluster_map.clear();
    _inst_belong_cluster.clear();
    _interval_cluster_root.clear();
    _interval_remain_length.clear();

    _database = lg_database;
    _config = lg_config;

    _inst_belong_cluster.resize(_database->get_lgInstance_list().size(), nullptr);

    int32_t interval_cnt = 0;
    for (auto& interval_vec : _database->get_lg_layout()->get_interval_2d_list()) {
      for (auto* interval : interval_vec) {
        interval_cnt++;
        _interval_remain_length.push_back(interval->get_max_x() - interval->get_min_x());
      }
    }
    _interval_cluster_root.resize(interval_cnt, nullptr);

    _row_height = _database->get_lg_layout()->get_row_height();
    _site_width = _database->get_lg_layout()->get_site_width();
  }

  bool Tetris::isInitialized()
  {
    return !_cluster_map.empty();
  }

  void Tetris::specifyTargetInstList(std::vector<ipl::LGInstance*>& target_inst_list)
  {
    _target_inst_list.clear();
    _target_inst_list = target_inst_list;
  }

  bool Tetris::runLegalization()
  {
    // 对所有可移动单元进行排序，使用 effective_x 排序
    std::vector<ipl::LGInstance*> movable_inst_list;
    pickAndSortMovableInstList(movable_inst_list);

    // 遍历所有可移动单元
    for (auto* inst : movable_inst_list) {
      // 获取当前布局的行高
      int32_t row_height = _database->get_lg_layout()->get_row_height();
      // 根据单元的 y 坐标计算初始的行索引
      int32_t row_idx = int32_t(inst->get_coordi().get_y() / row_height);

      // 初始行的放置代价
      int32_t row_avail = INT32_MAX;
      int32_t row_cost = INT32_MAX;
      // 尝试在初始行放置单元
      int32_t cost = placeRow(inst, row_idx, false, false);
      // 在附近的行中寻找更好的放置位置
      for (int i = 1;;i++) {
        // 如果在当前行的放置是有效的（代价不为最大值），则停止搜索
        if (cost != INT32_MAX) {
          break;
        }
        // 如果超出了可用的行范围，则停止搜索
        if (row_idx + i >= _database->get_lg_layout()->get_row_num() && row_idx - i < 0) {
          break;
        }
        // 尝试在向上的第 i 行放置单元
        if (row_idx + i < _database->get_lg_layout()->get_row_num()) {
          cost = placeRow(inst, row_idx + i, true, false);
          if (cost < row_cost) {
            row_cost = cost;
            row_avail = row_idx + i;
          }
        }
        // 尝试在向下的第 i 行放置单元
        if (row_idx - i >= 0) {
          cost = placeRow(inst, row_idx - i, true, false);
          if (cost < row_cost) {
            row_cost = cost;
            row_avail = row_idx - i;
          }
        }
      }
      // 如果找到了一个比初始行更合适的行，并且行索引不同，则将单元放置在该行
      if (row_avail != INT32_MAX && row_avail != row_idx) {
        placeRow(inst, row_avail, false, false);
      }
    }
    return true;
  }

  // bool Tetris::runLegalization()
  // {
  //   // Sort all movable instances
  //   std::vector<ipl::LGInstance*> movable_inst_list;
  //   pickAndSortMovableInstList(movable_inst_list);

  //   int32_t inst_id = 0;
  //   for (auto* inst : movable_inst_list) {

  //     int32_t best_row = INT32_MAX;
  //     int32_t best_cost = INT32_MAX;
  //     for (int32_t row_idx = 0; row_idx < _database->get_lg_layout()->get_row_num(); row_idx++) {
  //       int32_t cost = placeRow(inst, row_idx, true, false);

  //       if (cost < best_cost) {
  //         best_cost = cost;
  //         best_row = row_idx;
  //       }
  //     }

  //     if (best_row == INT32_MAX) {
  //       LOG_ERROR << "Instance: " << inst->get_name() << "Cannot find a row for placement";
  //       return false;
  //     }

  //     placeRow(inst, best_row, false, false);

  //     inst_id++;
  //     if (inst_id % 100000 == 0) {
  //       LOG_INFO << "Place Instance : " << inst_id;
  //     }
  //   }

  //   return true;
  // }

  bool Tetris::runIncrLegalization()
  {
    int32_t row_range_num = 5;
    int32_t row_num = _database->get_lg_layout()->get_row_num();

    // spilt new inst from the cluster.
    RollbackInfo2 rollback_info;
    for (auto* inst : _target_inst_list) {
      splitTargetInst(inst, rollback_info);
    }
    rollback_info.is_dirty = true;
    _rollback_stack.push(rollback_info);

    for (auto* inst : _target_inst_list) {
      int32_t row_idx = inst->get_coordi().get_y() / _row_height;
      int32_t max_row_idx = (row_idx + row_range_num > row_num) ? row_num : row_idx + row_range_num;
      int32_t min_row_idx = (row_idx - row_range_num < 0) ? 0 : row_idx - row_range_num;

      int32_t best_row = INT32_MAX;
      int32_t best_cost = INT32_MAX;
      for (int32_t row_idx = min_row_idx; row_idx < max_row_idx; row_idx++) {
        int32_t cost = placeRow(inst, row_idx, true, false);
        if (cost < best_cost) {
          best_cost = cost;
          best_row = row_idx;
        }
      }
      placeRow(inst, best_row, false, true);
    }

    return true;
  }

  // void Tetris::pickAndSortMovableInstList(std::vector<ipl::LGInstance*>& movable_inst_list)
  // {
  //   double max_weight = INT32_MIN;
  //   double min_weight = INT32_MAX;
  //   double radio = 0.05; // 单元宽度权重

  //   for (auto* inst : _database->get_lgInstance_list()) {
  //       if (inst->get_state() == ipl::LGINSTANCE_STATE::kFixed) {
  //           continue;
  //       }
  //       // 设置单元归一化权重
  //       max_weight = max_weight < (1 - radio) * inst->get_coordi().get_x() - radio * inst->get_shape().get_width()
  //                    ? (1 - radio) * inst->get_coordi().get_x() - radio * inst->get_shape().get_width()
  //                    : max_weight;
  //       min_weight = min_weight > (1 - radio) * inst->get_coordi().get_x() - radio * inst->get_shape().get_width()
  //                    ? (1 - radio) * inst->get_coordi().get_x() - radio * inst->get_shape().get_width()
  //                    : min_weight;
  //       movable_inst_list.push_back(inst);
  //   }

  //   for (auto* inst : movable_inst_list) {
  //       inst->set_weight((max_weight - (1 - radio) * inst->get_coordi().get_x() + radio * inst->get_shape().get_width())
  //                        / (max_weight - min_weight));
  //   }

  //   // 根据权重进行排序
  //   std::sort(movable_inst_list.begin(), movable_inst_list.end(),
  //             [](ipl::LGInstance* l_inst, ipl::LGInstance* r_inst) {
  //                 return l_inst->get_weight() > r_inst->get_weight();
  //             });
  // }

  void Tetris::pickAndSortMovableInstList(std::vector<ipl::LGInstance*>& movable_inst_list)
  {
    float width_factor = 0.2;

    // 遍历数据库中的所有单元实例
    for (auto* inst : _database->get_lgInstance_list()) {
      // 跳过状态为固定的单元实例，因为这些单元不能移动
      if (inst->get_state() == ipl::LGINSTANCE_STATE::kFixed) {
        continue;
      }
      // 将可以移动的单元实例添加到列表中
      movable_inst_list.push_back(inst);
    }

    std::sort(movable_inst_list.begin(), movable_inst_list.end(), [width_factor](ipl::LGInstance* l_inst, ipl::LGInstance* r_inst) {
      // 计算左侧单元实例的 effective_x 值
      float effective_x_l = l_inst->get_coordi().get_x() - l_inst->get_shape().get_width() * width_factor;
      // 计算右侧单元实例的 effective_x 值
      float effective_x_r = r_inst->get_coordi().get_x() - r_inst->get_shape().get_width() * width_factor;
      // 根据 effective_x 值从小到大排序
      return effective_x_l < effective_x_r;
      });
  }

  int32_t Tetris::placeRow(ipl::LGInstance* inst, int32_t row_idx, bool is_trial, bool is_record_cluster)
  {
    ipl::Rectangle<int32_t> inst_shape = std::move(inst->get_shape());

    // Determine clusters and their optimal positions x_c(c):
    std::vector<ipl::LGInterval*> interval_list = _database->get_lg_layout()->get_interval_2d_list()[row_idx];

    // Select the nearest interval for the instance
    int32_t row_interval_idx = searchNearestIntervalIndex(interval_list, inst_shape);
    if (row_interval_idx == INT32_MAX) {
      // std::cout << "Instance is not overlap with interval!" << std::endl;
      return INT32_MAX;
    }

    if (_interval_remain_length[interval_list[row_interval_idx]->get_index()] < inst_shape.get_width()) {
      // Select the most recent non-full interval
      int32_t origin_idx = row_interval_idx;
      row_interval_idx = searchRemainSpaceSegIndex(interval_list, inst_shape, origin_idx);
      if (row_interval_idx == origin_idx) {
        // LOG_INFO << "Row : " << row_idx << " has no room to place.";
        return INT32_MAX;
      }
    }

    // Arrange inst into interval
    auto* target_interval = interval_list[row_interval_idx];
    TetrisCluster target_cluster = std::move(arrangeInstIntoIntervalCluster(inst, target_interval));

    // Calculate cost
    int32_t movement_cost = 0;
    int32_t coordi_x = target_cluster.get_min_x();
    int32_t inst_movement_x = INT32_MAX;
    for (auto* target_inst : target_cluster.get_inst_list()) {
      int32_t origin_x = target_inst->get_coordi().get_x();
      if (target_inst == inst) {
        inst_movement_x = std::abs(coordi_x - origin_x);
      }
      else {
        movement_cost += std::abs(coordi_x - origin_x);
      }
      coordi_x += target_inst->get_shape().get_width();
    }
    // Add Inst Coordi Movement Cost
    int32_t inst_movement_y = std::abs(row_idx * _row_height - inst_shape.get_ll_y());
    int32_t inst_displacement = inst_movement_x + inst_movement_y;
    movement_cost += inst_displacement;

    // Penalize violations of maximum movement constraints
    if (inst_displacement > _config->get_max_displacement()) {
      movement_cost += _database->get_lg_layout()->get_max_x();
    }

    // Replace cluster

    if (!is_trial) {
      replaceClusterInfo(target_cluster, is_record_cluster);
      this->updateRemainLength(target_interval, -(inst->get_shape().get_width()));

      // debug
      // if (target_interval->get_name() == "30_1") {
      //   LOG_INFO << "***placeRow***";
      //   debugIntervalRemainLength(target_interval->get_name());
      // }
    }

    return movement_cost;
  }

  int32_t Tetris::searchNearestIntervalIndex(std::vector<ipl::LGInterval*>& segment_list, ipl::Rectangle<int32_t>& inst_shape)
  {
    if (segment_list.size() == 1) {
      return 0;
    }

    int32_t prev_distance = INT32_MAX;
    int32_t segment_idx = INT32_MAX;
    for (size_t i = 0; i < segment_list.size(); i++) {
      int32_t cur_distance
        = calDistanceWithBox(inst_shape.get_ll_x(), inst_shape.get_ur_x(), segment_list[i]->get_min_x(), segment_list[i]->get_max_x());
      if (cur_distance > prev_distance) {
        segment_idx = i - 1;
        break;
      }
      if (cur_distance == 0) {
        segment_idx = i;
        break;
      }

      prev_distance = cur_distance;
    }

    return segment_idx;
  }

  int32_t Tetris::calDistanceWithBox(int32_t min_x, int32_t max_x, int32_t box_min_x, int32_t box_max_x)
  {
    if (max_x >= box_min_x && min_x <= box_max_x) {
      return 0;
    }
    else if (min_x > box_max_x) {
      return (min_x - box_max_x);
    }
    else if (max_x < box_min_x) {
      return (box_min_x - max_x);
    }
    else {
      return INT32_MAX;
    }
  }

  int32_t Tetris::searchRemainSpaceSegIndex(std::vector<ipl::LGInterval*>& segment_list, ipl::Rectangle<int32_t>& inst_shape,
    int32_t origin_index)
  {
    int32_t segment_idx = origin_index;
    // int32_t max_range = segment_list.size() - 1;
    int32_t max_range = 2;
    int32_t range = 1;
    while (range <= max_range) {
      int32_t r_idx = segment_idx;
      if (r_idx + range < static_cast<int32_t>(segment_list.size())) {
        r_idx += range;
        int32_t interval_idx = segment_list[r_idx]->get_index();
        if (_interval_remain_length[interval_idx] >= inst_shape.get_width()) {
          segment_idx = r_idx;
          break;
        }
      }
      int32_t l_idx = segment_idx;
      if (l_idx - range >= 0) {
        l_idx -= range;
        int32_t interval_idx = segment_list[l_idx]->get_index();
        if (_interval_remain_length[interval_idx] >= inst_shape.get_width()) {
          segment_idx = l_idx;
          break;
        }
      }
      range++;
    }
    return segment_idx;
  }

  TetrisCluster Tetris::arrangeInstIntoIntervalCluster(ipl::LGInstance* inst, ipl::LGInterval* interval)
  {
    auto inst_shape = std::move(inst->get_shape());
    TetrisCluster record_cluster;
    auto* cur_cluster = _interval_cluster_root[interval->get_index()];
    auto* last_cluster = cur_cluster;
    bool is_collapse = false;

    if (cur_cluster && (inst_shape.get_ur_x() < cur_cluster->get_min_x())) {
      // should insert in the cluster
      record_cluster = *cur_cluster;
      record_cluster.insertInstance(inst);
      legalizeCluster(record_cluster);
      is_collapse = true;
    }
    else {
      while (cur_cluster) {
        if (checkOverlapWithBox(inst_shape.get_ll_x(), inst_shape.get_ur_x(), cur_cluster->get_min_x(), cur_cluster->get_max_x())) {
          record_cluster = *cur_cluster;
          record_cluster.insertInstance(inst);
          legalizeCluster(record_cluster);
          is_collapse = true;
          break;
        }
        auto* back_cluster = findCluster(cur_cluster->get_back_cluster());
        if (back_cluster) {
          // tmp fix bug.
          if (inst_shape.get_ll_x() >= cur_cluster->get_max_x() && inst_shape.get_ur_x() <= back_cluster->get_min_x()) {
            record_cluster = *cur_cluster;
            record_cluster.insertInstance(inst);
            legalizeCluster(record_cluster);
            is_collapse = true;
            break;
          }

          last_cluster = back_cluster;
        }
        cur_cluster = back_cluster;
      }
    }

    if (!is_collapse) {
      // Create new cluster
      std::string cluster_name = obtainUniqueClusterName(inst->get_name());
      record_cluster = TetrisCluster(cluster_name);

      // auto* exist_cluster = findCluster(inst->get_name());
      // if (exist_cluster) {
      //   record_cluster = TetrisCluster(exist_cluster->get_name() + "_2024");
      // }
      // else {
      //   record_cluster = TetrisCluster(inst->get_name());
      // }
      // // record_cluster = TetrisCluster(inst->get_name());

      record_cluster.add_inst(inst);
      record_cluster.appendInst(inst);
      record_cluster.set_belong_interval(interval);
      if (last_cluster) {
        record_cluster.set_front_cluster(last_cluster->get_name());
      }
      legalizeCluster(record_cluster);
    }

    return record_cluster;
  }

  void Tetris::legalizeCluster(TetrisCluster& cluster)
  {
    arrangeClusterMinXCoordi(cluster);
    int32_t cur_min_x, front_max_x, back_min_x;
    cur_min_x = cluster.get_min_x();
    front_max_x = obtainFrontMaxX(cluster);

    back_min_x = obtainBackMinX(cluster);
    while ((cur_min_x < front_max_x) || (cur_min_x + cluster.get_total_width() > back_min_x)) {
      while (cur_min_x < front_max_x) {
        TetrisCluster front_cluster = *(this->findCluster(cluster.get_front_cluster()));
        mergeWithPreviousCluster(cluster, front_cluster);
        arrangeClusterMinXCoordi(cluster);
        cur_min_x = cluster.get_min_x();
        front_max_x = obtainFrontMaxX(cluster);

        // front_cluster.appendCluster(cluster);

        // front_cluster.set_back_cluster(cluster.get_back_cluster());
        // arrangeClusterMinXCoordi(front_cluster);
        // cur_min_x = front_cluster.get_min_x();
        // front_max_x = obtainFrontMaxX(front_cluster);
        // cluster = front_cluster;
      }

      cur_min_x = cluster.get_min_x();
      back_min_x = obtainBackMinX(cluster);
      while (cur_min_x + cluster.get_total_width() > back_min_x) {
        auto* back_cluster = this->findCluster(cluster.get_back_cluster());
        mergeWithNextCluster(cluster, *back_cluster);

        // cluster.appendCluster(*back_cluster);
        // cluster.set_back_cluster(back_cluster->get_back_cluster());
        arrangeClusterMinXCoordi(cluster);
        cur_min_x = cluster.get_min_x();
        back_min_x = obtainBackMinX(cluster);
      }
    }
  }

  void Tetris::mergeWithPreviousCluster(TetrisCluster& cluster, TetrisCluster prev_cluster)
  {
    TetrisCluster tmp_cluster(cluster.get_name());
    tmp_cluster.set_belong_interval(cluster.get_belong_interval());
    tmp_cluster.appendInstList(prev_cluster.get_inst_list());
    tmp_cluster.appendCluster(cluster);

    tmp_cluster.set_front_cluster(prev_cluster.get_front_cluster());
    tmp_cluster.set_back_cluster(cluster.get_back_cluster());

    cluster = std::move(tmp_cluster);
  }

  void Tetris::mergeWithNextCluster(TetrisCluster& cluster, TetrisCluster next_cluster)
  {
    cluster.appendCluster(next_cluster);
    cluster.set_back_cluster(next_cluster.get_back_cluster());
  }

  void Tetris::arrangeClusterMinXCoordi(TetrisCluster& cluster)
  {
    int32_t cluster_x = (cluster.get_weight_q() / cluster.get_weight_e());
    cluster_x = (cluster_x / _site_width) * _site_width;

    int32_t boundary_min_x = cluster.get_belong_interval()->get_min_x();
    int32_t boundary_max_x = cluster.get_belong_interval()->get_max_x();
    cluster_x < boundary_min_x ? cluster_x = boundary_min_x : cluster_x;
    cluster_x + cluster.get_total_width() > boundary_max_x ? cluster_x = boundary_max_x - cluster.get_total_width() : cluster_x;

    if (cluster_x < boundary_min_x) {
      std::cout << "Cluster width is out of interval capcity" << std::endl;
    }

    cluster.set_min_x(cluster_x);
  }

  int32_t Tetris::obtainFrontMaxX(TetrisCluster& cluster)
  {
    int32_t front_max_x = cluster.get_belong_interval()->get_min_x();
    auto* front_cluster = this->findCluster(cluster.get_front_cluster());
    if (front_cluster) {
      front_max_x = front_cluster->get_max_x();
    }
    return front_max_x;
  }

  int32_t Tetris::obtainBackMinX(TetrisCluster& cluster)
  {
    int32_t back_min_x = cluster.get_belong_interval()->get_max_x();
    auto* back_cluster = this->findCluster(cluster.get_back_cluster());
    if (back_cluster) {
      back_min_x = back_cluster->get_min_x();
    }
    return back_min_x;
  }

  bool Tetris::checkOverlapWithBox(int32_t min_x, int32_t max_x, int32_t box_min_x, int32_t box_max_x)
  {
    if (max_x > box_min_x && min_x < box_max_x) {
      return true;
    }
    else {
      return false;
    }
  }

  void Tetris::replaceClusterInfo(TetrisCluster& modify_cluster, bool is_record_cluster)
  {
    auto* origin_interval = modify_cluster.get_belong_interval();
    int32_t coordi_y = origin_interval->get_belong_row()->get_coordinate().get_y();

    // record rollback info
    RollbackInfo2 rollback_info;

    auto* cluster_ptr = this->findCluster(modify_cluster.get_name());
    std::string origin_back_cluster_name = "";
    if (!cluster_ptr) {
      TetrisCluster* new_cluster = new TetrisCluster(modify_cluster);
      this->insertCluster(new_cluster->get_name(), new_cluster);
      cluster_ptr = new_cluster;

      if (is_record_cluster) {
        rollback_info.addition_clusters.push_back(modify_cluster);
      }
    }
    else {
      if (is_record_cluster) {
        rollback_info.origin_clusters.push_back(*cluster_ptr);
        rollback_info.addition_clusters.push_back(modify_cluster);
      }

      origin_back_cluster_name = cluster_ptr->get_back_cluster();
      *cluster_ptr = std::move(modify_cluster);
    }

    auto* origin_root = _interval_cluster_root[origin_interval->get_index()];
    std::string front_cluster_name = cluster_ptr->get_front_cluster();
    std::string back_cluster_name = cluster_ptr->get_back_cluster();
    auto* front_cluster = this->findCluster(front_cluster_name);
    auto* back_cluster = this->findCluster(back_cluster_name);

    // front cluster case
    if (!origin_root && !front_cluster) {
      // cur cluster is root
      _interval_cluster_root[origin_interval->get_index()] = cluster_ptr;
    }
    else if (origin_root && !front_cluster) {
      // from origin root to cur cluster need to erase.
      auto* tmp_cluster = origin_root;
      while (tmp_cluster->get_name() != cluster_ptr->get_name()) {
        if (is_record_cluster) {
          rollback_info.origin_clusters.push_back(*tmp_cluster);
        }

        std::string delete_cluster_name = tmp_cluster->get_name();
        tmp_cluster = this->findCluster(tmp_cluster->get_back_cluster());
        this->deleteCluster(delete_cluster_name);
        if (!tmp_cluster) {
          break;
        }
      }
      _interval_cluster_root[origin_interval->get_index()] = cluster_ptr;
    }
    else if (!origin_root && front_cluster) {
      LOG_ERROR << "Interval root is not recorded!!!";
    }
    else {
      // from front cluster to cur cluster need to erase.
      auto* tmp_cluster = this->findCluster(front_cluster->get_back_cluster());
      while (tmp_cluster && (tmp_cluster->get_name() != cluster_ptr->get_name())) {
        if (is_record_cluster) {
          rollback_info.origin_clusters.push_back(*tmp_cluster);
        }

        std::string delete_cluster_name = tmp_cluster->get_name();
        tmp_cluster = this->findCluster(tmp_cluster->get_back_cluster());
        this->deleteCluster(delete_cluster_name);
      }
    }

    // back cluster case
    auto* origin_back_cluster = this->findCluster(origin_back_cluster_name);
    if (!back_cluster && !origin_back_cluster) {
      //
    }
    else if (back_cluster && !origin_back_cluster) {
      LOG_ERROR << "Back cluster is not recorded !!!";
    }
    else if (!back_cluster && origin_back_cluster) {
      auto* tmp_cluster = origin_back_cluster;
      while (tmp_cluster) {
        if (is_record_cluster) {
          rollback_info.origin_clusters.push_back(*tmp_cluster);
        }

        std::string delete_cluster_name = tmp_cluster->get_name();
        tmp_cluster = this->findCluster(tmp_cluster->get_back_cluster());
        this->deleteCluster(delete_cluster_name);
      }
    }
    else {
      // from origin_back_cluster to back_cluster need to erase.
      auto* tmp_cluster = origin_back_cluster;
      while (tmp_cluster && (tmp_cluster->get_name() != back_cluster->get_name())) {
        if (is_record_cluster) {
          rollback_info.origin_clusters.push_back(*tmp_cluster);
        }

        std::string delete_cluster_name = tmp_cluster->get_name();
        tmp_cluster = this->findCluster(tmp_cluster->get_back_cluster());
        this->deleteCluster(delete_cluster_name);
      }
    }

    if (front_cluster) {
      front_cluster->set_back_cluster(cluster_ptr->get_name());
    }
    if (back_cluster) {
      back_cluster->set_front_cluster(cluster_ptr->get_name());
    }

    // update all inst info
    int32_t coordi_x = cluster_ptr->get_min_x();
    for (auto* inst : cluster_ptr->get_inst_list()) {
      _inst_belong_cluster[inst->get_index()] = cluster_ptr;
      inst->updateCoordi(coordi_x, coordi_y);
      coordi_x += inst->get_shape().get_width();
    }

    // record
    if (is_record_cluster) {
      rollback_info.is_dirty = true;
      _rollback_stack.push(rollback_info);
    }
  }

  // void Tetris::replaceClusterInfo(TetrisCluster& modify_cluster, bool is_record_cluster)
  // {
  //   auto* origin_interval = modify_cluster.get_belong_interval();
  //   int32_t coordi_y = origin_interval->get_belong_row()->get_coordinate().get_y();

  //   auto* cluster_ptr = this->findCluster(modify_cluster.get_name());
  //   if (!cluster_ptr) {
  //     TetrisCluster* new_cluster = new TetrisCluster(std::move(modify_cluster));
  //     auto inst_list = new_cluster->get_inst_list();
  //     if (inst_list.size() > 1 || inst_list.size() == 0) {
  //       std::cout << "Cluster Inst is not correctly set" << std::endl;
  //     }

  //     // cluster setting.
  //     _inst_belong_cluster[inst_list[0]->get_index()] = new_cluster;
  //     inst_list[0]->updateCoordi(new_cluster->get_min_x(), coordi_y);

  //     this->insertCluster(new_cluster->get_name(), new_cluster);

  //     // front cluster.
  //     std::string front_cluster_name = new_cluster->get_front_cluster();
  //     std::string back_cluster_name = new_cluster->get_back_cluster();
  //     auto* front_cluster = findCluster(front_cluster_name);
  //     auto* back_cluster = findCluster(back_cluster_name);
  //     if (front_cluster) {
  //       front_cluster->set_back_cluster(new_cluster->get_name());

  //       // assert
  //       if (back_cluster) {
  //         if (back_cluster_name != new_cluster->get_back_cluster()) {
  //           LOG_WARNING << "Unrecord back cluster!!!";
  //         }
  //       }
  //     }
  //     else {
  //       if (_interval_cluster_root[origin_interval->get_index()]) {
  //         LOG_WARNING << "Unrecord front cluster!!!";
  //       }
  //       else {
  //         _interval_cluster_root[origin_interval->get_index()] = new_cluster;
  //       }
  //     }

  //     if (back_cluster) {
  //       back_cluster->set_front_cluster(new_cluster->get_name());
  //     }

  //     if (is_record_cluster) {
  //       RollbackInfo2 rollback_info;
  //       rollback_info.is_dirty = true;
  //       rollback_info.addition_clusters.push_back(*new_cluster);
  //       _rollback_stack.push(rollback_info);
  //     }
  //     return;
  //   }

  //   auto& origin_cluster = *(cluster_ptr);
  //   auto* origin_root = _interval_cluster_root[origin_interval->get_index()];

  //   // record rollback info
  //   RollbackInfo2 rollback_info;

  //   // may be collapsing with front or back cluster
  //   TetrisCluster* front_origin = this->findCluster(origin_cluster.get_front_cluster());
  //   TetrisCluster* front_modify = this->findCluster(modify_cluster.get_front_cluster());
  //   while (front_origin != front_modify) {
  //     if (is_record_cluster && front_origin) {
  //       rollback_info.origin_clusters.push_back(*front_origin);
  //     }

  //     if (front_origin == origin_root) {
  //       _interval_cluster_root[origin_interval->get_index()] = &origin_cluster;
  //     }

  //     std::string delete_cluster = front_origin->get_name();
  //     front_origin = this->findCluster(front_origin->get_front_cluster());
  //     if (front_origin) {
  //       front_origin->set_back_cluster(origin_cluster.get_name());
  //     }
  //     this->deleteCluster(delete_cluster);
  //   }

  //   // test
  //   if (is_record_cluster) {
  //     rollback_info.addition_clusters.push_back(modify_cluster);
  //     rollback_info.origin_clusters.push_back(origin_cluster);
  //   }

  //   TetrisCluster* back_origin = this->findCluster(origin_cluster.get_back_cluster());
  //   TetrisCluster* back_modify = this->findCluster(modify_cluster.get_back_cluster());
  //   while (back_origin != back_modify) {
  //     if (is_record_cluster && back_origin) {
  //       rollback_info.origin_clusters.push_back(*back_origin);
  //     }

  //     std::string delete_cluster = back_origin->get_name();

  //     back_origin = this->findCluster(back_origin->get_back_cluster());
  //     if (back_origin) {
  //       back_origin->set_front_cluster(origin_cluster.get_name());
  //     }
  //     this->deleteCluster(delete_cluster);
  //   }

  //   // update all inst info
  //   origin_cluster = std::move(modify_cluster);
  //   int32_t coordi_x = origin_cluster.get_min_x();
  //   for (auto* inst : origin_cluster.get_inst_list()) {
  //     _inst_belong_cluster[inst->get_index()] = &origin_cluster;
  //     inst->updateCoordi(coordi_x, coordi_y);
  //     coordi_x += inst->get_shape().get_width();
  //   }

  //   // final push rollback stack
  //   if (is_record_cluster) {
  //     rollback_info.is_dirty = true;
  //     _rollback_stack.push(rollback_info);
  //   }
  // }

  TetrisCluster* Tetris::findCluster(std::string cluster_name)
  {
    if (cluster_name == "") {
      return nullptr;
    }
    TetrisCluster* cluster = nullptr;
    auto it = _cluster_map.find(cluster_name);
    if (it != _cluster_map.end()) {
      cluster = it->second;
    }

    return cluster;
  }

  void Tetris::insertCluster(std::string name, TetrisCluster* cluster)
  {
    auto it = _cluster_map.find(name);
    if (it != _cluster_map.end()) {
      std::cout << "Cluster : " << name << " was added before" << std::endl;
    }
    _cluster_map.emplace(name, cluster);
  }

  void Tetris::deleteCluster(std::string name)
  {
    auto it = _cluster_map.find(name);
    if (it != _cluster_map.end()) {
      _cluster_map.erase(it);
    }
    else {
      std::cout << "Cluster: " << name << " has not been insert" << std::endl;
    }
  }

  void Tetris::updateRemainLength(ipl::LGInterval* interval, int32_t delta)
  {
    int32_t cur_value = _interval_remain_length[interval->get_index()];
    _interval_remain_length[interval->get_index()] = cur_value + delta;
  }

  void Tetris::splitTargetInst(ipl::LGInstance* inst, RollbackInfo2& rollback_info)
  {
    int32_t inst_width = inst->get_shape().get_width();
    auto* target_cluster = _inst_belong_cluster[inst->get_index()];
    ipl::LGInterval* target_interval = target_cluster->get_belong_interval();
    int32_t target_size = target_cluster->get_inst_list().size();

    rollback_info.origin_clusters.push_back(*target_cluster);

    if (target_size == 1) {
      auto* front_cluster = this->findCluster(target_cluster->get_front_cluster());
      auto* back_cluster = this->findCluster(target_cluster->get_back_cluster());
      if (!front_cluster && !back_cluster) {
        //
      }
      else if (!front_cluster && back_cluster) {
        back_cluster->set_front_cluster("");
      }
      else if (front_cluster && !back_cluster) {
        front_cluster->set_back_cluster("");
      }
      else {
        front_cluster->set_back_cluster(back_cluster->get_name());
        back_cluster->set_front_cluster(front_cluster->get_name());
      }

      // move the root
      if (_interval_cluster_root[target_interval->get_index()]->get_name() == target_cluster->get_name()) {
        _interval_cluster_root[target_interval->get_index()] = back_cluster;
      }

      deleteCluster(target_cluster->get_name());
    }
    else {
      int32_t inst_idx = target_cluster->obtainInstIdx(inst);
      if (inst_idx == -1) {
        LOG_WARNING << "Inst is not in target cluster!!!";
        return;
      }

      if ((inst_idx == 0) || (inst_idx == target_size - 1)) {
        target_cluster->eraseTargetInstByIdx(inst_idx);
        int32_t min_x = target_cluster->get_inst_list().front()->get_coordi().get_x();
        target_cluster->set_min_x(min_x);
        target_cluster->updateTetrisInfo();
      }
      else if ((inst_idx > 0) && (inst_idx < target_size)) {
        // split cluster
        std::vector<ipl::LGInstance*> origin_inst_list = target_cluster->get_inst_list();
        std::vector<ipl::LGInstance*> new_inst_list(origin_inst_list.begin() + inst_idx + 1, origin_inst_list.end());
        target_cluster->eraseTargetInstByIdxPair(inst_idx, target_size - 1);
        target_cluster->updateTetrisInfo();

        // add new cluster
        ipl::LGInstance* flag_inst = new_inst_list[0];

        TetrisCluster* new_cluster;
        std::string cluster_name = obtainUniqueClusterName(flag_inst->get_name());
        new_cluster = new TetrisCluster(cluster_name);

        // auto* exist_cluster = findCluster(flag_inst->get_name());
        // if (exist_cluster) {
        //   new_cluster = new TetrisCluster(exist_cluster->get_name() + "_2024");
        // }
        // else {
        //   new_cluster = new TetrisCluster(flag_inst->get_name());
        // }

        new_cluster->appendInstList(new_inst_list);
        new_cluster->set_min_x(flag_inst->get_coordi().get_x());
        // update inst to cluster
        for (auto* inst : new_cluster->get_inst_list()) {
          _inst_belong_cluster[inst->get_index()] = new_cluster;
        }

        new_cluster->updateTetrisInfo();
        new_cluster->set_belong_interval(target_interval);
        new_cluster->set_front_cluster(target_cluster->get_name());
        std::string back_cluster_name = target_cluster->get_back_cluster();
        auto* back_cluster = findCluster(back_cluster_name);
        if (back_cluster) {
          new_cluster->set_back_cluster(back_cluster_name);
          back_cluster->set_front_cluster(new_cluster->get_name());
        }
        target_cluster->set_back_cluster(new_cluster->get_name());

        this->insertCluster(new_cluster->get_name(), new_cluster);
        rollback_info.addition_clusters.push_back(*new_cluster);
      }
      rollback_info.addition_clusters.push_back(*target_cluster);
    }

    _inst_belong_cluster[inst->get_index()] = nullptr;
    _interval_remain_length[target_interval->get_index()] += inst_width;

    // debug
    // if (target_interval->get_name() == "30_1") {
    //   LOG_INFO << "***Split***";
    //   debugIntervalRemainLength(target_interval->get_name());
    // }
  }

  bool Tetris::runRollback(bool clear_but_not_rollback)
  {
    if (clear_but_not_rollback) {
      // clear.
      std::stack<RollbackInfo2>().swap(_rollback_stack);
      return true;
    }

    while (!_rollback_stack.empty()) {
      auto& rollback_info = _rollback_stack.top();

      if (!rollback_info.is_dirty) {
        _rollback_stack.pop();
        continue;
      }

      std::map<ipl::LGInterval*, std::vector<TetrisCluster>> interval_to_clusters;
      for (auto& cluster : rollback_info.addition_clusters) {
        ipl::LGInterval* target_interval = cluster.get_belong_interval();
        auto it = interval_to_clusters.find(target_interval);
        if (it != interval_to_clusters.end()) {
          it->second.push_back(cluster);
        }
        else {
          interval_to_clusters.emplace(target_interval, std::vector<TetrisCluster>{cluster});
        }
      }

      for (auto pair : interval_to_clusters) {
        auto* target_interval = pair.first;
        this->deleteTargetIntervalClusters(target_interval, pair.second);

        // interval to reset remain length.
        this->reCalIntervalRemainLength(target_interval);

        // debug
        // if (target_interval->get_name() == "30_1") {
        //   LOG_INFO << "***Rollback (delete) ***";
        //   debugIntervalRemainLength(target_interval->get_name());
        // }
      }

      interval_to_clusters.clear();

      // sort the origin_clusters
      std::sort(rollback_info.origin_clusters.begin(), rollback_info.origin_clusters.end(),
        [](const TetrisCluster& a, const TetrisCluster& b) { return a.get_min_x() < b.get_min_x(); });

      for (auto& cluster : rollback_info.origin_clusters) {
        ipl::LGInterval* target_interval = cluster.get_belong_interval();
        auto it = interval_to_clusters.find(target_interval);
        if (it != interval_to_clusters.end()) {
          it->second.push_back(cluster);
        }
        else {
          interval_to_clusters.emplace(target_interval, std::vector<TetrisCluster>{cluster});
        }
      }

      for (auto pair : interval_to_clusters) {
        auto* target_interval = pair.first;
        this->insertTargetIntervalClusters(target_interval, pair.second);

        // interval to reset remain length.
        this->reCalIntervalRemainLength(target_interval);

        // debug
        // if (target_interval->get_name() == "30_1") {
        //   LOG_INFO << "***Rollback (insert) ***";
        //   debugIntervalRemainLength(target_interval->get_name());
        // }
      }

      _rollback_stack.pop();
    }
    return true;
  }

  void Tetris::deleteTargetIntervalClusters(ipl::LGInterval* interval, std::vector<TetrisCluster>& cluster_list)
  {
    int32_t interval_idx = interval->get_index();
    auto* interval_root = _interval_cluster_root[interval_idx];

    TetrisCluster* prev_cluster = nullptr;
    TetrisCluster* cur_cluster = interval_root;
    TetrisCluster* back_cluster = nullptr;

    while (cur_cluster) {
      std::string back_cluster_name = cur_cluster->get_back_cluster();
      back_cluster = this->findCluster(back_cluster_name);
      std::string prev_cluster_name = cur_cluster->get_front_cluster();
      prev_cluster = this->findCluster(prev_cluster_name);

      bool changed_flag = false;
      for (auto& target_cluster : cluster_list) {
        if (cur_cluster->get_name() == target_cluster.get_name()) {
          // change topo of cur_cluster
          if (!prev_cluster && !back_cluster) {
            _interval_cluster_root[interval_idx] = nullptr;
          }
          else if (prev_cluster && !back_cluster) {
            prev_cluster->set_back_cluster("");
          }
          else if (!prev_cluster && back_cluster) {
            _interval_cluster_root[interval_idx] = back_cluster;
            back_cluster->set_front_cluster("");
          }
          else {
            prev_cluster->set_back_cluster(back_cluster_name);
            back_cluster->set_front_cluster(prev_cluster_name);
          }
          changed_flag = true;
          this->deleteCluster(cur_cluster->get_name());
          break;
        }
      }

      if (changed_flag) {
        changed_flag = false;
        cur_cluster = back_cluster;
      }
      else {
        cur_cluster = back_cluster;
      }
    }
  }

  void Tetris::insertTargetIntervalClusters(ipl::LGInterval* interval, std::vector<TetrisCluster>& cluster_list)
  {
    std::vector<std::vector<TetrisCluster>> chain_list;
    // cluster_list -> chain_list, chain is ordered outside.
    int chain_idx = 0;
    chain_list.push_back(std::vector<TetrisCluster>{cluster_list[0]});
    for (size_t i = 0, j = i + 1; i < cluster_list.size(); i++, j++) {
      if (j >= cluster_list.size()) {
        //
        break;
      }
      std::string back_name = cluster_list[i].get_back_cluster();
      if (back_name == cluster_list[j].get_name()) {
        chain_list[chain_idx].push_back(cluster_list[j]);
      }
      else {
        chain_list.push_back(std::vector<TetrisCluster>{cluster_list[j]});
        chain_idx++;
      }
    }

    for (auto& chain : chain_list) {
      std::vector<TetrisCluster*> cluster_chain;
      for (auto& cluster : chain) {
        TetrisCluster* c = new TetrisCluster(cluster.get_name());
        // need to set coordi
        *c = cluster;

        // update inst coordi and change inst-cluster connection.
        int32_t coordi_y = c->get_belong_interval()->get_belong_row()->get_coordinate().get_y();
        int32_t coordi_x = c->get_min_x();
        for (auto* inst : c->get_inst_list()) {
          inst->updateCoordi(coordi_x, coordi_y);
          coordi_x += inst->get_shape().get_width();
          _inst_belong_cluster[inst->get_index()] = c;
        }
        cluster_chain.push_back(c);
      }
      insertClusterChainIntoInterval(interval, cluster_chain);
    }
  }

  void Tetris::insertClusterChainIntoInterval(ipl::LGInterval* interval, std::vector<TetrisCluster*>& cluster_chain)
  {
    int32_t interval_idx = interval->get_index();
    auto* interval_root = _interval_cluster_root[interval_idx];

    TetrisCluster* c_head = cluster_chain[0];
    TetrisCluster* c_tail = cluster_chain.back();

    auto* cur_cluster = interval_root;
    if (!cur_cluster) {
      for (auto* c : cluster_chain) {
        this->insertCluster(c->get_name(), c);
      }
      _interval_cluster_root[interval_idx] = c_head;
      return;
    }

    // front case
    if (c_head->get_min_x() < cur_cluster->get_min_x()) {
      for (auto* c : cluster_chain) {
        this->insertCluster(c->get_name(), c);
      }
      _interval_cluster_root[interval_idx] = c_head;
      cur_cluster->set_front_cluster(c_tail->get_name());
      return;
    }

    while (cur_cluster) {
      // not front case
      std::string back_cluster_name = cur_cluster->get_back_cluster();
      auto* back_cluster = this->findCluster(back_cluster_name);
      if (!back_cluster) {
        // direct add chain list.
        cur_cluster->set_back_cluster(c_head->get_name());
        for (auto* c : cluster_chain) {
          this->insertCluster(c->get_name(), c);
        }
        break;
      }
      else {
        if (c_head->get_min_x() >= cur_cluster->get_max_x() && c_head->get_max_x() <= back_cluster->get_min_x()) {
          // insert chain list.
          cur_cluster->set_back_cluster(c_head->get_name());
          back_cluster->set_front_cluster(c_tail->get_name());
          for (auto* c : cluster_chain) {
            this->insertCluster(c->get_name(), c);
          }
          break;
        }
        cur_cluster = back_cluster;
      }
    }
    return;
  }

  void Tetris::reCalIntervalRemainLength(ipl::LGInterval* interval)
  {
    int32_t interval_idx = interval->get_index();
    int32_t remain_length = (interval->get_max_x() - interval->get_min_x());

    TetrisCluster* interval_root = _interval_cluster_root[interval_idx];
    TetrisCluster* cur_cluster = interval_root;
    TetrisCluster* back_cluster = nullptr;
    while (cur_cluster) {
      std::string back_cluster_name = cur_cluster->get_back_cluster();
      back_cluster = this->findCluster(back_cluster_name);

      int32_t cluster_width = cur_cluster->get_total_width();
      remain_length -= cluster_width;
      cur_cluster = back_cluster;
    }
    _interval_remain_length[interval_idx] = remain_length;
  }

  void Tetris::debugIntervalRemainLength(std::string interval_name)
  {
    auto* interval = _database->get_lg_layout()->find_interval(interval_name);
    int32_t interval_idx = interval->get_index();
    int32_t remain_length = (interval->get_max_x() - interval->get_min_x());

    TetrisCluster* interval_root = _interval_cluster_root[interval_idx];
    TetrisCluster* cur_cluster = interval_root;
    TetrisCluster* back_cluster = nullptr;

    std::stringstream info;
    info << interval_name << " --- ";
    while (cur_cluster) {
      info << cur_cluster->get_name() << "(" << cur_cluster->get_inst_list().size() << "," << cur_cluster->get_total_width() << ")" << " -> ";

      std::string back_cluster_name = cur_cluster->get_back_cluster();
      back_cluster = this->findCluster(back_cluster_name);
      int32_t cluster_width = cur_cluster->get_total_width();
      remain_length -= cluster_width;
      cur_cluster = back_cluster;
    }

    info << std::endl;
    info << "Expect remain_length: " << remain_length << " ; " << "Actual remain_length: " << _interval_remain_length[interval_idx]
      << std::endl;
    LOG_INFO << info.str();
  }

  std::string Tetris::obtainUniqueClusterName(std::string origin_name)
  {
    std::string unique_name = origin_name;
    auto* cluster = this->findCluster(unique_name);
    while (cluster) {
      unique_name += "_2024";
      cluster = this->findCluster(unique_name);
    }
    return unique_name;
  }

}  // namespace ieda_solver
