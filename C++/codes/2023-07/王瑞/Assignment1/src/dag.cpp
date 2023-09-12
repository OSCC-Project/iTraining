/**
 * @file dag.cpp
 * @author wangrui
 * @brief
 * @version 0.2
 * @date 2023-07-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "dag.h"
#include <iostream>

void Edge::showEdge() {
  std::cout << "start: " << this->_start << " end: " << this->_end
            << " weight: " << this->_weight << std::endl;
}

Path::Path(int vertices_num, int *path) {
  this->_vertices_num = vertices_num;
  this->_path = new int[this->_vertices_num];
  for (int i = 0; i < vertices_num; ++i) {
    this->_path[i] = path[i];
  }
}

Path::Path(const Path &path) {
  this->_vertices_num = path._vertices_num;
  this->_path = new int[this->_vertices_num];
  for (int i = 0; i < this->_vertices_num; ++i) {
    this->_path[i] = path._path[i];
  }
}

Path::~Path() {
  if (this->_path != nullptr) {
    delete[] this->_path;
    this->_path = nullptr;
  }
}

void Path::set_path() {
  int vertices_num = 0;
  std::cout << "Please enter the number of vertices on the path:";
  std::cin >> vertices_num;
  if (vertices_num > 0) {
    this->_vertices_num = vertices_num;
    int *newpath = new int[vertices_num];
    for (int i = 0; i < vertices_num; ++i) {
      std::cout << "Please enter # " << i + 1 << " : ";
      std::cin >> newpath[i];
    }
    delete[] this->_path;
    this->_path = newpath;
  } else {
    std::cout << "enter error." << std::endl;
  }
}

void Path::addPathVertex(int vertex) {

  int *newpath = new int[this->_vertices_num + 1];
  int i;
  for (i = 0; i < _vertices_num; ++i) {
    newpath[i] = this->_path[i];
  }
  newpath[i] = vertex;
  ++this->_vertices_num;
  delete[] this->_path;
  this->_path = newpath;
}

void Path::popPathVertex() {
  --this->_vertices_num;
  int *newpath = new int[this->_vertices_num];
  for (int i = 0; i < this->_vertices_num; ++i) {
    newpath[i] = this->_path[i];
  }
  delete[] this->_path;
  this->_path = newpath;
}

void Path::showPath() const {
  for (int i = 0; i < this->_vertices_num; ++i) {
    std::cout << this->_path[i] << " ";
  }
}

Path &Path::operator=(const Path &path) {
  if (this == &path) {
    return *this;
  }
  if (this->_path != nullptr) {
    delete[] this->_path;
    this->_path = nullptr;
    this->_vertices_num = 0;
  }
  this->_vertices_num = path._vertices_num;
  this->_path = new int[this->_vertices_num];
  for (int i = 0; i < this->_vertices_num; ++i) {
    this->_path[i] = path._path[i];
  }
  return *this;
}

AnsPath::AnsPath(const AnsPath &anspath) {
  this->_cnt = anspath._cnt;
  this->_value = new int[this->_cnt];
  this->_anspath = new Path *[this->_cnt];
  for (int i = 0; i < this->_cnt; ++i) {
    this->_value[i] = anspath._value[i];
    this->_anspath[i] = anspath._anspath[i];
  }
}

AnsPath::~AnsPath() {
  if (this->_cnt != 0) {
    delete[] this->_value;
    delete[] this->_anspath;
    this->_value = nullptr;
    this->_anspath = nullptr;
    this->_cnt = 0;
  }
}

void AnsPath::addAnsPathPath(Path &anspath, int value) {
  ++this->_cnt;
  int *newvalue = new int[this->_cnt];
  Path **newanspath = new Path *[this->_cnt];
  for (int i = 0; i < _cnt - 1; ++i) {
    newanspath[i] = this->_anspath[i];
    newvalue[i] = this->_value[i];
  }
  Path *newpath = nullptr;
  newpath = new Path(anspath.get_vertices_num(), anspath.get_path());
  newanspath[_cnt - 1] = newpath;
  newvalue[_cnt - 1] = value;
  delete[] this->_value;
  delete[] this->_anspath;
  this->_value = newvalue;
  this->_anspath = newanspath;
}

void AnsPath::dessortAnspath() {
  if (_cnt > 1) {
    for (int i = 0; i < _cnt - 1; ++i) {
      int maxindex = i;
      int maxvalue = this->_value[maxindex];
      for (int j = i + 1; j < _cnt; ++j) {
        if (maxvalue < this->_value[j]) {
          maxvalue = this->_value[j];
          maxindex = j;
        }
      }
      Path *temp = nullptr;
      temp = new Path(_anspath[i]->get_vertices_num(), _anspath[i]->get_path());
      this->_anspath[i] = this->_anspath[maxindex];
      this->_anspath[maxindex] = temp;
      maxvalue = this->_value[i];
      this->_value[i] = this->_value[maxindex];
      this->_value[maxindex] = maxvalue;
    }
  }
}

void AnsPath::ascsortAnspath() {
  if (this->_cnt > 1) {
    for (int i = 0; i < _cnt - 1; ++i) {
      int minindex = i;
      int minvalue = this->_value[minindex];
      for (int j = i + 1; j < _cnt; ++j) {
        if (minvalue > this->_value[j]) {
          minvalue = this->_value[j];
          minindex = j;
        }
      }
      Path *temp = nullptr;
      temp = new Path(this->_anspath[i]->get_vertices_num(),
                      this->_anspath[i]->get_path());
      this->_anspath[i] = this->_anspath[minindex];
      this->_anspath[minindex] = temp;
      minvalue = this->_value[i];
      this->_value[i] = this->_value[minindex];
      this->_value[minindex] = minvalue;
    }
  }
}

void const AnsPath::showAnsPath(const int topN) const {
  int path_num = 0;
  if (topN > this->_cnt) {
    std::cout << "sorry! there are only " << this->_cnt << " path."
              << std::endl;
    path_num = this->_cnt;
  } else {
    std::cout << "the topN paths are as follow: " << std::endl;
    path_num = topN;
  }
  for (int i = 0; i < path_num; ++i) {
    std::cout << "the top" << i + 1 << " path : ";
    this->_anspath[i]->showPath();
    std::cout << " value : " << this->_value[i] << ". " << std::endl;
  }
}

AnsPath &AnsPath::operator=(const AnsPath &anspath) {
  if (this == &anspath) {
    return *this;
  }
  if (this->_anspath != nullptr) {
    delete[] this->_value;
    delete[] this->_anspath;
    this->_value = nullptr;
    this->_anspath = nullptr;
    this->_cnt = 0;
  }
  this->_cnt = anspath._cnt;
  this->_value = new int[this->_cnt];
  this->_anspath = new Path *[this->_cnt];
  for (int i = 0; i < this->_cnt; i++) {
    this->_value[i] = anspath._value[i];
    this->_anspath[i] = anspath._anspath[i];
  }
  return *this;
}

Visit::Visit() {
  int vertices_num = 0;
  std::cout << "Please enter the number of the vertices: " << std::endl;
  std::cin >> vertices_num;
  this->_visit = nullptr;
  this->_visit = new int[vertices_num];
  for (int i = 0; i < vertices_num; ++i) {
    this->_visit[i] = 0;
  }
}

Visit::Visit(const int vertices_num) {
  this->_visit = nullptr;
  this->_visit = new int[vertices_num];
  for (int i = 0; i < vertices_num; ++i) {
    this->_visit[i] = 0;
  }
}

Visit::Visit(const Visit &visit) {
  int visit_size = sizeof(visit._visit) / sizeof(visit._visit[0]);
  this->_visit = new int[visit_size];
  for (int i = 0; i < visit_size; ++i) {
    this->_visit[i] = visit._visit[i];
  }
}

Visit::~Visit() {
  if (_visit != nullptr) {
    delete[] this->_visit;
    this->_visit = nullptr;
  }
}

void Visit::setUnvisited(const int index) { this->_visit[index] = 0; }

void Visit::setVisited(const int index) { this->_visit[index] = 1; }

bool Visit::isVisited(const int index) {
  if (this->_visit[index] == 0) {
    return false;
  } else {
    return true;
  }
}

Visit &Visit::operator=(const Visit &visit) {
  if (this == &visit) {
    return *this;
  }
  if (this->_visit != nullptr) {
    delete[] this->_visit;
    this->_visit = nullptr;
  }
  std::cout << sizeof(visit._visit) << std::endl;
  int visit_size = sizeof(visit._visit) / sizeof(visit._visit[0]);
  this->_visit = new int[visit_size];
  for (int i = 0; i < visit_size; ++i) {
    this->_visit[i] = visit._visit[i];
  }
  return *this;
}

Map::Map() {
  this->_edges_num = 0;
  this->_map = nullptr;
}

Map::Map(int edges_num, const int map[][3]) {
  this->_edges_num = edges_num;
  this->_map = nullptr;
  Edge **newmap = new Edge *[_edges_num];
  for (int i = 0; i < edges_num; ++i) {
    Edge *newedge = nullptr;
    newedge = new Edge(map[i][0], map[i][1], map[i][2]);
    newmap[i] = newedge;
  }
  this->_map = newmap;
}

void Map::initialMap() {
  int edges_num = 0;
  std::cout << "please enter the number of the edges: " << std::endl;
  std::cin >> edges_num;
  if (edges_num > 0) {
    _edges_num = edges_num;
    Edge **newmap = new Edge *[_edges_num];
    for (int i = 0; i < this->_edges_num; ++i) {
      int start, end, weight;
      std::cout << "Please enter #" << i + 1 << " edge's start:";
      std::cin >> start;
      std::cout << "Please enter #" << i + 1 << " edge's end:";
      std::cin >> end;
      std::cout << "Please enter #" << i + 1 << " edge's weight:";
      std::cin >> weight;
      Edge *newedge = nullptr;
      newedge = new Edge(start, end, weight);
      newmap[i] = newedge;
    }
    delete[] this->_map;
    this->_map = newmap;
  } else {
    std::cout << "enter error." << std::endl;
  }
}

Map::Map(const Map &map) {
  this->_edges_num = map._edges_num;
  this->_map = new Edge *[this->_edges_num];
  for (int i = 0; i < this->_edges_num; ++i) {
    this->_map[i] = map._map[i];
  }
}

Map::~Map() {
  if (this->_map != nullptr) {
    delete[] this->_map;
    this->_map = nullptr;
    this->_edges_num = 0;
  }
}

void Map::addMapEdge() {
  int edges_num = 0;
  std::cout << "please enter the number of the edges: " << std::endl;
  std::cin >> edges_num;
  if (edges_num > 0) {

    Edge **newmap = new Edge *[_edges_num + edges_num];
    for (int i = 0; i < this->_edges_num; i++) {
      Edge *newedge = nullptr;
      newedge = new Edge(_map[i]->get_start(), _map[i]->get_end(),
                         _map[i]->get_weight());
      newmap[i] = newedge;
    }

    for (int i = 0; i < edges_num; i++) {
      int start, end, weight;
      std::cout << "Please add #" << i + 1 << " edge's start:";
      std::cin >> start;
      std::cout << "Please add #" << i + 1 << " edge's end:";
      std::cin >> end;
      std::cout << "Please add #" << i + 1 << " edge's weight:";
      std::cin >> weight;
      Edge *newedge = nullptr;
      newedge = new Edge(start, end, weight);
      newmap[this->_edges_num + i] = newedge;
    }
    this->_edges_num += edges_num;
    delete[] this->_map;
    this->_map = newmap;
  } else {
    std::cout << "enter error." << std::endl;
  }
}

void Map::printMap() {
  for (int i = 0; i < _edges_num; ++i) {
    this->_map[i]->showEdge();
  }
}

void Map::DFS(Edge &edge, int vertices_num, AnsPath &anspath, Path &temp,
              Path &MidPath) {
  temp.addPathVertex(edge.get_start());
  int flag = 1;
  if (edge.get_start() == edge.get_end()) {
    Visit visit(vertices_num);
    for (int i = 0; i < temp.get_vertices_num(); ++i) {
      visit.setVisited(temp[i]);
    }
    for (int i = 0; i < MidPath.get_vertices_num(); ++i) {
      if (visit.isVisited(MidPath[i]) == 0) {
        flag = 0;
      }
    }
    if (flag == 1) {
      anspath.addAnsPathPath(temp, edge.get_weight());
    }
  }
  for (int i = 0; i < _edges_num; ++i) {
    if (edge.get_start() == this->_map[i]->get_start()) {
      int next = this->_map[i]->get_end();
      Edge newedge(next, edge.get_end(),
                   edge.get_weight() + this->_map[i]->get_weight());
      DFS(newedge, vertices_num, anspath, temp, MidPath);
    }
  }
  temp.popPathVertex();
}

Map &Map::operator=(const Map &map) {
  if (this == &map) {
    return *this;
  }
  if (this->_map != nullptr) {
    this->_edges_num = 0;
    delete[] this->_map;
    this->_map = nullptr;
  }
  this->_edges_num = map._edges_num;
  for (int i = 0; i < this->_edges_num; ++i) {
    this->_map[i] = map._map[i];
  }
  return *this;
}