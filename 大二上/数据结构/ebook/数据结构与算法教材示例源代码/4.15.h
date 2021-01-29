#ifndef INCLUDE_CRITICALPATH
#define INCLUDE_CRITICALPATH
#include<iostream>
#define UNVISITED 0
#define VISITED 1
#define AFFINITY 999999
#include"AdjGraph.h"
#include"Graph.h"
#include"Edge.h"
#include"ModifyTopSort.h"
template<class EdgeType>
bool CriticalPath(Graph<EdgeType>& G, int* VE, int* VL, int* TopOrder)
{	//计算图G中关键活动并返回真，如果不是AOE网，则返回false
	//VE记录各个顶点事件的最早发生时间
	//VL记录各个顶点事件的最迟发生时间
	//TopOrder记录拓扑序列
	int n = G.VerticesNum(); //记录图中的顶点个数
	int v;
	if (!ModifyTopSort(G, VE, TopOrder))
	{//获得图的拓扑排序及各个顶点事件的最早发生时间
		return false;  //存在环,不能计算关键活动
	}
	//各个顶点事件的最迟发生时间都初始成终点事件的最早发生时间
	for (int i = 0; i<n; i++)
		VL[i] = VE[TopOrder[n - 1]];

	//按照逆拓扑排序的顺序,修改start代表的点的VL,每次找到以start为始点的边,计算vl=min{vl-dut}
	for (int i = n - 1; i >= 0; i--){
		int start = TopOrder[i];//每次修改的顶点(也是边的起始点)
		for (Edge<EdgeType> e = G.FirstEdge(start); G.IsEdge(e); e = G.NextEdge(e)){
			int end = e.end;
			EdgeType dut = e.weight;
			if (VL[start]>VL[end] - dut){
				VL[start] = VL[end] - dut;//按照公式修改VL
			}
		}
	}

	EdgeType sum = 0;//保存完成所有事件需要的最快时间
	for (v = 0; v<n; v++)
	{//确定关键活动
		for (Edge<EdgeType> e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))
		{//按照遍历每个顶点的边,寻找满足关键活动的边
			int u = e.end;
			EdgeType dut = e.weight;
			//确定关键活动并输出,关键活动的e=l,并且e=ve,l=vl-dut,因此关键活动所关联的事件的ve=vl-dut
			if (VE[v] == VL[u] - dut){
				cout << '(' << v + 1 << ',' << u + 1 << ')' << VE[v] << ' ' << dut << endl;
				sum = sum + dut;//累计时间
			}
		}
	}
	cout << "总时间为：" << sum << endl;
	return true;
}
#endif