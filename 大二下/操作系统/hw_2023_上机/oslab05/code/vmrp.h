#include <malloc.h>
#include <iomanip>
#include <iostream>
using namespace std;
class Replace {
   public:
    Replace();
    ~Replace();
    void InitSpace(char* MethodName);  // 初始化页号记录
    void Report(void);                 // 报告算法执行情况
    void Fifo(void);                   // 先进先出算法
    void Lru(void);                    // 最近最旧未用算法
    void Clock(void);                  // 时钟(二次机会)置换算法
    void Eclock(void);                 // 增强二次机会置换算法
    void Lfu(void);                    // 最不经常使用置换算法
    void Mfu(void);                    // 最经常使用置换算法
   private:
    int* ReferencePage;  // 存放要访问到的页号
    int* EliminatePage;  // 存放淘汰页号
    int* PageFrames;     // 存放当前正在实存中的页号
    int PageNumber;      // 访问页数int
    int FrameNumber;     // 实存帧数
    int FaultNumber;     // 失败页数
};