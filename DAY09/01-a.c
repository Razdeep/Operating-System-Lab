/**
 * Exercise #1
 *
 * Write a program to implement solution of race condition using semaphores
 *
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
int shared_variable = 0;
sem_t mysem;
void *process1()
{
    sem_wait(&mysem);
    int buffer = shared_variable;
    sleep(1);
    shared_variable = buffer + 1;
    sem_post(&mysem);
}
void *process2()
{
    sem_wait(&mysem);
    int buffer = shared_variable;
    sleep(1);
    shared_variable = buffer - 1;
    sem_post(&mysem);
}
int main(int argc, const char **argv)
{
    sem_init(&mysem, 0, 1);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, &process1, NULL);
    pthread_join(thread1, NULL);
    pthread_create(&thread2, NULL, &process2, NULL);
    pthread_join(thread2, NULL);
    printf("The value of the shared variable is %d\n\n", shared_variable);
    return 0;
}
