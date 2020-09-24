#ifndef INCLUDE_STRACTGRAPH
#define INCLUDE_STRACTGRAPH
#include"Edge.h"
using namespace std;
//G=（V,E）代表一个图，V即是顶点的非空有限集合，E是边（或弧）的集合
template<class EdgeType>
class Graph
{
public:
	Graph(int verticesNum);		//构造函数
	~Graph();                 		//析构函数
	virtual Edge<EdgeType> FirstEdge(int oneVertex) = 0;
	//返回与顶点oneVertex相关联的第一条边
	virtual Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge) = 0;
	//返回与边oneEdge有相同起点的下一条边
	virtual void setEdge(int start, int end, EdgeType weight) = 0;
	//设置边（start,end）,权重为weight
	virtual void delEdge(int start, int end) = 0;
	//删除边（start,end）
	int getVertexNum();			//返回图的顶点个数
	int getEdgeNum();       		//返回图的边数
	bool isEdge(Edge<EdgeType> oneEdge);
	//如果oneEdge是边则返回TRUE，否则返回FALSE
	int StartVertex(Edge<EdgeType> oneEdge);//返回边oneEdge的始点
	int EndVertex(Edge<EdgeType> oneEdge);//返回边oneEdge的终点
	EdgeType Weight(Edge<EdgeType> oneEdge);	//返回边oneEdge的权
};
#endif