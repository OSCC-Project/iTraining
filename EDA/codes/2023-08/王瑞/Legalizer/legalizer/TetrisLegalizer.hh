#ifndef IPL_TETRISLEGALIZER_H
#define IPL_TETRISLEGALIZER_H

#include "Config.hh"
#include "config/LegalizerConfig.hh"
#include "database/LGDatabase.hh"

namespace ipl {

#define TetrisLegalizerInst (ipl::TetrisLegalizer::getInst())

enum class LG_MODE
{
  kNone,
  kComplete,
  kIncremental
};

class TetrisLegalizer
{
 public:
  static TetrisLegalizer& getInst();
  static void destoryInst();
  void initTetrisLegalizer(Config* pl_config, PlacerDB* placer_db);

  void updateInstanceList();
  void updateInstanceList(std::vector<Instance*> inst_list);

  LG_MODE get_mode() const { return _mode; }
  bool runLegalize();
  bool runIncrLegalize();

  bool isInitialized() { return _mode != LG_MODE::kNone; }

 private:
  static TetrisLegalizer* _s_tetris_lg_instance;

  LGConfig _config;
  LGDatabase _database;
  int32_t _row_height;
  int32_t _site_width;

  LG_MODE _mode;
  std::vector<LGInstance*> _target_inst_list;

  TetrisLegalizer() = default;
  TetrisLegalizer(const TetrisLegalizer&) = delete;
  TetrisLegalizer(TetrisLegalizer&&) = delete;
  ~TetrisLegalizer();
  TetrisLegalizer& operator=(const TetrisLegalizer&) = delete;
  TetrisLegalizer& operator=(TetrisLegalizer&&) = delete;

  void initLGConfig(Config* pl_config);
  void initLGDatabase(PlacerDB* placer_db);
  void initLGLayout();
  void wrapRowList();
  void wrapRegionList();
  void wrapCellList();
  void initSegmentList();

  bool checkMapping();
  LGInstance* findLGInstance(Instance* pl_inst);
  bool checkInstChanged(Instance* pl_inst, LGInstance* lg_inst);
  void updateInstanceInfo(Instance* pl_inst, LGInstance* lg_inst);
  void updateInstanceMapping(Instance* pl_inst, LGInstance* lg_inst);

  bool runCompleteMode();
  bool runIncrementalMode();

  void pickAndSortMovableInstList(std::vector<LGInstance*>& movable_inst_list);
  int32_t placeRow(LGInstance* inst, int32_t row_idx, bool is_trial);
  int32_t searchNearestIntervalIndex(std::vector<LGInterval*>& segment_list, Rectangle<int32_t>& inst_shape);
  int32_t searchRemainSpaceSegIndex(std::vector<LGInterval*>& segment_list, Rectangle<int32_t>& inst_shape, int32_t origin_index);
  LGCluster arrangeInstIntoIntervalCluster(LGInstance* inst, LGInterval* interval);
  void replaceClusterInfo(LGCluster& cluster);
  void arrangeClusterMinXCoordi(LGCluster& cluster);
  void legalizeCluster(LGCluster& cluster);
  int32_t obtainFrontMaxX(LGCluster& cluster);
  int32_t obtainBackMinX(LGCluster& cluster);

  int32_t calDistanceWithBox(int32_t min_x, int32_t max_x, int32_t box_min_x, int32_t box_max_x);
  bool checkOverlapWithBox(int32_t min_x, int32_t max_x, int32_t box_min_x, int32_t box_max_x);

  void alignInstanceOrient(std::vector<LGInstance*> inst_list);
  void writebackPlacerDB(std::vector<LGInstance*> inst_list);
  int32_t calTotalMovement();
};

}  // namespace ipl

#endif