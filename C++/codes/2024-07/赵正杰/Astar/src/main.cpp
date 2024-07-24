/**
 * @file main.cpp
 * @brief 这是主函数文件
 * @author 赵正杰
 * @version 0.1
 * 
 * 这里简单实现了一个A*算法的路径搜索，并用可视化工具Visualization来展示搜索过程。
 */

#include "public_header.h"
#include "Graph.h"
#include "Visual.h"
#include "Astar.h"
int main() {
	Graph graph;//!这里为了方便起见我直接写了缺省值为4和8，但是实际上可以画任意大的图
	//graph.set_Weight();
	Visualization vis(&graph);
	

	Astar A;
	A.search_Path({ 0,0 }, {2,6},graph);
	A.get_Path({ 2,6 }, { 0,0 }, graph, &vis);
	vis.Put_Visual();
}