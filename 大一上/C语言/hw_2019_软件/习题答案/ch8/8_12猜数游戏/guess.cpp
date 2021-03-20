// 猜字游戏 
#include <iostream.h>
#include <stdlib.h>    // 调用rand()，srand()
#include <time.h>      // 调用函数time( )所需头文件
int main()
{
 	int iMagic;     // 被猜数
 	int iGuess;     // 猜测数
 	int iCounter = 0; // 猜测次数

 	cout<<"====This is a Number Guess Game!====\n";

    //生成被猜数的值 
    srand(time(0));         //用机器当前时间作为随机数种子
 	iMagic = rand()%100+1; //产生1~100内的随机数

	do{	
        cout<<"Please input a number between 1 and 100: ";
		cin>>iGuess;

		iCounter++;  //计数器增1
	    //判断猜测数与答案的大小
		if( iGuess>iMagic )
		{
		  cout<<"Wrong!Too large!"<<endl;
		}
		else if( iGuess<iMagic  )
		{
		    cout<<"Wrong!Too Small!"<<endl;
		}		
	} while(iGuess!=iMagic);

	cout<<"Win!"<<"\nYou made "<<iCounter
		<<((iCounter>1)?" times ":" time ")<<endl;    
	return 0;
}
