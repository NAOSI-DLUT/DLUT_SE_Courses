#include <stdio.h>
#include <sys/types.h>
// #include <unistd.h>
#include <stdlib.h>

int value = 5;  // where?

// 定义全局变量，被后续创建的两个进程共享

int main() {
    int i;  // where?
    // 定义局部变量
    pid_t pid;
    for (i = 0; i < 2; i++) {  // How many new processes and printfs£¿
        pid = fork();
        if (pid == 0) {
            value += 15;
            printf("Child: value = %d\n", value);
        } else if (pid > 0) {
            wait(NULL);  // 使父进程等待子进程结束
            printf("PARNET: value = %d\n", value);
            exit(0);  // Notice£ºWhat will happen with or without this line?
            //   使父进程正常退出返回0，没有的话父进程会继续执行
        }
    }
}
