#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
#include <Windows.h>
#include<graphics.h>
#include<mmsystem.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

typedef long long ll;
#define endl '\n'
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define Forget_that return
#define Just_go 0
#define Endl endl
#define ednl endl
#define eldn endl
#define dnel endl
#define enndl endl
#define Ednl endl
#define Edml endl
#define llmax 9223372036854775807
#define intmax 2147483647
#define PI 3.141592653589793238462643383279502884197
using namespace std;
#pragma comment(lib,"winmm.lib")

void drawThickCircle(int x, int y, int radius, int thickness)
{
	rep(i, 0, thickness)	circle(x, y, radius + i);
}

int  main()
{
	initgraph(600, 600, EX_SHOWCONSOLE);
	setbkcolor(WHITE);	
	cleardevice();
	BeginBatchDraw();
	while (1)
	{
		DWORD beginTime = GetTickCount();
	
		setlinestyle(0, 0);
		setorigin(300, 300);

		setcolor(BLACK);
		drawThickCircle(0, 0, 280, 3);

		setfillcolor(RGB(210, 210, 210));
		fillcircle(0, 0, 275);   //内圆

		//显示里面的线
		setlinestyle(0, 0);
		_rep(i, 1, 60) line(265 * cos(PI / 30 * i), 265 * sin(PI / 30 * i), 273 * cos(PI / 30 * i), 273 * sin(PI / 30 * i));
		setlinestyle(0, 2);
		_rep(i, 1, 12) line(265 * cos(PI / 6 * i), 265 * sin(PI / 6 * i), 273 * cos(PI / 6 * i), 273 * sin(PI / 6 * i));


		int charRadios = 240;
		settextcolor(BLACK);
		settextstyle(50, 25, _T("Courier"));
		setbkmode(TRANSPARENT);
		int textR = 230;

		_rep(i, 1, 12)
		{
			ostringstream ss;
			ss << i;
			outtextxy((int)(textR * cos(-PI / 2 + PI / 6 * i)) - 20, (int)(textR * sin(-PI / 2 + PI / 6 * i)) - 20, ss.str().c_str());
		}

		char rolexLogo[10] = "ROLEX";
		int h = textheight(rolexLogo);					
		int w = textwidth(rolexLogo);
		outtextxy(-w / 2, 50 -h / 2, rolexLogo);


		setfillcolor(RGB(0, 0, 0));
		solidcircle(0, 0, 12);   //黑色表芯
		setfillcolor(RGB(210, 0, 0));
		solidcircle(0, 0, 6);   //红色表芯

		SYSTEMTIME time;						// 定义系统时间变量
		int second;								// 秒数
		int minute;								// 分钟数
		int hour;								// 小时数
		int shizhenLength = 150;
		int fenzhenLength = 250;
		int miaozhenLength = 200;

		GetLocalTime(&time);					// 获取本地系统时间
		second = time.wSecond;					// 设置秒数		
		minute = time.wMinute;					// 设置分钟数
		hour = time.wHour;						// 设置小时数    
		setlinestyle(0, 4);
		line(0, 0, shizhenLength * cos(-PI / 2.0 + (hour % 12 + minute / 60.0 + second / 3600.0) * 2.0 * PI / 12.0),
			shizhenLength * sin(-PI / 2.0 + (hour % 12 + minute / 60.0 + second / 3600.0) * 2.0 * PI / 12.0));//画时针
		line(0, 0, fenzhenLength * cos(-PI / 2.0 + (minute + second / 60.0) * 2.0 * PI / 60.0), fenzhenLength * sin(-PI / 2.0 + (minute + second / 60.0) * 2.0 * PI / 60.0));//画时针
		setlinecolor(RED);
		line(0, 0, miaozhenLength * cos(-PI / 2.0 + 2.0 * PI / 60.0 * second), miaozhenLength * sin(-PI / 2.0 + 2.0 * PI / 60.0 * second));

		FlushBatchDraw();

		DWORD endTime = GetTickCount();
		DWORD elapsedTime = endTime - beginTime;
		if (elapsedTime < 1000 / 1)
			Sleep(1000 / 1 - elapsedTime);



	}

	//printf("现在的时间是：%2d:%2d:%2d", hour, minute, second);
	
	EndBatchDraw();

	system("pause");
	closegraph();


	Forget_that Just_go;
}