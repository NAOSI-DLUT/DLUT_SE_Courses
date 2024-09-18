/*
 Filename : consumer.c
 copyright : (C) by zhanghonglie
 Function : 建立并模拟消费者进程
*/
#include "ipc.h"
int main(int argc, char* argv[]) {
    int rate;
    // 可在在命令行第一参数指定一个进程睡眠秒数，以调解进程执行速度
    if (argv[1] != NULL)
        rate = atoi(argv[1]);
    else
        rate = 3;  // 不指定为 3 秒
    // 共享内存 使用的变量
    buff_key = 101;              // 缓冲区任给的键值
    buff_num = 8;                // 缓冲区任给的长度
    cget_key = 103;              // 消费者取产品指针的键值
    cget_num = 1;                // 指针数
    shm_flg = IPC_CREAT | 0644;  // 共享内存读写权限
    // 获取缓冲区使用的共享内存，buff_ptr 指向缓冲区首地址
    buff_ptr = (char*)set_shm(buff_key, buff_num, shm_flg);
    // 获取消费者取产品指针，cget_ptr 指向索引地址
    cget_ptr = (int*)set_shm(cget_key, cget_num, shm_flg);
    // 信号量使用的变量
    prod_key = 201;  // 生产者同步信号灯键值
    pmtx_key = 202;  // 生产者互斥信号灯键值
    cons_key = 301;  // 消费者同步信号灯键值
    cmtx_key = 302;  // 消费者互斥信号灯键值
    sem_flg =
        IPC_CREAT |
        0644;  // 信号灯操作权限 //生产者同步信号灯初值设为缓冲区最大可用量
    sem_val = buff_num;
    // 获取生产者同步信号灯，引用标识存 prod_sem
    prod_sem = set_sem(prod_key, sem_val, sem_flg);
    // 消费者初始无产品可取，同步信号灯初值设为 0
    sem_val = 0;
    // 获取消费者同步信号灯，引用标识存 cons_sem
    cons_sem = set_sem(cons_key, sem_val, sem_flg);
    // 消费者互斥信号灯初值为 1
    sem_val = 1;
    // 获取消费者互斥信号灯，引用标识存 pmtx_sem
    cmtx_sem = set_sem(cmtx_key, sem_val, sem_flg);
    // 循环执行模拟消费者不断取产品
    while (1) {
        // 如果无产品消费者阻塞
        down(cons_sem);
        // 如果另一消费者正在取产品，本消费者阻塞
        down(cmtx_sem);
        // 用读一字符的形式模拟消费者取产品，报告本进程号和获取的字符及读取的位置
        sleep(rate);
        printf("%d consumer get: %c from Buffer[%d]\n", getpid(),
               buff_ptr[*cget_ptr], *cget_ptr);
        // 读取位置循环下移
        *cget_ptr = (*cget_ptr + 1) % buff_num;

        // 唤醒阻塞的消费者
        up(cmtx_sem);
        // 唤醒阻塞的生产者
        up(prod_sem);
    }
    return EXIT_SUCCESS;
}