#include <iostream>
#define EMPTY -1   //设置删除标志
using namespace std;

template<class Key, class T> //Key为关键码的类型，T为存储在HashTable中的元素的类型
class HashTable
{
private:
	T* HT;
	int maxSize;             //存储数据的最大个数 
	int currentSize;         //存储数据的当前个数 
	int probe(Key k,int i) const{return k%maxSize+i;};
										//探查函数，i为探查的次数编号
	int hash(Key k) const{return k%maxSize;};			//散列函数
public:
	HashTable(int size)                                //构造函数 
	{
		maxSize=size;
		currentSize=0;
		HT=new T[maxSize];
	}
	~HashTable(){delete []HT;}                   //析构函数 
	bool hashInsert(const T& item)const ;	    //插入数据
	bool hashSearch(const Key& k);	            //检索数据
	bool hashDelete(const Key& k);				//删除数据
	//bool empty();
	T * getHT(){return HT;}
};
template <class Key, class T>
bool HashTable<Key,T>::hashInsert(const T& item) const
{
	int flag=0;
	int home=0;									//存储的初始探查位置
	int i=0;									//探查的序列编号
	int pos=home=hash(item);
	while(HT[pos]!=EMPTY)                       //EMPTY是散列表当前位置为空的标记 
	{
		if(HT[pos]==item){
			flag = 1;       	//发现重复，设置标记 
			break;
			}					       
		i++;
		pos=(probe(item,i))%maxSize;	//probe生成探查步长
	}
	if(flag == 1){
		cout<<"该数据已存在，不需插入"<<endl;
	}
	else{	
	HT[pos]=item;                      //更新表中位置信息 
	cout<<"位置是第"<<pos<<endl; 
	} 
	return true;
}
template <class Key, class T>
bool HashTable<Key,T>::hashSearch(const Key& k)
{
	int home=hash(k);
	int i=0;
	int pos=home;
	do
	{
		cout<<"正在检索的位置为"<<pos<<endl; 
		if(HT[pos]==k)                 //当前位置存储数据为待查数据 
			return true;
		i++;
		pos=(probe(k,i))%maxSize;   //利用探测步长继续寻找 
	
	}while((HT[pos]!=EMPTY)&&(HT[pos]!=home));
	return false;
}
template <class Key, class T>
bool HashTable<Key,T>::hashDelete(const Key& k)
{
	int home=hash(k);       
	int i=0;
	int pos=home;
	do
	{
		if(HT[pos]==k)
		{	
			HT[pos]=EMPTY; 			
		    cout<<"删除成功！"<<endl;
			return true;
		}
		else{
	     	i++;
	     	pos=(probe(k,i))%maxSize;
	    }
		
	}while(HT[pos]!=EMPTY);
	cout<<"表中没有该数据！"<<endl;
	return false;
}
int main()
{
    HashTable<int, int> ht(23);
    int *HT = ht.getHT();
	for(int i = 0;i < 23 ;i++){
		HT[i] = EMPTY;
	}
    cout<<"输入10个数"<<endl;
     int temp;
    for(int i=0;i<10;++i){
        cin>>temp;
        ht.hashInsert(temp);
    }
    
    cout<<"需要删除的数"<<endl;
    int tar;
    cin>>tar;
    ht.hashDelete(tar);
    
    
    cout<<"需要查找的数"<<endl;
    int target;
    cin>>target;
    bool s=ht.hashSearch(target);
    if(s == 0)
     	cout<<"未找到数据！"<<endl;
	else
		cout<<"找到数据！"<<target<<endl;

    return 0;
}


