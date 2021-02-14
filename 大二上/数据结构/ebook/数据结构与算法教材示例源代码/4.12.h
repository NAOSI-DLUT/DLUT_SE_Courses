#ifndef INCLUDE_FLOYD
#define INCLUDE_FLOYD
#include<iostream>
#define UNVISITED 0
#define VISITED 1
#define AFFINITY 999999
#include<stack>
#include"AdjGraph.h"
#include"Graph.h"
#include"Edge.h"

template<class EdgeType>
void Floyd(Graph<EdgeType> &G, EdgeType **adjArray, int **Path){
	//带权 有向图，adjArray[i][j]为从i到j的最短路径长度，Path[i][j]为最短路径中顶点j的前驱顶点编号
	int i, j, v;
	int n = G.VerticesNum();
	for (i = 0; i < n; i++){
		for (j = 0; j < n; j++){
			if (i == j){
				adjArray[i][j] = 0;//到自身的最小路径为0
			}
			else{
				adjArray[i][j] = AFFINITY;//否则是无穷大
			}
			Path[i][j] = i;//前驱顶点 编号 是自身
		}
	}//初始化
	for (v = 0; v < n; v++){
		//检查各个边，将（v,end）的权值作为adjArray[v][end]
		for (Edge<EdgeType> e = G.FirstEdge(v); G.IsEdge(e); e = G.NextEdge(e)){
			adjArray[v][e.end] = e.weight;
		}
	}
	//如果两个顶点i,j之间的最短路径经过顶点v，且有adjArray[i][j]>(adjArray[i][v]+adjArray[v][j])，就更新adjArray[i][j]和Path[i][j]的值
	for (v = 0; v < n; v++){
		for (i = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (adjArray[i][j] >(adjArray[i][v] + adjArray[v][j])){
					adjArray[i][j] = adjArray[i][v] + adjArray[v][j];//更新最短路径
					Path[i][j] = v;
				}
			}
		}
	}
}

//方便输出结果的辅助函数
template<class EdgeType>
void PrintFloyd(AdjGraph<EdgeType> &G, EdgeType **&adjArray, int **&Path){
	int n = G.VerticesNum();
	stack<int> sta;//采用栈保存路径节点
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << G.Vertex[i] << "到" << G.Vertex[j] << "的最短路径长度为:" << adjArray[i][j] << "    路径为";
			sta.push(j);//逆序查找节点 因此先压栈
			int s = j;
			while (Path[i][s] != i){//如果不是源点i就继续查找
				sta.push(Path[i][s]);
				s = Path[i][s];
			}
			sta.push(i);
			while (!sta.empty()){//依次出栈得到路径
				int temp = sta.top();
				sta.pop();
				cout << G.Vertex[temp] << "  ";
			}
			cout << endl;
		}
	}
}
#endif