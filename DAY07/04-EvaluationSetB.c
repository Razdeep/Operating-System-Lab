/**
 * ------------------
 *  SET B Question 2
 * ------------------
 * Create a scenario to simulate deadlock in a system which involves
 * 3 threads and 3 resources
 * 
 * NOTE: Compile with `gcc -lpthread`
 * 
 */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

pthread_mutex_t mutex1, mutex2, mutex3;

void *process1()
{
    pthread_mutex_lock(&mutex1);
    printf("Lock 1 acquired thread1\n");
    sleep(1);
    pthread_mutex_lock(&mutex2);
    printf("Lock 2 acquired by thread1\n");
    sleep(1);
    pthread_mutex_lock(&mutex3);
    printf("Lock 3 acquired by thread1\n");
    sleep(1);
    pthread_mutex_unlock(&mutex1);
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex3);
}
void *process2()
{
    pthread_mutex_lock(&mutex2);
    printf("Lock 2 acquired by thread2\n");
    sleep(1);
    pthread_mutex_lock(&mutex3);
    printf("lock 3 acquired by thread2\n");
    sleep(1);
    pthread_mutex_lock(&mutex1);
    printf("Lock 1 acquired by thread2\n");
    sleep(2);
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex3);
    pthread_mutex_unlock(&mutex1);
}
void *process3()
{
    pthread_mutex_lock(&mutex3);
    printf("Lock 3 acquired by thread3\n");
    sleep(1);
    pthread_mutex_lock(&mutex2);
    printf("lock 2 acquired by thread3\n");
    sleep(1);
    pthread_mutex_lock(&mutex1);
    printf("lock 1 by thread 3\n ");
    sleep(1);
    pthread_mutex_unlock(&mutex3);
    pthread_mutex_unlock(&mutex2);
    pthread_mutex_unlock(&mutex1);
}
int main()
{
    pthread_t thread1, thread2, thread3;
    pthread_mutex_init(&thread1, NULL);
    pthread_mutex_init(&thread2, NULL);
    pthread_mutex_init(&thread3, NULL);
    pthread_create(&thread1, NULL, &process1, NULL);
    pthread_create(&thread2, NULL, &process2, NULL);
    pthread_create(&thread3, NULL, &process3, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    return 0;
}
