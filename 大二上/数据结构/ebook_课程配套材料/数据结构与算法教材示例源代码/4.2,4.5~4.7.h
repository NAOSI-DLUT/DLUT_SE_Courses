#pragma once
#include<iostream>
#include"Edge.h"
#define VISITED 1
#define UNVISITED 0
using namespace std;
template <class EdgeType>
class Graph//图类型
{
public:
	int vertexNum;//图的顶点数目
	int edgeNum;//图的边数目
	int * Mark;//标记某顶点是否被访问过,访问过为1，没访问为0
	Graph(int verticesNum)
	{
		vertexNum = verticesNum;
		edgeNum = 0;
		Mark = new int[verticesNum];
		for (int i = 0; i < verticesNum; i++)
		{
			Mark[i] = UNVISITED;
		}
	}
	~Graph()
	{
		delete[] Mark;
	}
	virtual Edge<EdgeType> FirstEdge(int onevertex) = 0;//返回与顶点相关联的第一条边
	virtual Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge) = 0;//返回与oneedge有相同起点的下一条边
	int VerticesNum()//返回图的顶点个数
	{
		return vertexNum;
	}
	int edgesnum()//返回边个数
	{
		return edgeNum;
	}
	bool Isedge(Edge<EdgeType> oneEdge)//判断是否为边
	{
		if (oneEdge.weight > 0 && oneEdge.weight < INFINITY&&oneEdge.end >= 0)
			return true;
		else
			return false;
	}
	int StartVertex(Edge<EdgeType> oneEdge)//返回边的始点
	{
		return oneEdge.start;
	}
	int EndVertex(Edge<EdgeType> oneEdge)//返回边的终点
	{
		return oneEdge.end;
	}
	EdgeType Weight(Edge<EdgeType> oneEdge)//返回边的权重
	{
		return oneEdge.weight;
	}
	virtual void setEdge(int start, int end, EdgeType weight) = 0;//设置边
	virtual void delEdge(int start, int end) = 0;//删除边
	void visit(int v)//访问结点
	{
		cout << v << ' ';
	}
	void DFS(int v)//从某顶点开始递归深度优先搜索
	{
		visit(v);
		Mark[v] = VISITED;
		for (Edge<EdgeType> e = FirstEdge(v); Isedge(e); e = NextEdge(e))
		{
			if (Mark[EndVertex(e)] == UNVISITED)
				DFS(EndVertex(e));
		}
	}
	void DFStraverse()//图的递归深度优先搜索
	{
		int i;
		for (i = 0; i < VerticesNum(); i++)
			Mark[i] = UNVISITED;
		for (i = 0; i < VerticesNum(); i++)
		{
			if (Mark[i] == UNVISITED)
				DFS(i);
		}
	}
	void DFSNoReverse()//非递归法深度优先遍历
	{
		int i, v, u;
		stack<int> s;
		for (i = 0; i < VerticesNum(); i++)
			Mark[i] = UNVISITED;
		for (i = 0; i < VerticesNum(); i++)
		{
			if (Mark[i] == UNVISITED)
			{
				s.push(i);
				visit(i);
				Mark[i] = VISITED;
				while (!s.empty())
				{
					v = s.top();
					Edge<EdgeType> e;
					for (e = FirstEdge(v); Isedge(e); e = NextEdge(e))
					{	
						u = EndVertex(e);
						if (Mark[u] == UNVISITED)
						{
							s.push(u);
							visit(u);
							Mark[u] = VISITED;
							break;
						}						
					}
					if (!Isedge(e))
						s.pop();
				}
			}
		}
	}
	void BFS(int v)//从某结点开始广度优先搜索
	{
		queue<int> Q;
		Mark[v] = VISITED;
		visit(v);
		Q.push(v);
		while (!Q.empty())
		{
			v = Q.front();
			Q.pop();
			for (Edge<EdgeType> e = FirstEdge(v); Isedge(e); e = NextEdge(e))
			{
				int u = Mark[EndVertex(e)];
				int m = EndVertex(e);
				if (u == UNVISITED)
				{
					visit(m);
					Mark[m] = VISITED;
					Q.push(m);
				}
			}
		}
	}
	void BFStraverse()//图的广度优先搜索
	{
		int v;
		for (v = 0; v < VerticesNum(); v++)
			Mark[v] = UNVISITED;
		for (v = 0; v < VerticesNum(); v++)
		{
			if (Mark[v] == UNVISITED)
				BFS(v);
		}
	}
};