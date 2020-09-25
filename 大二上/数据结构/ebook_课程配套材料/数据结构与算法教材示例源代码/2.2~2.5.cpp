#include <iostream>
using namespace std;

// 2.2
template <class T>
class List
{
	void Clear(); //置空线性表
	bool IsEmpty(); //线性表为空时,返回true
	bool Append(const T value);	//在表尾添加元素value,表的长度增加1
	bool Insert(const int p, const T value); //在位置p插入元素value,  表的长度增加1
	bool Delete(const int p); //删除位置p上的元素,表的长度减1
	bool GetValue(const int p, T& value); //把位置p上的元素值返回到变量value中
	bool SetValue(const int p, const T value); //把位置p的元素值修改为value
	bool GetPos(int &p, const T value); //把值为value的元素的位置返回到变量p中
};

// 2.3
template <class T> //线性表的元素类型为T
class ArrayList : public List<T> //定义顺序表ArrayList
{
	public: //顺序表的运算集
		ArrayList(const int size) //创建顺序表,表长为最大长度
		{
		    if(size < 1){ //llz
                cout << "Size must be greater than 0";
                throw -1;
		    }
			maxSize = size;
			arrayList = new T[maxSize];
			curLen = 0;
			position = 0;
		}

		~ArrayList() //析构函数,消除ArrayList的实例
		{
			delete [] arrayList;
		}

		void clear() //清空顺序表
		{
			delete [] arrayList;
			curLen = 0;
			position = 0;
			arrayList = new T[maxSize];
		}

		int Length(); //返回顺序表长度，llz
		bool Append(const T value); //在表尾添加元素value,表的长度增加1
		bool Insert(const int p, const T value); //在位置p插入元素value,表的长度增加1
		bool Delete(const int p); //删除位置p上的元素,表的长度减1
		bool GetValue(const int p, T& value); //把位置p上的元素值返回到变量value中
		bool SetValue(const int p, const T value); //把位置p的元素值修改为value
		bool GetPos(int &p, const T value); //把值为value的元素的位置返回到变量p中

	private: //私有变量
		T *arrayList; //存储顺序表的实例
		int maxSize; //顺序表实例的最大长度
		int curLen; //顺序表实例的当前长度
		int position; //当前处理位置
};

template<class T>
int ArrayList<T> :: Length(){ //返回Arraylist长度
    return curLen;
}

template<class T>
bool ArrayList<T> :: GetValue(const int p, T& value){
    if(p < 0 || p > curLen)
    {
        cout << "GetValue position is illegal" << endl;
        return false;
    }
    value = arrayList[p];
}

// 2.4
template <class T> //顺序表的元素类型为T
bool ArrayList<T> :: Insert(const int p, const T value)
{
	if(curLen >= maxSize) //检查顺序表是否溢出
	{
		cout << "The List is overflow" << endl;
		return false;
	}

	if(p < 0 || p > curLen) //检查插入位置是否合法
	{
		cout << "Insertion point is illegal" << endl;
        return false; //llz
	}

	for(int i = curLen; i > p; i--)
	{
		arrayList[i] = arrayList[i-1]; //从表尾curLen-1处向后移动一个位置直到插入位置p
	}
	arrayList[p] = value; //位置p处插入新元素
	curLen++; //表的实际长度增加1
	return true;
}

// 2.5
template <class T> //顺序表的元素类型为T
bool ArrayList<T> :: Delete(const int p)
{
	if(curLen <= 0) //检查顺序表是否为空
	{
		cout << "No element to delete" << endl;
		return false;
	}

	if(p < 0 || p > curLen -1) //检查删除位置的合法性
	{
		cout << "Deletion is illegal" << endl;
		return false;
	}

	for(int i = p; i < curLen - 1; i++)
	{
		arrayList[i] = arrayList[i+1]; //从删除位置p开始每个元素向前移动一个位置直到表尾
	}
	curLen--; //表的实际长度减1
	return true;
}

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
    try{
        ArrayList<Student> l(10);
        l.Insert(0, s[0]);
        l.Insert(1, s[1]);
        l.Insert(2, s[2]);
        l.Delete(1);
        for(int i = 0; i < l.Length(); i++){
            Student stu;
            l.GetValue(i, stu);
            cout << stu;
        }
    }catch(int e){

    }
    return 0;
}
