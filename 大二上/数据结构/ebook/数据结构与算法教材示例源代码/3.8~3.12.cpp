#include<iostream>
using namespace std;
//【例3.8】线索二叉树的结点类。

template <class T>
class ThreadBinaryTreeNode
{
public:
	int leftTag, rightTag;                  	//左右标志位
	ThreadBinaryTreeNode<T> * leftChild;   	//前驱或左子树
	ThreadBinaryTreeNode<T> * rightChild;  	//后继或右子树
	T element;                                  	//结点数据域

	ThreadBinaryTreeNode() {}
	ThreadBinaryTreeNode(const T& ele)
	{
		element = ele;
	}//构造函数
	ThreadBinaryTreeNode(const T& ele, ThreadBinaryTreeNode<T> * l, ThreadBinaryTreeNode<T> * r)
	{
		element = ele;
		leftChild = l;
		rightChild = r;
	}
	ThreadBinaryTreeNode(const T& ele, ThreadBinaryTreeNode<T> * l, ThreadBinaryTreeNode<T> * r, int lt, int rt)
	{
		element = ele;
		leftChild = l;
		rightChild = r;
		leftTag = lt;
		rightTag = rt;
	}
	void getLeftChild() const
	{
		if (leftChild)
		{
			cout << leftChild->element << endl;
		}
		else
		{
			cout << "NULL" << endl;
		}
	}
	void getRightChild() const
	{
		if (rightChild)
		{
			cout << rightChild->element << endl;
		}
		else
		{
			cout << "NULL" << endl;
		}
	}
	void setLeftChild(ThreadBinaryTreeNode<T> * l)
	{
		leftChild = l;
	}
	void setRightChild(ThreadBinaryTreeNode<T> * r)
	{
		rightChild = r;
	}
	void getValue() const
	{
		cout << element << endl;
	}//返回该结点的数据值
	void setValue(const T& val)
	{
		element = val;
	}//设置该结点的数据域的值
};


//【例3.9】线索二叉树类。

template <class T>
class ThreadBinaryTree
{
public:
	ThreadBinaryTreeNode<T> * root;     		//根结点指针

	ThreadBinaryTree()
	{

	}                        	//构造函数
	ThreadBinaryTree(ThreadBinaryTreeNode<T> * r)
	{
		root = r;
	}
	~ThreadBinaryTree()
	{

	}//析构函数
	void InsertNode(ThreadBinaryTreeNode<T>* pointer, ThreadBinaryTreeNode<T>* newPointer);//中序线索二叉树的插入操作
	ThreadBinaryTreeNode<T> * getRoot();   		//返回根结点指针
	void InThread(ThreadBinaryTreeNode<T> * root, ThreadBinaryTreeNode<T> * &pre);//中序线索化二叉树
	void InOrder(ThreadBinaryTreeNode<T> * root);	//中序遍历
};

//【例3.10】中序线索化二叉树。

template <class T>
void ThreadBinaryTree<T>::InThread(ThreadBinaryTreeNode<T>* root, ThreadBinaryTreeNode<T>* &pre)//pre初始值为NULL
{
	ThreadBinaryTreeNode<T>* current;//pre为当前访问结点的前一个结点
	current = root;                          	//current为当前访问结点
	if (current != NULL)
	{
		InThread(current->leftChild, pre);	//中序线索化左子树
		if (current->leftChild == NULL)
		{
			current->leftChild = pre;
			current->leftTag = 1;     		//建立前驱线索
		}
		if ((pre) && (pre->rightChild == NULL))
		{
			pre->rightChild = current;
			pre->rightTag = 1;              	//建立后继线索
		}
		pre = current;
		InThread(current->rightChild, pre);	//中序线索化右子树
	}
}


//【例3.11】中序遍历线索二叉树。

template<class T>
void ThreadBinaryTree<T>::InOrder(ThreadBinaryTreeNode<T>* root)
{
	ThreadBinaryTreeNode<T>* current;
	current = root;

	while (current->leftTag == 0)
		current = current->leftChild;    	//寻找中序遍历的第一个结点
	while (current)
	{
		current->getValue();                  		//访问当前结点
		if (current->rightTag == 1)
		{
			current = current->rightChild;	//沿线索寻找后继
		}
		else
		{
			current = current->rightChild;
			while (current && current->leftTag == 0)
				current = current->leftChild; 	//寻找最左终端结点
		}
	}
}


//【例3.12】中序线索二叉树的插入操作。

template<class T>
void ThreadBinaryTree<T>::InsertNode(ThreadBinaryTreeNode<T>* pointer, ThreadBinaryTreeNode<T>* newPointer)
{
	if (pointer->rightTag == 1) //pointer无右孩子
	{
		newPointer->rightChild = pointer->rightChild;
		//pointer的后继变为newPointer的后继
		newPointer->rightTag = 1;
		pointer->rightChild = newPointer;	//newPointer成为pointer的右孩子
		pointer->rightTag = 0;
		newPointer->leftChild = pointer;	//pointer成为newPointer的前驱
		newPointer->leftTag = 1;
	}
	else //pointer有右孩子
	{
		ThreadBinaryTreeNode<T>* s = pointer->rightChild;
		while (s->leftTag == 0)
			s = s->leftChild;	//查找p结点的右子树的"最左下端"结点
		newPointer->rightChild = pointer->rightChild;
		//pointer的右孩子变为newPointer的右孩子
		newPointer->rightTag = 0;
		newPointer->leftChild = pointer;	//pointer变为newPointer的前驱
		newPointer->leftTag = 1;
		pointer->rightChild = newPointer;	//newPointer变为pointer的右孩子
		s->leftChild = newPointer;
		//newPointer变为pointer原来右子树的"最左下端"结点的前驱
	}
}



int main()
{//构建二叉树，书上的例子
	ThreadBinaryTreeNode<char> A('A', NULL, NULL, 0, 0);
	ThreadBinaryTreeNode<char> B('B', NULL, NULL, 0, 0);
	ThreadBinaryTreeNode<char> C('C', NULL, NULL, 0, 0);
	ThreadBinaryTreeNode<char> D('D', NULL, NULL, 0, 0);
	ThreadBinaryTreeNode<char> E('E', NULL, NULL, 0, 0);
	ThreadBinaryTreeNode<char> F('F', NULL, NULL, 0, 0);
	ThreadBinaryTreeNode<char> G('G', NULL, NULL, 0, 0);
	ThreadBinaryTreeNode<char> H('H', NULL, NULL, 0, 0);
	A.setLeftChild(&B);
	A.setRightChild(&C);
	B.setLeftChild(NULL);
	B.setRightChild(&D);
	C.setLeftChild(NULL);
	C.setRightChild(&E);
	D.setLeftChild(&F);
	D.setRightChild(&G);
	E.setLeftChild(NULL);
	E.setRightChild(&H);
	F.setLeftChild(NULL);
	F.setRightChild(NULL);
	G.setLeftChild(NULL);
	G.setRightChild(NULL);
	H.setLeftChild(NULL);
	H.setRightChild(NULL);
	ThreadBinaryTree<char> R(&A);
	ThreadBinaryTreeNode<char> *prev = NULL;
	R.InThread(&A, prev);//中序线索化
	R.InOrder(&A);//中序遍历
	ThreadBinaryTreeNode<char> I('I', NULL, NULL, 0, 0);//待插入结点，以书上为例，将newPointer结点插入到pointer结点的右侧。
	R.InsertNode(&B,&I);//将I插入到B的右侧
	R.InOrder(&A);//中序遍历
	system("pause");
	return 0;
}