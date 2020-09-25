#ifndef INCLUDE_DIJKSTRA
#define INCLUDE_DIJKSTRA
#define UNVISITED 0
#define VISITED 1
#define AFFINITY 999999
#include<iostream>
#include<string>
#include<stack>
#include"AdjGraph.h"
#include"Edge.h"
#include"Graph.h"
template<class EdgeType>
void Dijkstra(Graph<EdgeType> &G, int s, EdgeType* D, int * Path){
	/*Dijkstra算法，其中参数s是源点，D是最短特殊路径长度，Path[i]为路径上i的前驱顶点编号*/
	int n = G.VerticesNum();//保存图的节点数目
	for (int i = 0; i < n; i++){
		//初始化
		G.Mark[i] = UNVISITED;//一个路径都没有，都没有被访问过
		D[i] = AFFINITY;//从s到每个点的最短特殊路径的长度初始化为最大值
		Path[i] = s;//所有点的前驱初始为源点s
	}
	D[s] = 0;//s到自身的最短长度为0
	for (int j = 0; j < n; j++){
		//每次循环就找到一个最短路径
		//找到一条最短特殊路径,即min{D[j]&&G.Mark[j]==UNVISITED, 0<=j<n}
		EdgeType min = AFFINITY;//min为最小权
		int k;
		for (int i = 0; i < n; i++){
			if (G.Mark[i] == UNVISITED&&D[i] < min){
				k = i;
				min = D[i];
			}
		}
		//已确定s到k的最短路径
		G.Mark[k] = VISITED;
		//下面修改D
		//利用k更新到其余未访问顶点的最短特殊路径
		for (Edge<EdgeType> e = G.FirstEdge(k); G.IsEdge(e); e = G.NextEdge(e)){
			int endVertex = e.end;
			if (G.Mark[endVertex] == UNVISITED&&D[endVertex] > (D[k] + e.weight)){
				//如果出现更小的路径,就更新
				D[endVertex] = D[k] + e.weight;//更新到endVertex的最短特殊路径
				Path[endVertex] = k;//更新前驱节点编号
			}
		}
	}
}

//方便输出结果的辅助函数
template<class EdgeType>
void PrintDj(AdjGraph<EdgeType> &G, int s, EdgeType* &D, int * &P){//格式化输出路径以及长度
	stack<int> sta;//采用栈保存路径节点
	int n = G.VerticesNum();
	for (int i = 0; i < n; i++){
		cout << "从" << G.Vertex[s] << "到" << G.Vertex[i] << "的最短路径为：";
		sta.push(i);//逆序查找节点 因此先压栈
		int j = i;
		while (P[j] != s){//如果不是源点s就继续查找
			sta.push(P[j]);
			j = P[j];
		}
		sta.push(s);
		while (!sta.empty()){//依次出栈得到路径
			int temp = sta.top();
			sta.pop();
			cout << G.Vertex[temp] << "  ";
		}
		cout << "长度为：" << D[i] << endl;
	}
}

#endif