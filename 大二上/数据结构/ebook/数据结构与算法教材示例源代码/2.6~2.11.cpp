#include <iostream>
using namespace std;

// 2.6
template<class T>
class LinkNode
{
	public:
		T data;	//数据域
		LinkNode<T>*link; //指向后继指针的结点
        LinkNode(){  //llz
        }
		LinkNode(const T&el, LinkNode<T>*ptr = 0){ //构造函数
			data=el;
			link=ptr;
        }
};

// 2.7
template<class T>
class LinkList
{
	private:
		LinkNode<T> *head, *tail; //表头和表尾指针
		LinkNode<T> *prevPtr, *currPtr;	//记录表当前遍历位置的指针，由插入和删除操作更新
		int position; //当前元素在表中的位置序号，由函数reset使用
	public:
		LinkList();
		~LinkList();
		int getSize()const; //返回链表中的元素个数
		bool isEmpty()const; //链表是否为空
		void reset(int pos = 0); //初始化指针的位置（第一位数的位置设为0)
		void next(); //使指针移动到下一个结点
		bool endOfList()const; //指针是否到了链尾
		int currentPosition(void); //返回指针当前的位置
		void insertHead(const T&item); //在表头插入结点
		void insertTail(const T&item); //在表尾添加结点
		void insertAt(const T&item); //在当前结点之前插入结点
		void insertAfter(const T&item);	//在当前结点之后插入结点
		T deleteHead(); //删除头结点
		void deleteCurrent(); //删除当前结点
		T&data(); //返回对当前结点成员数据的引用
		const T&data()const; //返回对当前结点成员数据的常引用
		void clear(); //清空链表：释放所有结点的内存空间
		LinkNode<T>* setPos(int pos); //返回指定位置pos的指针
		bool insertPos(const int i, const T value); //在指定位置插入结点
		bool deletePos(const int i); //删除指定位置的结点
		void display(); //llz
};


template<class T>
LinkList<T> :: LinkList(){
    head = new LinkNode<T>();
    tail = new LinkNode<T>();
    prevPtr = new LinkNode<T>();
    currPtr = new LinkNode<T>();
    head->link = NULL;
    tail->link = NULL;
}

template<class T>
LinkList<T> :: ~LinkList(){
    LinkNode<T> *p;
    while(head!=NULL){
        p = head;
        head = p->link;
        delete p;
    }
    delete tail;
}


// 2.8
template<class T>
LinkNode<T> * LinkList<T>::setPos(int pos) //返回指定位置pos的指针
{
	if(pos == -1) //i为-1则定位到头结点
		return head;
	int count = 0;
	LinkNode<T> *p = head->link;
	while(p != NULL && count < pos)
	{
		p = p->link;
		count++;
	}
	return p; //指向第i个结点，当链表长度小于i时返回NULL
}

// 2.9
template<class T>
bool LinkList<T>::insertPos(const int i, const T value)
{
	LinkNode<T> *p, *q; // q是新插入的结点，llz
	if((p = setPos(i - 1)) == NULL) //p是第i个结点的前驱
	{
		cout << "插入操作不允许" << endl;
		return false;
	}

	q = new LinkNode<T>(value, p->link);
	p->link = q;
	if(p == tail) //在表尾进行插入操作
		tail = q;
	return true;
}

// 2.10
template<class T>
bool LinkList<T>::deletePos(const int i)
{
	LinkNode<T> *p, *q;
	if((p = setPos(i - 1)) == NULL || p == tail) //待删除点不存在
	{
		cout << "非法删除点" << endl;
		return false;
	}

	q = p->link; //q为真正待删除点
	if(q == tail) //删除点为表尾，修改尾指针
	{
		tail = p;
		p->link = NULL;
		delete q;
	}
	else if(q != NULL) //删除结点q，并修改指针
	{
		p->link = q->link;
		delete q;
	}
	return true;
}


template<class T>
void LinkList<T> ::display(){
    LinkNode<T> *tmp = head->link;
    while(tmp!=NULL){
        cout << tmp->data << endl;
        tmp = tmp->link;
    }
    tmp = NULL;
}

// 2.11
template<class T>
class DLLNode
{
	public:
		T data; //保存结点元素的内容
		DLLNode<T> *next; //指向后继结点的指针
		DLLNode<T> *prev; //指向前驱结点的指针

		DLLNode(const T info, DLLNode<T> *prevVal = NULL, DLLNode<T> *nextVal = NULL) //构造函数
		{
			data = info;
			prev = prevVal;
			next = nextVal;
		}
		DLLNode(DLLNode<T> *prevVal = NULL, DLLNode<T> *nextVal = NULL) //给定前后指针的构造函数
		{
			prev = prevVal;
			next = nextVal;
		}
};

//测试类
class Student{
    private:
        int id;
        string name;
    public:
        Student(){
        }
        Student(int id, string name){
            this->id = id;
            this->name = name;
        }
        int getId(){
            return this->id;
        }
        void setId(int id){
            this->id = id;
        }
        string getName(){
            return this->name;
        }
        void setName(string name){
            this->name = name;
        }
        friend ostream & operator<<(ostream &out, Student &obj){
            cout << "id: " << obj.id << " ,name: " << obj.name << endl;
            return out;
        }
};

//测试主函数
int main(){
    Student s[5] = {Student(1, "zhangsan"), Student(2, "lisi"),
                    Student(3, "zhaowu"), Student(4, "wangliu"), Student(5, "wuqi")};
    LinkList<Student> *l = new LinkList<Student>();
    l->insertPos(0, s[0]);
    l->insertPos(1, s[1]);
    l->deletePos(0);
    l->display();
    return 0;
}
