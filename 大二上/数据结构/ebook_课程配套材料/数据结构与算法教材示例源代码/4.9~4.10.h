#ifndef INCLUDE_KRUSKAL
#define INCLUDE_KRUSKAL
#include<iostream>
#include <assert.h>
#include"MinHeap.h"
#include"Edge.h"
#include"AdjGraph.h"
#include"Graph.h"
class UFsets{
private:
	int n;//等价类中 等价元的个数
	int *root;//root[i]表示元素i所在的等价类的代表元素编号
	int *next;//next[i]表示在等价类中,i的后面元素编号
	int *length;//length[i]表示i所代表的 等价类的元素个数
public:
	UFsets(int size){
		n = size;//初始size个元素的等价类
		root = new int[n];
		next = new int[n];
		length = new int[n];
		for (int i = 0; i < n; i++){
			root[i] = next[i] = i;//各个元素独自成一个等价类
			length[i] = 1;
		}
	}
	int Find(int v){
		if (v < n){
			return root[v];
		}//返回等价类中的代表元素编号
		else
		{//边界检查
			cout << "参数不合法" << endl;
		}
	}
	void Union(int v, int u);//合并v和u所在的等价类，将元素少的合并到元素多的里面去
};
void UFsets::Union(int v, int u){
	if (root[u] == root[v]){
		//如果两个在同一个等价类中，就返回
		return;
	}
	else if (length[root[v]] <= length[root[u]]){
		//如果u的长度比v的长度长，那么就把v合到u里面去
		int rt = root[v];//记录v所在的等价类的代表元素
		length[root[u]] = length[root[u]] + length[root[v]];//修改u所在的等价类的元素的个数
		root[rt] = root[u];//下面来修改v所在的等价类里面的元素的代表元素
		for (int j = next[rt]; j != rt; j = next[j]){
			root[j] = root[u];
		}
		//下面交换两个代表元素 rt,root[u] 的next值
		int temp;
		temp = next[rt];
		next[rt] = next[root[u]];
		next[root[u]] = temp;
	}
	else if (length[root[v]] > length[root[u]]){
		//相反的一样
		int rt = root[u];
		length[root[v]] = length[root[v]] + length[root[u]];
		root[rt] = root[v];
		for (int k = next[rt]; k != rt; k = next[k]){
			root[k] = root[v];
		}
		int temp;
		temp = next[rt];
		next[rt] = next[root[v]];
		next[root[v]] = temp;
	}
}
template<class EdgeType>
Edge<EdgeType>* Kruskal(Graph<EdgeType> &G){//最小生成树的Kruskal算法
	//求含有n个顶点、e条边的连通图G的最小生成树 返回边的集合
	int n = G.VerticesNum();//记录顶点数目
	UFsets sets(n);//定义n个结点的等价类
	Edge<EdgeType> *MST = new Edge<EdgeType>[n - 1];//要返回的最小生成树的边
	MinHeap<Edge<EdgeType>> MinH(G.EdgesNum());//定义含有e个元素的最小堆，用于寻找权值最小的边
	Edge<EdgeType> edge;
	for (int i = 0; i < n; i++){
		for (edge = G.FirstEdge(i); G.IsEdge(edge); edge = G.NextEdge(edge)){
			if (G.StartVertex(edge) < G.EndVertex(edge)){
				//限制起始点的编号大小顺序，防止无向图中的边被重复加入
				MinH.insertNode(edge);
			}
		}
	}
	int edgeNum = 0;//生成边的个数
	while (edgeNum < n - 1){//n个结点的连通图的生成树有n-1条边
		if (!MinH.isEmpty()){
			//如果堆不空
			edge = MinH.removemin();//找到权重最小的未处理的边  
			int v = edge.start;
			int u = edge.end;
			if (sets.Find(v) != sets.Find(u)){
				//判断该边关联的顶点是否在一个连通分量
				sets.Union(v, u);//合并两个顶点所在的等价类
				MST[edgeNum] = edge;//将符合条件的边添加到生成树的边集合中
				edgeNum++;
			}
		}
		else
		{
			assert("不存在最小生成树.");
			return nullptr;
		}

	}
	return MST;
}

#endif