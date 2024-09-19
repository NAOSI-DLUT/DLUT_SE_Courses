/*
 * Filename : dask.h
 * copyright : (C) 2006 by zhonghonglie
 * Function : 声明磁盘移臂调度类
 */
#include <malloc.h>
#include <iostream>
class DiskArm {
   public:
    DiskArm();
    ~DiskArm();
    void InitSpace(char* MethodName);  // 初始化寻道记录
    void Report(void);                 // 报告算法执行情况
    void Fcfs(void);                   // 先来先服务算法
    void Sstf(void);                   // 最短寻道时间优先算法
    void Scan(void);                   // 电梯调度算法
    void CScan(void);                  // 均匀电梯调度算法
    void Look(void);                   // LOOK 调度算法
   private:
    int* Request;         // 磁盘请求道号
    int* Cylinder;        // 工作柱面道号号
    int RequestNumber;    // 磁盘请求数
    int CurrentCylinder;  // 当前道号
    int SeekDirection;    // 磁头方向
    int SeekNumber;       // 移臂总数
    int SeekChang;        // 磁头调头数
};
