/**
 * Write a c program that creates three threads. You need to
 * maintain the order of execution as T2, T1, T3
 */
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
void *process1()
{
    sleep(1);
    printf("Process 1\n");
}
void *process2()
{
    printf("Process 2\n");
}
void *process3()
{
    sleep(2);
    printf("Process 3\n");
}
int main(int argc, const char **argv)
{
    pthread_t thread1, thread2, thread3;
    pthread_create(&thread1, NULL, &process1, NULL);
    pthread_create(&thread2, NULL, &process2, NULL);
    pthread_create(&thread3, NULL, &process3, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    return 0;
}