/**
 * Race condition using threads
 * Explanation: 
 * @TODO
 * 
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared_variable = 0;

void *process1()
{
    int x = shared_variable;
    x++;
    sleep(1);
    shared_variable = x;
}
void *process2()
{
    int x = shared_variable;
    x--;
    sleep(1);
    shared_variable = x;
}
int main(int argc, const char **argv)
{
    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, &process1, NULL);
    pthread_create(&thread_2, NULL, &process2, NULL);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    printf("Shared variable = %d\n", shared_variable);
    return 0;
}