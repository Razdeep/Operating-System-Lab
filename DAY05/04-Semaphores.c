/**
 * Explanation:
 * @TODO
 *  
 */
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int shared_variable;
sem_t my_sem;
void *fun1()
{
    int x;
    sem_wait(&my_sem);
    x = shared_variable;
    x++;
    sleep(2);
    shared_variable = x;
    sem_post(&my_sem);
}
void *fun2()
{
    int x;
    sem_wait(&my_sem);
    x = shared_variable;
    x++;
    sleep(2);
    shared_variable = x;
    sem_post(&my_sem);
}
int main()
{
    sem_init(&my_sem, 0, 1);
    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, &fun1, NULL);
    pthread_create(&thread_2, NULL, &fun2, NULL);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    return 0;
}