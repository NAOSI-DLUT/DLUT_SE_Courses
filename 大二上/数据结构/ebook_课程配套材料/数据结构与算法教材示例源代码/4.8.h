#ifndef INCLUDE_PRIM
#define INCLUDE_PRIM
#define UNVISITED 0
#define VISITED 1
#define AFFINITY 999999
#include<iostream>
#include"Edge.h"
#include"Graph.h"
#include"AdjGraph.h"
using namespace std;
template <class EdgeType>
Edge<EdgeType>* Prim(Graph<EdgeType>& G, int s)
{	//应用Prim算法从s顶点出发得到的最小生成树
	int i, j;
	Edge<EdgeType> *MST; 	//存储最小生成树的边
	//各个顶点到生成树中的各个顶点的最短的边
	EdgeType *nearest;  	//nearest[i]表示生成树中点到i点的最小边权值
	int *neighbor;      		//neighbor[i]表示生成树中与i点最近的点编号， 
	//-1表示i点已经在生成树集合中
	int n = G.VerticesNum();//图的顶点个数

	nearest = new EdgeType[n];
	neighbor = new int[n];
	MST = new Edge<EdgeType>[n - 1];
	for (i = 0; i<n; i++)    		//初始化neighor数组和nearest数组
	{
		neighbor[i] = s;
		nearest[i] = AFFINITY;
	}
	//与s相邻接的顶点的边权值 作为这些点 距离生成树集合的最短边长 
	for (Edge<EdgeType> e = G.FirstEdge(s); G.IsEdge(e); e = G.NextEdge(e))
	{
		nearest[e.end] = e.weight;
	}

	neighbor[s] = -1;//将已加入到生成树的点的最近邻设置为-1
	for (i = 1; i < n; i++)
	{ //i标记已经加入到生成树中的点个数                               
		EdgeType min = AFFINITY;//记录最小权值
		int v = -1;//记录下一个将要加入到集合中的点
		for (j = 0; j<n; j++)
		{//确定一个顶点在生成树集合，一个顶点不在生成树集合且权值最小的
			//边所关联的顶点
			if (nearest[j]<min && neighbor[j]>-1)
			{
				min = nearest[j];
				v = j;
			}
		}//for(j)
		if (v >= 0)
		{//将v加入到生成树集合中,更新到生成树外的各个点最小权值的边信息
			Edge<EdgeType> tempEdge(neighbor[v], v, nearest[v]);
			MST[i-1] = tempEdge;//将边加入到生成树集合中 
			neighbor[v] = -1;
			for (Edge<EdgeType> e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e))
			{
				int u = e.end;
				if (neighbor[u] != -1 && nearest[u]>e.weight)
				{//用与v关联的边更新生成树之外顶点到生成树集合的最小权值边
					neighbor[u] = v;
					nearest[u] = e.weight;
				}
			}//for(e)
		}//if(v>=0)
	}//for(i)
	delete[] neighbor; //释放空间
	delete[] nearest;
	return MST;
}
#endif