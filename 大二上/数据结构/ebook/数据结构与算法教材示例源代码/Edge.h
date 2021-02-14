#pragma once
template <class EdgeType>
class Edge//±ßÀàÐÍ
{
public:
	int start, end;
	EdgeType weight;
	Edge()
	{
		start = 0;
		end = 0;
	}
	Edge(int st, int en, EdgeType w)
	{
		start = st;
		end = en;
		weight = w;
	}
	bool operator > (Edge oneEdge)
	{
		return weight > oneEdge.weight;
	}
	bool operator < (Edge oneEdge)
	{
		return weight < oneEdge.weight;
	}
};