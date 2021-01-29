#include<iostream>
#include<assert.h>
#include<string.h>
using namespace std;

//【例2.30】朴素的字符串模式匹配算法。
int NaiveStrMatching(const string & T, const string & P)
{
	int p = 0;                		//模式的下标变量
	int t = 0;                		//目标的下标变量
	int plen = P.length();  	//模式的长度
	int tlen = T.length();  	//目标的长度
	if(tlen < plen)           	//如果目标比模式短，匹配无法成功
		return -1;
	while(p< plen && t < tlen)	//反复比较对应字符进行匹配
	{
		if(T[t] == P[p])
		{
			p++;
			t++;

		}
		else
		{
			t = t - p + 1;
			p = 0;
		}
	}
	if(p >= plen)
		return (t - plen);
	else
		return -1;
}


//【例2.31】计算特征向量的算法。

int * Next(string P)
{
	int m = P.size();         		//模式P的长度
	assert(m > 0);                	//若m = 0，则退出
	int * N = new int[m];          	//在动态存储区开辟新的数组
	assert(N != 0);
	N[0] = 0;
	for(int i = 1; i < m; i++)    	//对P的每一个位置进行分析
	{
		int k = N[i - 1];         	//第i-1位置的最长前缀串长度
		while(k > 0 && P[i] != P[k])
			k = N[k - 1];
		if(P[i] == P[k])
			N[i] = k + 1;
		else
			N[i] = 0;
	}
	return N;
}

//【例2.32】KMP模式匹配算法。



int KMPStrMatching(string T, string P, int * N, int startIndex)
{
	int lastIndex = T.size() - P.size();
	if((lastIndex - startIndex) < 0) //若startIndex过大，则无法匹配成功
		return (-1);
	int i;                         	//指向T内部字符的游标
	int j = 0;                    	//指向P内部字符的游标
	for(  i = startIndex;i < T.size(); i++)
	{
		while(P[j] != T[i] && j > 0)
			j = N[j - 1];               
		if(P[j] == T[i])		//当P的第j位和T的第i位相同时，则继续
			j++;
		if(j == P.size())
			return (i -j + 1);	//匹配成功，返回该T子串的开始位置
	}
	return (-1);
}


int main()
{
	string s1="acabaabaabcacaabc";
	string s2="abaabcac";
	//测试2.30
	cout<<NaiveStrMatching(s1,s2)<<endl;
        //测试2.31
	int *k=Next(s2);
       //测试2.32
	cout<<KMPStrMatching(s1,s2,k,2)<<endl;
	return 0;
}
