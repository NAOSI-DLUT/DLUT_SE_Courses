#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <graphics.h>
#include <mmsystem.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include <math.h>
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
#pragma comment(lib, "winmm.lib")


int numScore = 0;

struct BALL
{
    int r;
    int x;
    int y;
    int vx;
    int vy;
}ball;


struct BLOCK
{
    int x;
    int y;
    int length;
    int height;
    bool isright;
    bool isleft;
}block;

void isGuangdong(BALL& b)
{
    if (b.x <= b.r  )
    {
        b.vx *= -1;
        b.x = b.r;
    }
    else if (b.x + b.r >= 800)
    {
        b.x = 800 - b.r;
        b.vx *= -1;
    }
        

    else if (b.y <= b.r)
    {
        b.y = b.r;
        b.vy *= -1;
    }
    else if ((b.y + b.r + block.height >= 600 && b.x >= block.x && b.x <= block.x + block.length))
    {
        b.y = 600 - b.r - block.height;
        b.vy *= -1;
        numScore++;
    }


}

int main()
{
    srand(time(0));
    bool running = true;  // 主循环控制参数
    ExMessage msg;        // 消息对象
    string ss = "score : ";


    ball.x = 400, ball.y = 300;
    ball.r = 10;
    ball.vx = 10 + rand() % 10;
    ball.vy = 10 + rand() % 10;
    block.x = 350, block.y = 590;
    block.height = 10, block.length = 100;
    block.isleft = false, block.isright = false;


    initgraph(800, 600); // 初始化绘图窗口
    BeginBatchDraw();    // 开启批量绘图
    settextcolor(YELLOW);
    settextstyle(20, 0, "微软雅黑");

    ll timecnt = 0;

    // 主循环
    while (running)
    {
        DWORD beginTime = GetTickCount64(); // 记录循环开始时间
        timecnt++;

        isGuangdong(ball);
        ball.x += ball.vx / 2;
        ball.y += ball.vy / 2;

        while (peekmessage(&msg))
        {
            if (msg.message == WM_KEYDOWN)			// 按下按键处理
            {
                switch (msg.vkcode)
                {
                case 'a':
                case 'A':
                case VK_LEFT:
                    block.isleft = true;
                    break;

                case 'd':
                case 'D':
                case VK_RIGHT:
                    block.isright = true;
                    break;

                case VK_ESCAPE:
                    running = false;
                    break;
                }
            }
            if (msg.message == WM_KEYUP)			// 松开按键处理
            {
                switch (msg.vkcode)
                {
                case 'a':
                case 'A':
                case VK_LEFT:
                    block.isleft = false;
                    break;

                case 'd':
                case 'D':
                case VK_RIGHT:
                    block.isright = false;
                    break;
                }
            }
        }

        if (block.isleft && !block.isright)
            block.x -= 10;
        else if (block.isright && !block.isleft)
            block.x += 10;


        if (ball.x > 820 || ball.x < -20 || ball.y < -20 || ball.y>620)
            running = false;


        solidcircle(ball.x, ball.y, ball.r);
        solidrectangle(block.x, block.y, block.x + block.length, block.y + block.height);

        ostringstream stringScore;
        stringScore << numScore;
        string s;
        s = ss + stringScore.str();

        int scorewidth = textwidth(s.c_str());
        outtextxy(400 - scorewidth, 50, s.c_str());

        FlushBatchDraw(); // 刷新批量绘图

        DWORD endTime = GetTickCount64();          // 记录循环结束时间
        DWORD elapsedTime = endTime - beginTime; // 计算循环耗时
        if (elapsedTime < 1000 / 60)            // 按每秒60帧进行补时
            Sleep(1000 / 60 - elapsedTime);
        cleardevice();
    }

    EndBatchDraw(); // 关闭批量绘图
    closegraph();   // 关闭绘图窗口

    Forget_that Just_go;
}