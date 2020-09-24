#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

#define m 3  //B-树的阶
//#define KeyType int




template <class Key>
class BNode
{
public:
    Key key[m + 1]; // 个数key[0]
    BNode<Key> *parent, *ptr[m + 1];
    string record[m + 1]; //节点标记
};


template <class Key>
class Result
{
public:
    BNode<Key> *r;           		// 指向找到的结点
    int i;                     	// 记录所查关键字在结点中的位置
    bool flag;					// 是否查找到关键字的标志
    Result(BNode<Key> * rr, int ii, int flagg)
    {
        r = rr;
        i = ii;
        flag = flagg;
    };
};

template<class Key>
class BTree
{
BNode<Key> *root;
public:

    //BTree();                  		// 构造函数
    //Result<Key> Search(const BTree<Key> &T, Key key);	// 查询关键字x所在的结点
    //BNode<Key> *InsertBTree(Key x,BNode<Key>* p,int i); // 插入关键字x
    void DeleteBTree(Key x);            		// 删除关键字x
    BNode<Key> * getroot(){return root;}
    int initTree()
    {
        root = NULL;
        return 0;
    };
    int destroyTree()
    {
        BTree<Key> T;
        T.root = root;
        if(root == NULL)
            return 0;
        for(int i = 0; i <= root->key[0]; i++)
        {
            T.destroyTree();
            root->ptr[i] = NULL;
        }
        delete root;
        return 0;
    };
    Result<Key> Search(Key key);
    int Insert(BNode<Key> *q, int i, Key key, BNode<Key> *ap, string rcd);
    int split(BNode<Key> *q, int s, BNode<Key> *ap);
    int NewRoot(BNode<Key> *q, Key key, BNode<Key> *ap, string rcd);
    int InsertBTree(Key key, BNode<Key>  *q, int i, string rcd);
    int traverse(const BNode<Key> *q);


};




/*template<class Key>
int BTree::destroyTree(BTree<Key> T){
    if(T==NULL)
        return 0;
    for(int i=0; i<=T.root->key[0]; i++){
        T.destroyTree((T.root)->ptr[i]);
        T.root->ptr[i] = NULL;
    }
    delete T;
    return 0;
}*/

/*template<class Key>
int Search<Key> BTree::(const BTree<Key> &T, Key K){
   int i=0,j;
   for(j=1;j<=T->key[0];j++)
       if(K >= T->key[j])
           i=j;
   return i;
}*/




// 在B-树上查找
template<class Key>
Result<Key> BTree<Key>::Search(const Key x)
{
    // 在m阶B-树中查找关键字x，返回结果Result。如查找成功，则flag=1，指针r
// 指向的结点中的第i个关键字就是所查关键字x；如果查找不成功，则flag=0，
// 等于x的关键字应插入在指针r所指的结点中第i个关键字和第i+1个关键字之间
    Result<Key> ret(NULL, 0, false);
    BNode<Key> *p = root;
    BNode<Key> *q = NULL;
    int i = 0;
    while (p && !ret.flag)
    {
        for(i = 1; i <= p->key[0]; i++)
        {
            //找到待查记录所在节点
            if(p->key[i] >= x) //在p->key[1…keynum]中查找，
                break;            //i使得：p->key[i]<=X<p-> key[i+1]
        }
        if(i > 0 && p->key[i] == x) //在节点中查找该记录x所查关键字
        {
            ret.flag = true;//查找成功
            ret.r = p;
            ret.i = i;
        }
        else
        {
            q = p;        //查找不成功，返回x的插入信息
            p = p->ptr[i - 1];
            ret.r = q;
            ret.i = i;
        }
    }
    return ret;
}



// 暂时在这个节点加上这个关键字，后面是在不行再split操作

template<class Key>
int BTree<Key>::Insert(BNode<Key> *q, int i, Key key, BNode<Key> *ap, string rcd)
{
    q->key[0]++;
    int j = q->key[0];
    for(; j > i + 1; j--)
    {
        q->key[j] = q->key[j - 1];
        q->ptr[j] = q->ptr[j - 1];
        q->record[j] = q->record[j - 1];
    }
    q->key[j] = key;
    q->ptr[j] = ap;
    q->record[j] = rcd;
    return 0;

}

// 满了，把一个关键字序列分裂成两个
template<class Key>
int BTree<Key>::split(BNode<Key> *q, int s, BNode<Key> *ap)
{
    // cout << "s=" << s <<endl;

    BNode<Key> *b;
    ap = b;
//BNode<Key> *p = root;

    //ap = new BNode<int>;
    ap->key[0] = 0;
    root->key[0]--;
    ap->ptr[0] = root->ptr[s];
    if(ap->ptr[0] != NULL)
    {
        ap->ptr[0]->parent = ap;
    }
    ap->parent = root->parent;
    for(int i = s + 1, j = 1; i <= m; i++, j++)
    {
        ap->key[j] = root->key[i];
        ap->ptr[j] = root->ptr[i];
        ap->record[j] = root->record[i];
        ap->key[0] ++;
        root->key[0]--;
        if(ap->ptr[j] != NULL)
        {
            ap->ptr[j]->parent = ap;
        }
    }
    return 0;
}

template<class Key>
int BTree<Key>::NewRoot(BNode<Key> *q, Key key, BNode<Key> *ap, string rcd)
{
    BTree<Key> p;
    p.root = root;
    BTree<Key> T;
    //  T = new BTNode;
    T.root->key[0] = 1;
    T.root->key[1] = key;
    T.root->parent = NULL;
    T.root->ptr[0] = p.root;
    T.root->ptr[1] = ap;
    T.root->record[1] = rcd;
    if(T.root->ptr[0] != NULL)
    {
        T.root->ptr[0]->parent = T.root;
    }
    if(T.root->ptr[1] != NULL)
    {
        T.root->ptr[1]->parent = T.root;
    }
    return 0;
}

// 在B-树上添加
template<class Key>
int BTree<Key>::InsertBTree(Key key, BNode<Key> *q, int i, string rcd)
{
    Key x = key;
    BTree<Key> T;
    T.root = root;

    string y = rcd;
    BNode<Key> *ap = NULL;
    bool finished = false;
    Result<Key> ret(NULL, 0, false);
    while(q != NULL && !finished)
    {
        Insert(q, i, x, ap, rcd);
        if(q->key[0] < m)
            finished = true;
        else
        {
            int s = (m + 1) / 2; // 上取整
            split(q, s, ap);
            x = q->key[s];
            y = q->record[s];
            q = q->parent;
            if(q != NULL)
                ret = T.Search(x);
        }
    }
    if(!finished)
    {
        NewRoot(T.root, x, ap, y);
    }
    return 0;
}

template<class Key>
int BTree<Key>::traverse(const BNode<Key> *q)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        //if(T->parent!=NULL){
        //    cout << endl << T->key[1] << "parent " << T->parent->key[1] << endl;
        //}
        if(root->ptr[0] != NULL)
        {
            //cout << T->key[1]<< "的第0个子" << endl;
            traverse(root->ptr[0]);
        }
        for(int i = 1; i <= root->key[0]; i++)
        {
            cout << root->key[i] << " "; // visit
            if(root->ptr[i] != NULL)
            {
                //cout << T->key[i]<< "的第"<<i<<"个子" << endl;
                traverse(root->ptr[i]);
            }
        }
        return 0;
    }
}

int main()
{
    BTree<int> T;
    T.initTree();
    int key;
    string str;
    while(cin >> key >> str && key != -1)
    {
        Result<int> s = T.Search(key);
        if(!s.flag)
        {
            cout << "添加" << key << "  " << str << endl;
            cout << s.i << endl;
            T.InsertBTree(key, s.r, s.i, str);
            T.traverse(T.getroot());
            cout << endl;
        }
    }
    cout << "Now 开始查找过程" << endl;
    while(cin >> key)
    {
        Result<int> s = T.Search(key);
        if(s.flag)
            cout << s.r->key[s.i] << " -> " << s.r->record[s.i] << endl;
        else
            cout << "Not Found! " << endl;
    }
    T.destroyTree();
    // system("pause");
    return 0;
}



