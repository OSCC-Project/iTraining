/**
 * @file dag.h
 * @author wangrui
 * @brief
 * @version 0.2
 * @date 2023-07-24
 *
 * @copyright Copyright (c) 2023
 *
 */
#ifndef MYDAG_H_
#define MYDAG_H_

/**
 * @brief An edge has start, end vertex information and the weight of it.
 *
 * @param start the start of the edge.
 * @param end the end of the edge.
 * @param weight  the weight of the edges.
 */
class Edge {
public:
  /**
   * @brief Create a edge with default values;
   *
   */
  Edge() : _start(0), _end(0), _weight(0) {}

  /**
   * @brief Create a edge with given values;
   *
   * @param start the start of the edge.
   * @param end the end of the edge.
   * @param weight the weight of the edges.
   */
  Edge(int start, int end, int weight)
      : _start(start), _end(end), _weight(weight){};

  ~Edge() {}

  /**
   *  @brief Get the start of the edge.
   *
   *  @return the start of the edge.
   */
  int get_start() { return _start; }

  /**
   * @brief Get the Edge end object
   *
   * @return the end of the edge.
   */
  int get_end() { return _end; }

  /**
   * @brief Get the Edge weight object
   *
   * @return the weight of the edge.
   */
  int get_weight() { return _weight; }

  /**
   * @brief Show the edge.
   */
  void showEdge();

private:
  int _start;  ///< Start vertex information
  int _end;    ///< end vertex information
  int _weight; ///< the edge's weight
};
/**
 * @brief An path has the number of vertices and an array to save the vertices
 * along
 *
 * @param vector_num
 * @param path
 */

class Path {
public:
  /// Create a path with default values.
  Path() : _vertices_num(0), _path(nullptr){};
  /// Create a path with given values.
  Path(int vertices_num, int *path);
  /// Copy function
  Path(const Path &path);
  /// Destructor function
  ~Path();
  /// Create a path with inputing values.
  void set_path();
  /// Add the vertex to the path.
  void addPathVertex(int vertex);
  /// Pop the vertex from the path.
  void popPathVertex();
  /// Get the number of the vertices along the path.
  /// @return the number of the vertices along the path.
  int get_vertices_num() { return _vertices_num; }
  /// Get the vertices along the path.
  /// @return the vertices along the path.
  int *get_path() { return _path; }
  /// Show the path.
  void showPath() const;
  /// Extend the array output form
  const int &operator[](const int i) const { return _path[i]; };
  /// Overload the equal operator to prevent shallow copying
  Path &operator=(const Path &path);

private:
  int _vertices_num; ///< Save the number of the vertices
  int *_path;        ///< an array to save the vertices along the path.
};
/**
 * @brief This is a class for AnsPath. An anspath has an array to save the
 * path's value, 2d array to save succesful, paths' message and the number of
 * these paths.
 *
 * @param valve
 * @param anspath
 * @param cnt
 */
class AnsPath {
public:
  /// Create a path with default values.
  AnsPath() : _value(nullptr), _anspath(nullptr), _cnt(0) {}
  /// Copy function
  AnsPath(const AnsPath &anspath);
  /// Destructor function
  ~AnsPath();
  /// Add the successful path to 2d array.
  void addAnsPathPath(Path &anspath, int valve);
  /// Get the number of the answer paths.
  ///@return the number of the answer paths.
  int get_anspath() const { return _cnt; }
  /// Sort by values in descending order.
  void dessortAnspath();
  /// Sort by values in ascending order.
  void ascsortAnspath();
  /// Show the answer paths.
  const void showAnsPath(const int topN) const;
  /// Overload the equal operator to prevent shallow copying
  AnsPath &operator=(const AnsPath &anspath);

private:
  int *_value;     ///< an array to save the path's value
  Path **_anspath; ///< 2d array to save succesful paths' message
  int _cnt;        ///< recard the number of successful paths;
};
/**
 * @brief This is a class for Visit.
 *
 * @param visit Indicate whether the vertex has visited.
 */
class Visit {
public:
  /// Create a visit array with inputing values.
  Visit();
  /// Create a visit array with given values.
  Visit(const int vertices_num);
  /// Copy function
  Visit(const Visit &visit);
  /// Destructor function
  ~Visit();
  /// the sign that the vertex doesn't been visited.
  void setUnvisited(const int index);
  /// the sign that the vertex has been visited.
  void setVisited(const int index);
  /// Get the vertex whether it is visited.
  ///@return true or false.
  bool isVisited(const int index);
  /// Overload the equal operator to prevent shallow copying
  Visit &operator=(const Visit &visit);

private:
  int *_visit; ///< an array to indicate whether the vertex has visited.
};
/**
 * @brief This is a class for Map. Store the message of the edges and the number
 * of edges.
 *
 * @param edges num
 * @param map
 */
class Map {
public:
  /// Create a map with inputing values.
  Map();
  /// Create a map with inputing values.
  Map(int edges_num) : _edges_num(edges_num){};
  /// Create a map with giving values.
  Map(int edges_num, const int map[][3]);
  /// Copy function
  Map(const Map &map);
  /// Destructor function
  ~Map();
  /// Initialize a map.
  void initialMap();
  /// Add edge to the map.
  void addMapEdge();
  /// Show the map.
  void printMap();
  /// Get the number of the edges.
  ///@return the number of the edges.
  int get_edges_num() { return _edges_num; };
  /// DFS algorithm
  void DFS(Edge &edge, int vertices_num, AnsPath &ans, Path &temp,
           Path &MidPath);
  /// Overload the equal operator to prevent shallow copying
  Map &operator=(const Map &map);

private:
  int _edges_num; ///< Store the number of the edges in the map.
  Edge **_map;    ///< A 2d array to indicate whether the vertex has visited.
};

#endif