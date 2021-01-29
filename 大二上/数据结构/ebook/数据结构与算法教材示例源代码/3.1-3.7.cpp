#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
template <class T>
class BinaryTreeNode{
	//friend class BinaryTree<T>;
private:
	T element;                      	//结点的数据域
	BinaryTreeNode<T> * leftChild;   	//结点的左孩子结点
	BinaryTreeNode<T> * rightChild;   	//结点的右孩子结点
public:
	BinaryTreeNode();              	//默认构造函数
	BinaryTreeNode(const T& ele);	//给定数据域的值的构造函数
	BinaryTreeNode(const T& ele, BinaryTreeNode<T> * l, BinaryTreeNode<T> * r);			//给定数据值和左右孩子结点的构造函数
	BinaryTreeNode<T> * getLeftChild() const;//返回该结点的左孩子结点
	BinaryTreeNode<T> * getRightChild() const;//返回该结点的右孩子结点
	void setLeftChild(BinaryTreeNode<T> * l);//设置该结点的左孩子结点
	void setRightChild(BinaryTreeNode<T> * r);//设置该结点的右孩子结点
	void createLeftChild();//创建该结点的左孩子结点
	void createRightChild();//创建该结点的右孩子结点
	T getValue() const;                           //返回该结点的数据值
	void setValue(const T& val);                //设置该结点的数据域的值
	bool isLeaf() const;  //判断该结点是否是叶子结点，若是，则返回true
};
template<class T>
BinaryTreeNode<T>::BinaryTreeNode()
{
    element = 0;
    leftChild = rightChild = NULL;
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele)
{
    element = ele;
    leftChild = rightChild = NULL;
}
template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& ele, BinaryTreeNode<T> * l, BinaryTreeNode<T> * r)
{
    element = ele;
    leftChild = l;
    rightChild = r;
}
template<class T>
BinaryTreeNode<T> * BinaryTreeNode<T>::getLeftChild() const
{
    return leftChild;
}
template<class T>
BinaryTreeNode<T> * BinaryTreeNode<T>::getRightChild() const
{
    return rightChild;
}
template<class T>
void BinaryTreeNode<T>::setLeftChild(BinaryTreeNode<T> * l)
{
    leftChild = l;
}
template<class T>
void BinaryTreeNode<T>::setRightChild(BinaryTreeNode<T> * r)
{
    rightChild = r;
}
template<class T>
void BinaryTreeNode<T>::createLeftChild()
{
    leftChild = new BinaryTreeNode<T>;
}
template<class T>
void BinaryTreeNode<T>::createRightChild()
{
    rightChild = new BinaryTreeNode<T>;
}
template<class T>
T BinaryTreeNode<T>::getValue() const
{
    return element;
}
template<class T>
void BinaryTreeNode<T>::setValue(const T& val)
{
    element = val;
}
template<class T>
bool BinaryTreeNode<T>::isLeaf() const
{
    if(leftChild == NULL && rightChild == NULL)
        return true;
    else
        return false;
}
template <class T>
class BinaryTree{
private:
	BinaryTreeNode<T> * root;				//二叉树根结点
public:
	BinaryTree();              				//默认构造函数
	~BinaryTree();                  		//析构函数
	bool isEmpty() const;           		//判断二叉树是否为空树
	BinaryTreeNode<T> * getRoot() const;	//返回二叉树的根结点
	BinaryTreeNode<T> * getParent(BinaryTreeNode<T> * current) const;
                                              		//返回current结点的父结点
	BinaryTreeNode<T> * getLeftSibling(BinaryTreeNode<T> * current) const;
	                                          	//返回current结点的左兄弟
	BinaryTreeNode<T> * getRightSibling(BinaryTreeNode<T> * current) const;
	                                          	//返回current结点的右兄弟
	void levelOrder(BinaryTreeNode<T> * root);
	                               		//广度优先遍历以root为根结点的子树
	void preOrder(BinaryTreeNode<T> * root);
									//先序遍历以root为根结点的子树
    void PreOrderWithoutRecusion(BinaryTreeNode<T> * root);
                                    //非递归先序遍历以root为根结点的子树
	void inOrder(BinaryTreeNode<T> * root);
									//中序遍历以root为根结点的子树
    void InOrderWithoutRecusion(BinaryTreeNode<T> * root);
                                    //非递归中序遍历以root为根结点的子树
	void postOrder(BinaryTreeNode<T> * root);
									//后序遍历以root为根结点的子树
    void PostOrderWithoutRecusion(BinaryTreeNode<T> * root);
                                    //非递归后序遍历以root为根结点的子树
	void deleteBinaryTree(BinaryTreeNode<T> * root);
	                    				//删除以root为根结点的子树
    void visit(BinaryTreeNode<T> *t);   //访问当前节点
    void create1(string m,string n);    //输入二叉树的先序和中序
    void preincreatetree(BinaryTreeNode<T> *t,string pre,string in);
                                        //先序和中序创建二叉树
    void create2(string m,string n);    //输入二叉树的后序和中序
    void inpostcreatetree(BinaryTreeNode<T> *t,string in,string post);
                                        //后序和中序创建二叉树
};
template <class T>
BinaryTree<T>::BinaryTree()
{
    root = NULL;
}
template <class T>
BinaryTree<T>::~BinaryTree()
{
    deleteBinaryTree(root);
}
template <class T>
bool BinaryTree<T>::isEmpty() const
{
    if(root == NULL)
        return true;
    else
        return false;
}
template <class T>
BinaryTreeNode<T> * BinaryTree<T>::getRoot() const
{
    return root;
}
template <class T>
void BinaryTree<T>::levelOrder(BinaryTreeNode<T> * root)
{
    queue<BinaryTreeNode<T> *> nodeQueue;//用队列来存放将要访问的结点
	BinaryTreeNode<T> * pointer = root;

	if(pointer)                          //如果根结点非空，将根结点移入队列
		nodeQueue.push(pointer);
	while(!nodeQueue.empty())
	{
		pointer = nodeQueue.front(); 	//读取队首结点
		visit(pointer);	                 	//访问当前结点
		nodeQueue.pop();               	//将访问过的结点移出队列
		if(pointer->getLeftChild())
			nodeQueue.push(pointer->getLeftChild());
		if(pointer->getRightChild())
			nodeQueue.push(pointer->getRightChild());
		                       	//将访问过的结点的左右孩子结点依次加入到队尾
	}
}
template <class T>
void BinaryTree<T>::preOrder(BinaryTreeNode<T> * root)
{
    if(root != NULL)
	{
		visit(root);			         	//访问当前结点
		preOrder(root->getLeftChild());			//访问左子树
		preOrder(root->getRightChild());	   		//访问右子树
	}
}
template <class T>
void BinaryTree<T>::PreOrderWithoutRecusion(BinaryTreeNode<T> * root)
{
    stack<BinaryTreeNode<T> * > nodeStack;   	//存放待访问的结点的栈
  	BinaryTreeNode<T> * pointer = root;      	//保存根结点

	while(!nodeStack.empty() || pointer)	 	//栈为空时遍历结束
	{
		if(pointer)
        {
		  	  visit(pointer);		          	//访问当前结点
			  if(pointer->getRightChild() != NULL)
					nodeStack.push(pointer->getRightChild());
			                           	//当前访问结点的右子树的根结点入栈
			  pointer = pointer->getLeftChild();		//转向访问其左子树
		}
		else
		{	        			 	//左子树访问完毕，转向访问右子树
			  pointer = nodeStack.top();		//读取栈顶待访问的结点
			  nodeStack.pop();                  	//删除栈顶结点
		}
	}
}
template <class T>
void BinaryTree<T>::inOrder(BinaryTreeNode<T> * root)
{
    if(root != NULL)
	{
		inOrder(root->getLeftChild());			//访问左子树
		visit(root);			         	//访问当前结点
		inOrder(root->getRightChild());	    	//访问右子树
	}
}
template <class T>
void BinaryTree<T>::InOrderWithoutRecusion(BinaryTreeNode<T> * root)
{
    stack<BinaryTreeNode<T> * > nodeStack; 		//存储待访问结点
  	BinaryTreeNode<T> * pointer = root;		  	//保存根结点

	while(!nodeStack.empty() || pointer)     	//栈为空时遍历结束
	{
		if(pointer)
        {
			  nodeStack.push(pointer);			//当前结点入栈
			  pointer = pointer->getLeftChild();   	//转向访问其左孩子
		}
		else
        {        					//左子树访问完毕，转向访问右子树
			  pointer = nodeStack.top();		//读取栈顶待访问的结点
		  	  visit(pointer);		       		//访问当前结点
			  pointer = pointer->getRightChild();  	//转向其右孩子
			  nodeStack.pop();				  	//删除栈顶结点
		}
	}
}
template <class T>
void BinaryTree<T>::postOrder(BinaryTreeNode<T> * root)
{
    if(root != NULL)
	{
		postOrder(root->getLeftChild());	    	//访问左子树
		postOrder(root->getRightChild());		//访问右子树
		visit(root);	                    //访问当前结点
	}
}
template <class T>
void BinaryTree<T>::PostOrderWithoutRecusion(BinaryTreeNode<T> * root)
{
    stack<BinaryTreeNode<T> * > nodeStack;	//存储待访问结点
  	BinaryTreeNode<T> * pointer = root;		//保存根结点
	BinaryTreeNode<T> * pre = root;         //保存前一个被访问的结点

	while(pointer)
    {
		for( ; pointer->getLeftChild() != NULL; pointer = pointer->getLeftChild())
			nodeStack.push(pointer);     	//向左搜索

		while(pointer != NULL && (pointer->getRightChild() == NULL || pointer->getRightChild() == pre))
        {
			        //当前结点没有右孩子或者右孩子刚被访问过,则访问该结点
			visit(pointer);
			pre = pointer;            		//记录刚被访问过的结点
			if(nodeStack.empty())
				return;
			pointer = nodeStack.top();   	//取栈顶结点
			nodeStack.pop();
		}
		nodeStack.push(pointer);
		pointer = pointer->getRightChild();  	//转向当前结点的右子树
	}
}
template <class T>
void BinaryTree<T>::deleteBinaryTree(BinaryTreeNode<T> * root)
{
    if(root!=NULL)
    {
        deleteBinaryTree(root->getLeftChild());
        deleteBinaryTree(root->getRightChild());
        delete root;
    }
}
template <class T>
void BinaryTree<T>::visit(BinaryTreeNode<T> *t)
{
    cout<<t->getValue();
}
template <class T>
void BinaryTree<T>::create1(string m,string n)
{
    root = new BinaryTreeNode<T>;
    preincreatetree(root,m,n);
}
template <class T>
void BinaryTree<T>::preincreatetree(BinaryTreeNode<T> *t,string pre,string in)
{
    if(pre.length() == 0)
    {
        t = NULL;
        return;
    }
    char tvalue = pre[0];
    int index = in.find(tvalue);                              //在中序序列中的位置
    string leftchild_in = in.substr(0,index);                 //左孩子的中序序列
    string rightchild_in = in.substr(index+1);                //右孩子的中序序列
    int leftchild_length = leftchild_in.length();             //左孩子的长度
    int rightchild_length = rightchild_in.length();           //右孩子的长度
    string leftchild_pre = pre.substr(1,leftchild_length);    //左孩子的前序序列
    string rightchild_pre = pre.substr(leftchild_length+1);   //右孩子的前序序列
    if(leftchild_length == 0 && rightchild_length == 0)
    {
        t->setValue(tvalue);
    }
    else if(leftchild_length > 0 && rightchild_length == 0)
    {
        t->setValue(tvalue);
        t->createLeftChild();
        preincreatetree(t->getLeftChild(),leftchild_pre,leftchild_in);        //递归创建左孩子
    }
    else if(leftchild_length == 0 && rightchild_length > 0)
    {
        t->setValue(tvalue);
        t->createRightChild();
        preincreatetree(t->getRightChild(),rightchild_pre,rightchild_in);     //递归创建右孩子
    }
    else if(leftchild_length > 0 && rightchild_length > 0)
    {
        t->setValue(tvalue);
        t->createLeftChild();
        t->createRightChild();
        preincreatetree(t->getLeftChild(),leftchild_pre,leftchild_in);        //递归创建左孩子
        preincreatetree(t->getRightChild(),rightchild_pre,rightchild_in);     //递归创建右孩子
    }
}
template <class T>
void BinaryTree<T>::create2(string m,string n)
{
    root = new BinaryTreeNode<T>;
    inpostcreatetree(root,m,n);
}
template <class T>
void BinaryTree<T>::inpostcreatetree(BinaryTreeNode<T> *t,string in,string post)
{
    if(post.length() == 0)
    {
        t = NULL;
        return;
    }
    char tvalue=post[post.length()-1];
    int index=in.find(tvalue);                                                //在中序序列中的位置
    string leftchild_in=in.substr(0,index);                                   //左孩子的中序序列
    string rightchild_in=in.substr(index+1);                                  //右孩子的中序序列
    int leftchild_length=leftchild_in.length();                               //左孩子的长度
    int rightchild_length=rightchild_in.length();                             //右孩子的长度
    string leftchild_post=post.substr(0,leftchild_length);                    //左孩子的后序序列
    string rightchild_post=post.substr(leftchild_length,rightchild_length);   //右孩子的后序序列
    if(leftchild_length == 0 && rightchild_length == 0)
    {
        t->setValue(tvalue);
    }
    else if(leftchild_length > 0 && rightchild_length == 0)
    {
        t->setValue(tvalue);
        t->createLeftChild();
        inpostcreatetree(t->getLeftChild(),leftchild_in,leftchild_post);           //递归创建左孩子
    }
    else if(leftchild_length == 0 && rightchild_length > 0)
    {
        t->setValue(tvalue);
        t->createRightChild();
        inpostcreatetree(t->getRightChild(),rightchild_in,rightchild_post);        //递归创建右孩子
    }
    else if(leftchild_length > 0 && rightchild_length > 0)
    {
        t->setValue(tvalue);
        t->createLeftChild();
        t->createRightChild();
        inpostcreatetree(t->getLeftChild(),leftchild_in,leftchild_post);        //递归创建左孩子
        inpostcreatetree(t->getRightChild(),rightchild_in,rightchild_post);     //递归创建右孩子
    }
}
int main()
{
    BinaryTree<char> tree;
    string m,n;
    cout<<"请输入前序序列："<<endl;
    cin>>m;//ABDFGCEH
    cout<<"请输入中序序列："<<endl;
    cin>>n;//BFDGACEH
    tree.create1(m,n);
    /*cout<<"请输入中序序列："<<endl;
    cin>>m;
    cout<<"请输入后序序列："<<endl;
    cin>>n;//FGDBHECA
    tree.create2(m,n);*/
    cout<<"该二叉树广度优先遍历序列为："<<endl;//ABCDEFGH
    tree.levelOrder(tree.getRoot());
    cout<<"\n该二叉树递归前序遍历序列为："<<endl;
    tree.preOrder(tree.getRoot());
    cout<<"\n该二叉树非递归前序遍历序列为："<<endl;
    tree.PreOrderWithoutRecusion(tree.getRoot());
    cout<<"\n该二叉树递归中序遍历序列为："<<endl;
    tree.inOrder(tree.getRoot());
    cout<<"\n该二叉树非递归中序遍历序列为："<<endl;
    tree.InOrderWithoutRecusion(tree.getRoot());
    cout<<"\n该二叉树递归后序遍历序列为："<<endl;
    tree.postOrder(tree.getRoot());
    cout<<"\n该二叉树非递归后序遍历序列为："<<endl;
    tree.PostOrderWithoutRecusion(tree.getRoot());
    return 0;
}
