/**@brief 这个文件包含了一些常用的头文件，包括iostream、vector、queue、unordered_map、cmath、utility、thread、chrono、algorithm等。
 * @author 赵正杰
*/



#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <utility>
#include <cassert>
#include <thread>   // for std::this_thread::sleep_for
#include <chrono>   // for std::chrono::milliseconds
#include <algorithm>

using Point = std::pair<int, int>;
using Priority_Point = std::pair<int, Point>;
using PriorityQueue = std::priority_queue<Priority_Point, std::vector<Priority_Point>, std::greater<Priority_Point>>;
