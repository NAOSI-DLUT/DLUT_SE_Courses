#include<iostream>
using namespace std;

template <class T>
class BinarySearchTreeNode
{
public:
	T element;                          //结点的数据域
	BinarySearchTreeNode<T> * leftChild;   	//结点的左孩子结点
	BinarySearchTreeNode<T> * rightChild;   	//结点的右孩子结点

	BinarySearchTreeNode()              	//默认构造函数
	{

	}
	BinarySearchTreeNode(const T& ele)	//给定数据域的值的构造函数
	{
		element = ele;
	}
	BinarySearchTreeNode(const T& ele, BinarySearchTreeNode<T> * l, BinarySearchTreeNode<T> * r)	//给定数据值和左右孩子结点的构造函数
	{
		element = ele;
		leftChild = l;
		rightChild = r;
	}
	//BinarySearchTreeNode<T> * getLeftChild() const;//返回该结点的左孩子结点

	//BinarySearchTreeNode<T> * getRightChild() const;//返回该结点的右孩子结点

	void setLeftChild(BinarySearchTreeNode<T> * l)//设置该结点的左孩子结点
	{
		leftChild = l;
	}
	void setRightChild(BinarySearchTreeNode<T> * r)//设置该结点的右孩子结点
	{
		rightChild = r;
	}
	T getValue() const                           //返回该结点的数据值
	{
		return element;
	}
	void setValue(const T& val)                //设置该结点的数据域的值
	{
		element = val;
	}
	//bool isLeaf() const;  //判断该结点是否是叶子结点，若是，则返回true

};


template <class T>
class BinarySearchTree
{
public:
	BinarySearchTreeNode<T> * root;				//二叉树根结点

	BinarySearchTree(BinarySearchTreeNode<T> * r)              				//默认构造函数
	{
		root = r;
	}
	~BinarySearchTree()                  			//析构函数
	{

	}
	/*bool isEmpty() const;           			//判断二叉树是否为空树
	BinarySearchTreeNode<T> * getRoot() const;	//返回二叉树的根结点
	BinarySearchTreeNode<T> * getParent(BinarySearchTreeNode<T> * current) const;
	//返回current结点的父结点
	BinarySearchTreeNode<T> * getLeftSibling(BinarySearchTreeNode<T> * current) const;
	//返回current结点的左兄弟
	BinarySearchTreeNode<T> * getRightSibling(BinarySearchTreeNode<T> * current) const;
	//返回current结点的右兄弟
	void breadthFirstOrder(BinarySearchTreeNode<T> * root);
	//广度优先遍历以root为根结点的子树
	void preOrder(BinarySearchTreeNode<T> * root);
	//先序遍历以root为根结点的子树
	void inOrder(BinarySearchTreeNode<T> * root);
	//中序遍历以root为根结点的子树
	void postOrder(BinarySearchTreeNode<T> * root);
	//后序遍历以root为根结点的子树
	void levelOrder(BinarySearchTreeNode<T> * root);
	//按层次遍历以root为根结点的子树
	void deleteBinaryTree(BinarySearchTreeNode<T> * root);
	//删除以root为根结点的子树*/
	BinarySearchTreeNode<T>* search(BinarySearchTreeNode<T>* root, T key);
	//二叉搜索树的查找
	void insertNode(const T& value);
	//向二叉搜索树中插入结点
	void deleteByMerging(BinarySearchTreeNode<T>* node);
	//合并删除
	void deleteByCopying(BinarySearchTreeNode<T>* node);
	//复制删除
};







//【例3.13】二叉搜索树的查找。

template<class T>
BinarySearchTreeNode<T>* BinarySearchTree<T>::search(BinarySearchTreeNode<T>* root, T key)
{
	BinarySearchTreeNode<T>* current = root;
	while ((NULL != root) && (key != current->element))
		//当前结点的key值等于查询的值时，退出循环
	{
		current = (key < current->element ? search(current->leftChild, key) : search(current->rightChild, key));
		//根据当前结点的值的大小决定移动方向
	}
	return current;
}

//【例3.14】向二叉搜索树中插入结点。

template<class T>
void BinarySearchTree<T>::insertNode(const T& value) 
{
	BinarySearchTreeNode<T> *p = root, *prev = NULL;
	while (p != 0)
	{                                  		//新结点查找位置
		prev = p;                      	//记录父结点
		if (p->getValue() < value)
			p = p->rightChild;
		else
			p = p->leftChild;
	}
	if (root == NULL)               		//如果是空树，将新结点作为根结点
		root = new BinarySearchTreeNode<T>(value);
	else if (prev->getValue() < value)
		//根据关键码决定设置为左子结点还是右子结点
		prev->rightChild = new BinarySearchTreeNode<T>(value);
	else
		prev->leftChild = new BinarySearchTreeNode<T>(value);
}


//【例3.15】合并删除的算法实现。

template<class T>

void BinarySearchTree<T>::deleteByMerging(BinarySearchTreeNode<T>* node)
{
	BinarySearchTreeNode<T> *tmp = node;
	if (node != NULL)
	{
		//如果被删除结点没有右子树，用其左子树的根结点来代替被删除结点
		if (!node->rightChild)
			node = node->leftChild;
		//如果被删除结点没有左子树，用其右子树的根结点来代替被删除结点
		else if (node->leftChild == NULL)
			node = node->rightChild;
		else {                      	//如果被删除结点左右子树都存在
			tmp = node->leftChild;
			while (tmp->rightChild != NULL)
				//查找左子树中按中序遍历的最后一个结点
				tmp = tmp->rightChild;
			//将查找到的结点的右指针赋值为被删除结点的右子树的根
			tmp->rightChild = node->rightChild;
			tmp = node;
			node = node->leftChild; //用左子树的根结点代替被删除结点
		}
		//delete tmp;
	}
}

//【例3.16】复制删除算法实现。

template<class T>
void BinarySearchTree<T>::deleteByCopying(BinarySearchTreeNode<T>* node)
{
	BinarySearchTreeNode<T>* previous, *tmp = node;
	//如果被删除结点没有右子树，用其左子树的根结点来代替被删除结点
	if (node->rightChild == NULL)
		node = node->leftChild;
	//如果被删除结点没有左子树，用其右子树的根结点来代替被删除结点
	else if (node->leftChild == NULL)
		node = node->rightChild;
	else    								//如果被删除结点左右子树都存在
	{
		tmp = node->leftChild;
		previous = node;
		while (tmp->rightChild != NULL)	//查找左子树中关键码最大的结点
		{
			previous = tmp;
			tmp = tmp->rightChild;
		}
		node->element = tmp->element;	//将查找到的结点的值赋值给被删除结点
		if (previous == node)
			previous->leftChild = tmp->leftChild;
		else
			previous->rightChild = tmp->leftChild;
	}
	//delete tmp;
}


int main()
{
	//构建二叉树，书上图3-22的例子
	BinarySearchTreeNode<int> N1(400, NULL, NULL);
	BinarySearchTreeNode<int> N2(122, NULL, NULL);
	BinarySearchTreeNode<int> N3(450, NULL, NULL);
	BinarySearchTreeNode<int> N4(99, NULL, NULL);
	BinarySearchTreeNode<int> N5(250, NULL, NULL);
	BinarySearchTreeNode<int> N6(500, NULL, NULL);
	BinarySearchTreeNode<int> N7(110, NULL, NULL);
	BinarySearchTreeNode<int> N8(200, NULL, NULL);
	BinarySearchTreeNode<int> N9(300, NULL, NULL);
	BinarySearchTreeNode<int> N10(105, NULL, NULL);
	BinarySearchTreeNode<int> N11(330, NULL, NULL);
	N1.setLeftChild(&N2);
	N1.setRightChild(&N3);
	N2.setLeftChild(&N4);
	N2.setRightChild(&N5);
	N3.setLeftChild(NULL);
	N3.setRightChild(&N6);
	N4.setLeftChild(NULL);
	N4.setRightChild(&N7);
	N5.setLeftChild(&N8);
	N5.setRightChild(&N9);
	N6.setLeftChild(NULL);
	N6.setRightChild(NULL);
	N7.setLeftChild(&N10);
	N7.setRightChild(NULL);
	N8.setLeftChild(NULL);
	N8.setRightChild(NULL);
	N9.setLeftChild(NULL);
	N9.setRightChild(&N11);
	N10.setLeftChild(NULL);
	N10.setRightChild(NULL);
	N11.setLeftChild(NULL);
	N11.setRightChild(NULL);
	BinarySearchTree<int> R(&N1);
	//查找element为200的结点
	//BinarySearchTreeNode<int>* P=R.search(&N1, 200);
	//cout << P->element << endl;
	//将Key值为120的结点插入到树中
	//R.insertNode(120);
	//cout << N7.rightChild->element << endl;
	//合并删除N2
	//R.deleteByMerging(&N2);
	//复制删除N2
	R.deleteByCopying(&N2);
	system("pause");
	return 0;
}