#include <pthread.h>
#include <stdio.h>
int sum = 0;
void thread(void) {
    int i;
    for (i = 0; i < 1000000; i++)
        sum += 1;
}
int main(void) {
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, thread, NULL);
    pthread_create(&tid2, NULL, thread, NULL);
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    printf("1000000 + 1000000 = % d\n", sum);
    return (0);
}