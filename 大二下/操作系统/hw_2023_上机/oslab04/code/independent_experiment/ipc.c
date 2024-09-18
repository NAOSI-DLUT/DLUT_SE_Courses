#include "ipc.h"

// 生产消费者共享缓冲区即其有关的变量
key_t buff_key;
int buff_num;
char* buff_ptr;

// 生产者放产品位置的共享指针
key_t pput_key;
int pput_num;
int* pput_ptr;

// 消费者取产品位置的共享指针
key_t cget_key;
int cget_num;
int* cget_ptr;
int buff_num;
int pput_num;
int buff_number;
int pput_number;
int cget_number;

key_t pput_h;
key_t prod_h;
key_t pmtx_h;
key_t cons_h;
key_t cmtx_h;

key_t buff_h;
key_t cget_h;

// 生产者有关的信号量
key_t prod_key;
key_t pmtx_key;
int prod_sem;
int pmtx_sem;

// 消费者有关的信号量
key_t cons_key;
key_t cmtx_key;
int cons_sem;
int cmtx_sem;
int sem_val;
int sem_flg;
int shm_flg;
int get_ipc_id(char* proc_file, key_t key) {
    FILE* pf;                        // 定义文件指针
    int i, j;                        // 定义整型变量i和j
    char line[BUFSZ], colum[BUFSZ];  // 定义字符数组line和colum
    if ((pf = fopen(proc_file, "r")) == NULL) {  // 如果文件指针为空，则出错
        perror("Proc file not open");            // 打印错误信息
        exit(EXIT_FAILURE);                      // 退出程序
    }
    fgets(line, BUFSZ, pf);          // 读取文件的第一行
    while (!feof(pf)) {              // 如果文件没有结束
        i = j = 0;                   // 初始化i和j
        fgets(line, BUFSZ, pf);      // 读取文件的一行
        while (line[i] == ' ')       // 如果这一行是空格
            i++;                     // 则跳过这一行
        while (line[i] != ' ')       // 如果这一行不是空格
            colum[j++] = line[i++];  // 则将这一行的内容赋值给colum
        colum[j] = '\0';  // 将colum字符数组的最后一个元素赋值为空字符
        if (atoi(colum) != key)      // 如果atoi(colum)的值不等于key
            continue;                // 则跳过这一行
        j = 0;                       // 初始化j
        while (line[i] == ' ')       // 如果这一行是空格
            i++;                     // 则跳过这一行
        while (line[i] != ' ')       // 如果这一行不是空格
            colum[j++] = line[i++];  // 则将这一行的内容赋值给colum
        colum[j] = '\0';  // 将colum字符数组的最后一个元素赋值为空字符
        i = atoi(colum);  // 将colum字符数组的值转换为整数
        fclose(pf);       // 关闭文件
        return i;         // 返回整数值
    }
    fclose(pf);  // 关闭文件
    return -1;   // 返回-1
}
int down(int sem_id) {
    // 声明一个struct sembuf类型的变量buf
    struct sembuf buf;
    // 将buf.sem_op设置为-1
    buf.sem_op = -1;
    // 将buf.sem_num设置为0
    buf.sem_num = 0;
    // 将buf.sem_flg设置为SEM_UNDO
    buf.sem_flg = SEM_UNDO;
    // 如果semop函数的返回值小于0，则输出错误信息，并退出程序
    if ((semop(sem_id, &buf, 1)) < 0) {
        perror("down error ");
        exit(EXIT_FAILURE);
    }
    // 返回成功
    return EXIT_SUCCESS;
}

int up(int sem_id) {
    struct sembuf buf;
    buf.sem_op = 1;
    buf.sem_num = 0;
    buf.sem_flg = SEM_UNDO;
    if ((semop(sem_id, &buf, 1)) < 0) {
        perror("up error ");
        exit(EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}

int set_sem(key_t sem_key, int sem_val, int sem_flg) {
    int sem_id;
    Sem_uns sem_arg;

    // 测试由 sem_key 标识的信号灯数组是否已经建立
    if ((sem_id = get_ipc_id("/proc/sysvipc/sem", sem_key)) < 0) {
        // semget 新建一个信号灯,其标号返回到 sem_id
        if ((sem_id = semget(sem_key, 1, sem_flg)) < 0) {
            perror("semaphore create error");
            exit(EXIT_FAILURE);
        }
        // 设置信号灯的初值
        sem_arg.val = sem_val;
        if (semctl(sem_id, 0, SETVAL, sem_arg) < 0) {
            perror("semaphore set error");
            exit(EXIT_FAILURE);
        }
    }
    return sem_id;
}

char* set_shm(key_t shm_key, int shm_num, int shm_flg) {
    int i, shm_id;
    char* shm_buf;

    // 测试由 shm_key 标识的共享内存区是否已经建立
    if ((shm_id = get_ipc_id("/proc/sysvipc/shm", shm_key)) < 0) {
        // shmget 新建 一个长度为 shm_num 字节的共享内存,其标号返回到 shm_id
        if ((shm_id = shmget(shm_key, shm_num, shm_flg)) < 0) {
            perror("shareMemory set error");
            exit(EXIT_FAILURE);
        }
        // shmat 将由 shm_id 标识的共享内存附加给指针 shm_buf
        if ((shm_buf = (char*)shmat(shm_id, 0, 0)) < (char*)0) {
            perror("get shareMemory error");
            exit(EXIT_FAILURE);
        }
        for (i = 0; i < shm_num; i++)
            shm_buf[i] = 0;
        // 初始为 0
    }
    // shm_key 标识的共享内存区已经建立,将由 shm_id 标识的共享内存附加给指 针
    // shm_buf
    if ((shm_buf = (char*)shmat(shm_id, 0, 0)) < (char*)0) {
        perror("get shareMemory error");
        exit(EXIT_FAILURE);
    }
    return shm_buf;
}

int set_msq(key_t msq_key, int msq_flg) {
    int msq_id;
    // 测试由 msq_key 标识的消息队列是否已经建立
    if ((msq_id = get_ipc_id("/proc/sysvipc/msg", msq_key)) < 0) {
        // msgget 新建一个消息队列,其标号返回到 msq_id
        if ((msq_id = msgget(msq_key, msq_flg)) < 0) {
            perror("messageQueue set error");
            exit(EXIT_FAILURE);
        }
    }
    return msq_id;
}