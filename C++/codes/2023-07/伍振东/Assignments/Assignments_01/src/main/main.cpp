#include<iostream>
#include<map>
#include<vector>
#include "Graph.h"

/*  思路
    1、先找到拓扑排序的拓扑队列
    2、从高层到低层可能有路径，从低层到高层没有路径
    3、维护一个含有N个元素的路径队列，按照权重排序找到TopN
*/

// 找到从起始点到终点的拓扑排序
std::vector<std::vector<int>> topSort(Graph m_graph) {
    // 使用vector存储拓扑排序的顺序
    std::vector<std::vector<int>> top_queue;
    // 备份一份，不修改原始数据的值
    Graph graph(m_graph);

    // 只要拓扑排序没有结束，不断的将前驱结点为0的加入到队列中
    while (!graph.isEnd()) {
        std::vector<int> temp_queue;
        for (int i = 0; i < graph._edges; ++i) {
            if (graph._pre_edges[i] == 0) {
                temp_queue.emplace_back(i);
                graph._pre_edges[i] = -1;
            }
        }

        for (int i = 0; i < temp_queue.size(); ++i) {
            // 将队列中的边的出边都进行减一，并更新矩阵
            for (int j = 0; j < graph._edges; ++j) {
                if (graph._matrix[temp_queue[i]][j] != 0) {
                    graph._matrix[temp_queue[i]][j] = 0;
                    graph._pre_edges[j] -= 1;
                }
            }
        }

        top_queue.emplace_back(temp_queue);
    }
    return top_queue;
}

// 对当前给出的经过的结点按照所得到的拓扑顺序排列
bool nodeSort(std::vector<std::vector<int>>top_queue, std::vector<int>& mid_node){
    int len = top_queue.size();
    int count = mid_node.size() - 2;
    std::vector<int> node_sort;
    node_sort.emplace_back(mid_node[0]);

    // 通过判断top_queue找出正确的拓扑顺序
    for(int i = 0; i < len; ++i){
        for(int j = 0; j < top_queue[i].size(); ++j){
            // 提前跳出第二层循环的条件
            int flag = 0;
            for(int k = 1; k < mid_node.size()-1; ++k){
                if(top_queue[i][j] == mid_node[k]){
                    node_sort.emplace_back(mid_node[k]);
                    mid_node.erase(mid_node.begin()+k);
                    count -= 1;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1)break;
        }
    }

    node_sort.emplace_back(mid_node[mid_node.size()-1]);
    // 所给出的序列无法完成拓扑排序
    if(count>0)return false;
    mid_node = node_sort;
    return true;
}

// 寻找两个结点之间的全部路径，用深度优先
void Graph::findTwoPoint(int point1, int point2, mpath path, std::vector<mpath>& res){
    if(point1 == point2){
        path.m_queue.emplace_back(point2);

        // 按照权重的大小进行push
        if(res.empty()){
            res.emplace_back(path);
        }
        else{
            int i = 0;
            while(path.weight < res[i].weight){
                ++i;
            }
            res.insert(res.begin() + i, path);
        }
        return;
    }
    // std::cout<<point1<<":"<<point2<<" "<<'\n';

    path.m_queue.emplace_back(point1);
    for(int i = 0; i < _edges; ++i){
        // 退出循环
        if(_matrix[point1][i] != 0){
            path.weight += _matrix[point1][i];
            findTwoPoint(i, point2, path, res);
            path.weight -= _matrix[point1][i];
        }
    }
    path.m_queue.emplace_back(point1);
}

// 通过得到的顺序，找出所有的路径对权值进行排序
void allPath(std::vector<int> nodes, Graph m_graph, int n, int first, int second){
    // 对得到的排序构建hashmap，以确保访问的过程中都完成一次遍历
    mpath path;
    std::vector<mpath> res;

    // 找出起始点到终点的所有路径，然后排除掉没有通过的路径
    m_graph.findTwoPoint(first,second,path,res);
    
    // 将得到的结点哈希化
    std::map<int, bool> m_map;
    for(int i = 0; i < nodes.size(); ++i){
        m_map[nodes[i]] = 1;
    }
    // for(int i = 0; i < res.size(); ++i){
    //     for(int j = 0; j < res[i].m_queue.size(); ++j){
    //         std::cout<<res[i].m_queue[j]<<"->";
    //     }
    //     std::cout<<"weight:"<<res[i].weight<<'\n';
    // } 
    // 得到topN，把问题想复杂了，我擦
    std::vector<mpath> ans;
    for(int i = 0; i < res.size(); ++i){
        // 检查路径中是否包含nodes结点
        int count = 0;
        for(int j = 0; j < res[i].m_queue.size(); ++j){
            if(m_map.find(res[i].m_queue[j]) != m_map.end()){
                count++;
            }
        }
        if(count == nodes.size() && ans.size() < n){
            ans.emplace_back(res[i]);
        }
    }
    for(int i = 0; i < ans.size(); ++i){
        for(int j = 0; j < ans[i].m_queue.size()-1; ++j){
            std::cout<<ans[i].m_queue[j]<<"->";
        }
        std::cout<<ans[i].m_queue[ans[i].m_queue.size()-1]<<"  ";
        std::cout<<"weight:"<<ans[i].weight<<'\n';
    } 
}

void showVector(std::vector<int> mid_node){
    for(auto i : mid_node){
        std::cout<<i<<' ';
    }   
}

int main() {

    int matrix_[6][6] = { {0,5,5,4,0,0}, {0,0,0,1,0,0}, {0,0,0,0,7,0},
                        {0,0,0,0,2,8}, {0,0,0,0,0,1}, {0,0,0,0,0,0} };
    int** matrix = new int* [6];
    for (int i = 0; i < 6; ++i) {
        matrix[i] = matrix_[i];
    }
    Graph m_graph(matrix, 6, 6);
    // 得到拓扑排序
    std::vector<std::vector<int>>top_queue = topSort(m_graph);

    std::vector<int> mid = {0, 1, 5};
    int n = 3;

    bool b = nodeSort(top_queue, mid);

    allPath(mid, m_graph, n, mid[0], mid[mid.size() - 1]);

    std::cout<<"Sdadsadad!!!";
    system("PAUSE");
    return 0;
}