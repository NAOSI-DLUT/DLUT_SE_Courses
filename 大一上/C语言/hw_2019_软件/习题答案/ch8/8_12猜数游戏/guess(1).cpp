//猜字游戏2
#include <iostream.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int iMagic;     // 被猜数
	int iGuess;     // 猜测数
	int iCounter=0; // 猜测次数

	cout<<"====This is a Number Guess Game!====\n";
	srand(time(0)); //用机器当前时间作为随机数种子
	iMagic = rand()%100+1; //生成被猜数的值

    for(int i=0; i<10; i++) //最多猜10次
	{
	    
		cout<<"Please input a number between 1 and 100: ";
		cin>>iGuess;

		if( iGuess>iMagic )
		{
			 cout<<"Wrong!Too large!"<<endl;
		}
		else if( iGuess<iMagic  )
		{
			cout<<"Wrong!Too Small!"<<endl;
		}
		
        if(iGuess==iMagic)
		{
			cout<<"Win!"<<"\nYou made "<<i<<" times."<<endl;
		    break;
		}
    }

	if(i==10) cout<<"You lose!"<<endl;
	return 0;
}

