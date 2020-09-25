#ifndef INCLUDE_MODIFYTOPSORT
#define INCLUDE_MODIFYTOPSORT
#include<iostream>
#define UNVISITED 0
#define VISITED 1
#define AFFINITY 999999
#include"AdjGraph.h"
#include"Graph.h"
#include"Edge.h"
template<class EdgeType>
bool ModifyTopSort(Graph<EdgeType>& G, int* VE, int* SortArray)
{//对图G利用拓扑排序,获得各个顶点事件的最早发生时间,
	//拓扑序列存放在数组SortArray中，事件的最早发生时间记录在VE中
	int n = G.VerticesNum(); 		//记录图中的顶点个数
	int* indegree = new int[n];		//创建一个数组记录各个顶点的入度值
	int v;
	Edge<EdgeType> e;
	for (v = 0; v<n; v++)
	{//各个顶点的入度初始化0,访问状态标记为未访问,事件的最早发生时间初始化为0
		indegree[v] = 0; 
		G.Mark[v] = UNVISITED;
		VE[v] = 0;
	}
	for (v = 0; v<n; v++)
	{ //统计各个顶点的入边信息
		for (e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))
		{
			indegree[e.end]++;
		}
	}
	for (int i = 0; i<n; i++)
	{//依次确定拓扑序列SortArray中的第i个元素
		//找到入度为0且未被访问的顶点
		for (v = 0; v<n; v++)
		{
			if (indegree[v] == 0 && G.Mark[v] == UNVISITED)
			{
				break; //退出for(v)循环
			}
		}
		//找不到入度为0的顶点,退出拓扑排序
		if (v == n) { return false; }
		//将顶点v放到排序序列中,并将其状态设置为VISITED
		G.Mark[v] = VISITED;
		SortArray[i] = v;
		for (e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))
		{//修改v指向的顶点的入度
			indegree[e.end]--;
			//修改v的后继事件的最早发生时间 max{ve[i]+dut[i,j]}
			if (VE[e.end]<VE[v] + e.weight)
				VE[e.end] = VE[v] + e.weight;
		}
	}
	delete[]indegree;
	return true;
}
#endif