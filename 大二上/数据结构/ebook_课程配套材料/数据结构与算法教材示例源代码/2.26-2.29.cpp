#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;
class String
{
public:
String(char *str = NULL); // 普通构造函数
String  &operator = (const String& s);//赋值函数 
String  operator +(String &other); // 拼接运算函数
String Substr(int index, int count);// 抽取字符串函数
void display(); 
~ String(); // 析构函数
private:
char *str; // 用于保存字符串
int size;

}; 
String::~String()
{ 
  delete [] str; 
} 
 void String::display() 
{
  cout<<str<<endl;
} 
 
 
//【例2.26】String串构造函数。

String::String(char * s)
{
   if(s==NULL)
  { 
    str=new char[1]; //对空字符串自动申请存放结束标志'\0'的空间 
    assert(str != '\0');     	//当开辟动态区域不成功时，运行异常，退出
    str[0]='\0'; 
  } 
else
{
	int size = strlen(s);          	//求出串的长度
	str = new char[size + 1];	//动态开辟一块空间，需要存储结束符'\0'，所以长度为size+1
	assert(str != '\0');     	//当开辟动态区域不成功时，运行异常，退出
	strcpy(str, s);            	//将初值s复制到str所指的存储空间
}
	
}
 
 //【例2.27】赋值运算符的实现。

String& String::operator = (const String &s)
{
	if (this == &s) //检查自赋值 
  { return *this; }
  
	if(size != s.size)		//长度不同，则释放本串存储空间并开辟新的空间
	{
		delete [] str;  				//释放原空间
		str = new char[s.size + 1];		//若开辟空间失败，则退出
		assert(str != '\0');
		size = s.size;
	}
	strcpy(str, s.str);
	return *this;
}

//【例2.28】拼接运算符的实现。

String String::operator + (String& s)
{
	String temp;               		//创建一个串temp
	int len;
	len = size + s.size;        		//拼接长串的长度
	delete [] temp.str;           	//释放temp创建时new申请的存储空间
	temp.str = new char[len + 1];	//为长串开辟存储空间
	//temp = new char[len + 1];	/为长串开辟存储空间
	assert(temp.str != NULL);    	//若开辟存储空间不成功，则退出
	temp.size = len;
	strcpy(temp.str, str);       	//先把本实例的私有项str存到temp
	strcat(temp.str, s.str);     	//进行字符串的拼接
	return temp;
}


//【例2.29】抽取字符串函数的实现。

String String::Substr(int index, int count)
{
	int left = size - index;	//自下标index向右计数到串尾，长度为left
	String temp;
	char *p, *q;
	if(index >= size)  			//若下标值index超过本串的实际长度，则返回空串
		return temp;
	if(count > left) 			//若count超过自index以右的子符串长度，则count变小
		count = left;
	delete [] temp.str;			//释放原来的存储空间
	temp.str = new char[count + 1];
	assert(temp.str != NULL);	//若开辟存储空间不成功，则退出
	p = temp.str;          		//p指向暂无内容的空串
	q = &str[index];       		//q指向本实例串str数组下标index处
	for(int i = 0; i < count; i++)
		*p++ = *q++;     		//将q所指的内容赋值给p，同时后移
	*p = '\0';             		//加入结束标志'\0'
	temp.size = count;
	return temp;
}

int main()
{
	//测试2.26 
	String str1("Love"), str2("China"),str3,str4;
	str1.display();
	
	//测试2.27
	str3=str2;
	str3.display();
	//测试2.28
	str3=str1+str3;
	str3.display(); 
	//测试2.29
	str3.Substr(3,5).display();
	
	return 0;
 } 
