/*判断某人是否属于肥胖体型，常使用"体指数"指标*/
#include<stdio.h>
int main()
{
	float fWeight;  /*体重*/
	float fHeight;  /*身高*/
	float fT;

	printf("Input your weight(m):");
	scanf("%f",&fWeight);
    printf("Input your Height(kg):");
	scanf("%f",&fHeight);

	fT=fWeight/(fHeight*fHeight);

	/*用简单if语句实现单选择结构*/
	if(fT<18)
	{
			printf("Lower weight!\n");
	}
	if(fT>=18 && fT<25)
	{
		printf("Standard weight!\n");
	}
	if(fT>=25 && fT<27)
	{
		printf("Highter weight!\n");
	}
	if(fT>=27)
	{
	    printf("Too fat!!\n");
	}
/*
	/*用简单if嵌套语句实现双选择结构*/
	if(fT<27)
	{
		if(fT<25)
		{
			if(fT<18)
				cout<<"Lower weight!"<<endl;
		
	    	else
			{
			    cout<<"Standard weight!"<<endl;
			}
		}
	   else
	   {
		cout<<"Highter weight!"<<endl;
	   }
	}
	else
	{
		cout<<"Too fat!!"<<endl;
	}

	/*用if-else语句实现多择结构*/
	if(fT<18)
	{
		cout<<"Lower weight!"<<endl;
	}
	else if (fT<25)
	{
		cout<<"Standard weight!"<<endl;
	}
	else if(fT<27)
	{
		cout<<"Highter weight!"<<endl;
	}
	else
	{
		cout<<"Too fat!!"<<endl;
	}
*/	
	return 0;
}