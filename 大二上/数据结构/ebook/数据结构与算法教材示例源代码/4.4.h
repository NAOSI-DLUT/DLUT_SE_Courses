#pragma once
template<class EdgeType>
class listData           				//邻接表边结点的数据部分定义
{
public:
	int vertex;             			//边的终点
	EdgeType weight;      			//边的权
};
template<class Elem>         		//定义边结点
class ListNode {
public:
	Elem element;             		//边结点的数据
	ListNode<Elem> *next;     		//边结点指针，指向下一个边结点
	ListNode(const Elem& elemval, ListNode<Elem> *nextval = NULL) { element = elemval; next = nextval; }
	ListNode(ListNode<Elem> *nextval = NULL) { next = nextval; }
};
template<class Elem>
class EdgeList {          			//每个顶点所关联的边表
public:
	ListNode<Elem>* head;   		//head指针
	EdgeList() {              			//构造函数
		head = new ListNode<Elem>();
	}
	void removeall()      			//释放边表所有边结点占据的空间
	{
		ListNode<Elem> *tmp;
		while (head != NULL)    		//逐步释放每个边结点占据的空间
		{
			tmp = head;
			head = head->next;
			delete tmp;
		}
	}

	~EdgeList() { removeall(); }	//析构函数
};
template <class EdgeType>
class ListGraph : public Graph<EdgeType>	//图的邻接表表示
{
private:
	EdgeList<listData<EdgeType>> *graList;
	//graList是保存所有边表的数组
public:
	ListGraph(int verticesNum) :Graph<EdgeType>::Graph(verticesNum) //构造函数
	{//申请空间，有vertexNum个顶点则有vertexNum个边表
		graList = new EdgeList<listData<EdgeType>>[this->vertexNum];
	}
	~ListGraph()           			//析构函数
	{
		delete[] graList;
	}
	Edge<EdgeType> FirstEdge(int oneVertex) 	//返回顶点oneVertex的第一条边
	{
		Edge<EdgeType> tmpEdge; 	//将边tmpEdge作为函数的返回值
		tmpEdge.start = oneVertex;
		ListNode<listData<EdgeType>> *temp = graList[oneVertex].head;  			   //graList[oneVertex].head保存的是顶点oneVertex的边表，					   //temp->next指向顶点oneVertex的第一条边(如果temp->next不为null)
		if (temp->next != NULL)		//顶点oneVertex的第一条边存在
		{
			tmpEdge.end = temp->next->element.vertex;
			tmpEdge.weight = temp->next->element.weight;
		}
		return tmpEdge;
	}
	Edge<EdgeType> NextEdge(Edge<EdgeType> oneEdge)
	{//返回与边OneEdge有相同关联顶点的下一条边
		Edge<EdgeType> tmpEdge;
		tmpEdge.start = oneEdge.start;
		ListNode<listData<EdgeType>>*temp = graList[oneEdge.start].head;
		//确定边oneEdge在边表中的位置,如果边oneEdge的下一条边确实存在，
		//则temp->next指针指向下一条边的表目
		while (temp->next != NULL && temp->next->element.vertex <= oneEdge.end)
			temp = temp->next;
		if (temp->next != NULL)         //边oneEdge的下一条边存在 
		{
			tmpEdge.end = temp->next->element.vertex;
			tmpEdge.weight = temp->next->element.weight;
		}
		return tmpEdge;
	}
	void setEdge(int start, int end, EdgeType weight)//为图设定一条边
	{
		ListNode<listData<EdgeType>> *temp = graList[start].head;
		while (temp->next != NULL && temp->next->element.vertex < end)
			//确定边(start,end)或<start,end>在边表中的位置,如果不存在,则边				//(start,end)或<start,end>为新加的一条边
			temp = temp->next;
		if (temp->next == NULL)
		{//边在边表中不存在且在边表中其后已无其他边,
		 //则在边表中加入这条边
			temp->next = new ListNode<listData<EdgeType>>;
			temp->next->element.vertex = end;
			temp->next->element.weight = weight;
			this->edgeNum++;
			return;
		}
		if (temp->next->element.vertex == end)		//边在边表中已存在
		{
			temp->next->element.weight = weight;
			return;
		}
		if (temp->next->element.vertex > end)
		{//边在边表中不存在,但在边表中其后存在其他边,
		 //则在边表中插入这条边
			ListNode<listData<EdgeType>> *other = temp->next;
			temp->next = new ListNode<listData<EdgeType>>;
			temp->next->element.vertex = end;
			temp->next->element.weight = weight;
			temp->next->next = other;
			this->edgeNum++;

		}
	}
	void delEdge(int start, int end)         	//删掉图的一条边
	{
		ListNode<listData<EdgeType>> *temp = graList[start].head;
		while (temp->next != NULL && temp->next->element.vertex < end)
			temp = temp->next;
		if (temp->next == NULL) return;        	//边不存在,不需任何操作
		if (temp->next->element.vertex == end)//边存在,将其删掉
		{
			ListNode<listData<EdgeType>> *other = temp->next->next;
			delete temp->next;
			temp->next = other;
			this->edgeNum--;
		}
	}
};
