#include <iostream>
#include<stdlib.h>
using namespace std;

template <class T>
class HuffmanTreeNode {
	//friend class HuffmanTree<T>;
	
	
public:
	T element;                      	//结点的数据域
	HuffmanTreeNode<T>* leftChild;   	//结点的左孩子结点
	HuffmanTreeNode<T>* rightChild;   	//结点的右孩子结点
	HuffmanTreeNode<T>* parent;
	HuffmanTreeNode() {
		leftChild = NULL;
		rightChild = NULL;
		parent = NULL;
	}//默认构造函数
	HuffmanTreeNode(T ele, HuffmanTreeNode<T> * l = NULL, HuffmanTreeNode<T> * r = NULL, HuffmanTreeNode<T> * p = NULL){
		element = ele;
		leftChild = l;
		rightChild = r;
		parent = p;
	}			//给定数据值和左右孩子结点的构造函数
	bool operator <=(HuffmanTreeNode<T> &r) {
         return element <= r.element;

	}
     bool operator <(HuffmanTreeNode<T> &r) {
         return element<r.element;

	}
     bool operator >=(HuffmanTreeNode<T> &r) {
         return element >= r.element;

	}
     bool operator >(HuffmanTreeNode<T> &r) {
         return element>r.element;

	}

};

template <class T>
class MinHeap
{
private:
	T* heapArray;               		//存放堆数据的数组
	int CurrentSize;             		//当前堆中元素数目
	//int MaxSize;                		//堆所能容纳的最大元素数目
public:
	MinHeap(int num)
	{
		this->heapArray = new T[num];
		this->CurrentSize = 0;
	}
	virtual ~MinHeap(){
		delete[]heapArray;
	}	//析构函数
	void SiftUp(int position)	//从position向上开始调整，使序列成为堆
	{
		//准备
		int i = position;           //标识插入的新结点
		int j = (i - 1) / 2;   //标识父结点
		T temp = heapArray[i];     	//保存新结点的关键码
									//过筛
		while (i > 0)
		{
			if (*temp < *heapArray[j])
			{                             //该结点的关键码大于父结点的值时
				heapArray[i] = heapArray[j];	//交换对应值
				i = j;
				j = (i - 1) / 2;              //向上继续判断是否满足最大堆的性质
			}
			else break;
		}
		heapArray[i] = temp;
	}

	void SiftDown(int left,int m)//筛选法函数，参数left表示开始处理的数组下标
	{
		//准备
		int i = left;            			//标识父结点
		int j = 2 * i + 1;           		//标识左子结点
		T temp = heapArray[i];     		//保存父结点的关键码
										//过筛
		while (j <= m)
		{
			if ((j < m) && (heapArray[j] > heapArray[j + 1]))
				j++;
			//该结点有右孩子且右孩子的关键码小于左孩子的关键码时，j指向右子结点
			if (temp>heapArray[j])
			{                       //该结点的关键码大于左右孩子中比较小的那个时
				heapArray[i] = heapArray[j];	//交换对应值
				i = j;
				j = 2 * j + 1;                 //向下继续判断是否满足最大堆的性质
			}
			else break;
		}
		heapArray[i] = temp;
	}
	
	bool Insert(const T& newNode)	//向堆中插入新元素newNode
	{	
		heapArray[CurrentSize] = newNode;
		SiftUp(CurrentSize);
		CurrentSize++;
		return true;
	}
	bool RemoveMin(T& x)                  	//从堆顶删除
	{
		if (!CurrentSize)
			return false;
		x = heapArray[0];
		heapArray[0] = heapArray[CurrentSize - 1];
		CurrentSize--;
		SiftDown(0,CurrentSize-1);
		return true;
	}
	T* getMinHeap() {
		return heapArray;
	}
	int getCurrSize()
	{
		return CurrentSize;
	}
};

template <class T>
class HuffmanTree
{
private:
	HuffmanTreeNode<T>* root;                               //Huffman树的树根
public:	
	HuffmanTree(T weight[], int n);                         //构造Huffman树，weight是权值的数组，n是数组长度
	~HuffmanTree() { DeleteTree(root); }	        //析构函数
	HuffmanTreeNode<T> * getRoot() {
		return root;
	}//返回Huffman树的根结点
	void preOrder(HuffmanTreeNode<T> *root);                //先序遍历以root为根结点的子树
	void inOrder(HuffmanTreeNode<T> *root);                 //中序遍历以root为根结点的子树
	//void visit(HuffmanTreeNode<T> *t);
	void MergeTree(HuffmanTreeNode<T> *ht1, HuffmanTreeNode<T> *ht2, HuffmanTreeNode<T>* parent);//把ht1和ht2为根的Huffman子树合并成一棵以parent为根的二叉树
	void DeleteTree(HuffmanTreeNode<T>* root);              //删除Huffman树或其子树

};


template<class T>
	HuffmanTree<T>::HuffmanTree(T weight[], int n)
	{
		MinHeap <HuffmanTreeNode<T>*> heap(n);  		//定义最小堆
		HuffmanTreeNode<T>* parent, *firstchild, *secondchild,*temp;
		//HuffmanTreeNode<T>* NodeList = new HuffmanTreeNode<T>[n];
		
		for (int i = 0; i<n; i++)
		{
			temp = new HuffmanTreeNode<T>(weight[i]);
			heap.Insert(temp);
		}
		for (int i = 0; i < n - 1; i++)			//通过n-1次合并建立Huffman树
		{
			parent = new HuffmanTreeNode<T>;
			firstchild = new HuffmanTreeNode<T>;
			secondchild = new HuffmanTreeNode<T>;
			heap.RemoveMin(firstchild);       	//选择权值最小的结点
            heap.RemoveMin(secondchild);
			MergeTree(firstchild, secondchild, parent);//合并权值最小的两棵树
			heap.Insert(parent);              	//把parent插入到堆中去
			root = parent;                       	//建立根结点
		}
	}

template<class T>
	void HuffmanTree<T>::MergeTree(HuffmanTreeNode<T> *ht1, HuffmanTreeNode<T> *ht2,HuffmanTreeNode<T>* parent)
	{
		parent->element = ht1->element + ht2->element;
		parent->leftChild = ht1;
		parent->rightChild = ht2;
		ht1->parent = parent;
		ht2->parent = parent;
	}

	template<class T>
	void HuffmanTree<T>::DeleteTree(HuffmanTreeNode<T>* root)
	{
		if (root == NULL)return;
		DeleteTree(root->leftChild);
		DeleteTree(root->rightChild);
		delete root;
	}

	template <class T>
	void HuffmanTree<T>::preOrder(HuffmanTreeNode<T> *root)                 //前序遍历
	{
		if (root != NULL)
		{
			cout<<root->element<<" ";			         	//访问当前结点
			preOrder(root->leftChild);			//访问左子树
			preOrder(root->rightChild);	   		//访问右子树
		}
	}


	template <class T>
	void HuffmanTree<T>::inOrder(HuffmanTreeNode<T> *root)                  //中序遍历
	{
		if (root != NULL)
		{
			inOrder(root->leftChild);			//访问左子树
			cout << root->element << " ";			//访问当前结点
			inOrder(root->rightChild);	    	//访问右子树
		}
	}

	int main()
	{

		int a[4] = { 7,5,2,4 };

		HuffmanTree<int> ht1(a,4);

		cout << "该哈弗曼树递归前序遍历序列为：" << endl;
		ht1.preOrder(ht1.getRoot());

		cout << "该哈弗曼树递归中序遍历序列为：" << endl;
		ht1.inOrder(ht1.getRoot());

		system("pause");
		return 0;
	}
