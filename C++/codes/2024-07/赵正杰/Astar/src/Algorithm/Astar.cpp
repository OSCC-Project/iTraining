#include "Astar.h"

void Astar::search_Path(const Point start, const Point end,Graph& graph) {
    PriorityQueue Node_Queue;
    Node_Queue.emplace(0, start);
    std::vector<std::pair<int, Point>> vc_cost_so_far;
    vc_cost_so_far.emplace_back(0, start);
    while (!Node_Queue.empty()) {
        auto current_node = Node_Queue.top().second;
        Node_Queue.pop();
        if (current_node == end) break;
        auto neighbors = Find_neighbors(current_node, graph);

        auto current_cost = std::find_if(vc_cost_so_far.begin(), vc_cost_so_far.end(),
            [current_node](const Priority_Point& Node) {
                return current_node == Node.second;
            })->first;
        for (auto next : neighbors) {
            auto new_cost = current_cost + graph.get_Weight(next.first, next.second);
            auto is_exit_next = std::find_if(vc_cost_so_far.begin(), vc_cost_so_far.end(),
                [next](const Priority_Point& Node) {
                    return next == Node.second;
                });
            if (is_exit_next == vc_cost_so_far.end() || new_cost < is_exit_next->first) {
                if (is_exit_next == vc_cost_so_far.end()) {
                    vc_cost_so_far.emplace_back(new_cost, next);
                } else {
                    is_exit_next->first = new_cost;
                }
                int priority = new_cost + heuristic(next, end);
                Node_Queue.emplace(priority, next);
                come_from.push_back({ next, current_node });
            }
        }
    }
}

void Astar::get_Path(const Point& end, const Point& start, Graph& graph, Visualization* vis) {
    assert(!come_from.empty());
    Point current_Node = end;
    graph._Adj_Graph[end.first][end.second] = 0;
    while (current_Node != start) {
        if (vis) {
            vis->Put_Visual();
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            system("clear");
        }

        auto history_Node = std::find_if(come_from.begin(), come_from.end(),
            [current_Node](std::pair<Point, Point> Node) {
                return Node.first == current_Node;
            });
        current_Node = history_Node->second;
        graph._Adj_Graph[current_Node.first][current_Node.second] = 0;
    }
}

std::vector<Astar::Point> Astar::Find_neighbors(const Point current,Graph& graph) {
    std::vector<Point> vc_neighbors;
    if (current.first != 0) {
        vc_neighbors.push_back({ current.first - 1, current.second });
    }
    if (current.first != graph.get_Width() - 1) {
        vc_neighbors.push_back({ current.first + 1, current.second });
    }
    if (current.second != 0) {
        vc_neighbors.push_back({ current.first, current.second - 1 });
    }
    if (current.second != graph.get_length() - 1) {
        vc_neighbors.push_back({ current.first, current.second + 1 });
    }
    return vc_neighbors;
}

int Astar::heuristic(Point a, Point b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}