#pragma once
template <class EdgeType>
class AdjGraph :public Graph<EdgeType>//图的邻接矩阵表示
{
private:
	int ** matrix;
public:
	AdjGraph(int ver) :Graph<EdgeType>::Graph(ver)
	{
		int i, j;
		matrix = (int **)new int *[ver];
		for (i = 0; i < ver; i++)
			matrix[i] = new int[ver];
		for (i = 0; i < ver; i++)
			for (j = 0; j < ver; j++)
				matrix[i][j] = 0;//存权重
	}
	~AdjGraph()
	{
		for (int i = 0; i < this->vertexNum; i++)
			delete[]matrix[i];
		delete[]matrix;
	}
	Edge<EdgeType> FirstEdge(int onevertex)//返回与顶点相关联的第一条边
	{
		Edge<EdgeType> tmpEdge;
		tmpEdge.start = onevertex;
		for (int i = 0; i < this->vertexNum; i++)
		{
			if (matrix[onevertex][i] != 0)
			{
				tmpEdge.end = i;
				tmpEdge.weight = matrix[onevertex][i];
				break;
			}
		}
		return tmpEdge;
	}
	Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)//返回与oneEdge有相同起点的下一条边
	{
		Edge<EdgeType> tmpEdge;
		tmpEdge.start = oneEdge.start;
		for (int i = oneEdge.end + 1; i < this->vertexNum; i++)
		{
			if (matrix[oneEdge.start][i] != 0)
			{
				tmpEdge.end = i;
				tmpEdge.weight = matrix[oneEdge.start][i];
				break;
			}
		}
		return tmpEdge;
	}
	void setEdge(int start, int end, EdgeType weight)//为图新增一条边
	{
		if (matrix[start][end] == 0)
			this->edgeNum++;
		matrix[start][end] = weight;
	}
	void delEdge(int start, int end)//删除一条边
	{
		if (matrix[start][end] != 0)
			this->edgeNum--;
		matrix[start][end] = 0;
	}
};