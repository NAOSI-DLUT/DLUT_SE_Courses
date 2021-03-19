//猜字游戏
#include <iostream.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	int iMagic;     // 被猜数
	int iGuess;     // 猜测数
	int iCounter=0; // 猜测次数
	char cChoice;

	cout<<"====This is a Number Guess Game!====\n";
	srand(time(0)); //用机器当前时间作为随机数种子
	iMagic = rand()%100+1; //生成被猜数的值

    do
	{
	    
		cout<<"Please input a number between 1 and 100: ";
		cin>>iGuess;

		iCounter++;
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
			cout<<"Win!"<<"\nYou made "<<iCounter<<" times."<<endl;
		    break;
		}

		cout<<"Do you want to continue the games?(y/n):";
		cin>>cChoice;
    }while(cChoice=='y'||cChoice=='Y');

	if(iCounter>10) cout<<"You lose!"<<endl;//最多猜10次
	return 0;
}

