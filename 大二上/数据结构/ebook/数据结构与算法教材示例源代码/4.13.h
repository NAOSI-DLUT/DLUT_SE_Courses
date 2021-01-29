#ifndef INCLUDE_TOPOLOGYSORT
#define INCLUDE_TOPOLOGYSORT
#include<iostream>
#define UNVISITED 0
#define VISITED 1
#define AFFINITY 999999
#include"AdjGraph.h"
#include"Graph.h"
#include"Edge.h"
template<class EdgeType>
bool TopologySort(Graph<EdgeType> &G, int* SortArray){
	//对有向图进行拓扑排序，将排序的序列保存在SortArray中
	int n = G.VerticesNum();//记录图中的顶点个数
	int *indegree = new int[n];//创建一个数组记录各个顶点的入度值

	int v;
	Edge<EdgeType> e;
	for (v = 0; v<n; v++)
	{//各个顶点的入度初始化0,访问状态标记为未访问
		indegree[v] = 0; G.Mark[v] = UNVISITED;
	}
	for (v = 0; v<n; v++)
	{ //统计各个顶点的入边信息
		for (e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))
		{
			indegree[e.end]++;//修改各个顶点的入度值
		}
	}
	for (int i = 0; i < n; i++){
		//依次确定拓扑序列SortArray中的第i个元素
		for (v = 0; v < n; v++){
			if (indegree[v] == 0 && G.Mark[v] == UNVISITED){
				//找到 入度为0 并且没有被访问的顶点
				break;//退出for(v)循环
			}
		}
		if (v == n){
			//找不到入度为0的顶点,退出拓扑排序
			return false;//即为有环
		}
		//将顶点v放到排序序列中,并将其状态设置为VISITED
		G.Mark[v] = VISITED;
		SortArray[i] = v;
		//由顶点v为始点的边删去，依次修改所有边的终点的入度
		for (e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e)){
			indegree[e.end]--;
		}
	}
	delete[]indegree;
	return true;
}
#endif