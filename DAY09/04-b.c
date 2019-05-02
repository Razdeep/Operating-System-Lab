/**
 * Write a program to simulate deadlock for two threads and two resources
 * 
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
pthread_mutex_t lock1, lock2;
void* process1()
{
	pthread_mutex_lock(&lock1);
	printf("In process1\n");
	pthread_mutex_lock(&lock2);
	printf("If this statement prints it is not is deadlock\n");
	pthread_mutex_unlock(&lock1);
	pthread_mutex_unlock(&lock2);
}
void* process2()
{
	pthread_mutex_lock(&lock2);
	printf("In process2\n");
	pthread_mutex_lock(&lock1);
	printf("Not in deadlock\n");
	pthread_mutex_unlock(&lock2);
	pthread_mutex_unlock(&lock1);
}
int main()
{
	pthread_mutex_init(&lock1, 0);
	pthread_mutex_init(&lock2, 0);
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, &process1, NULL);
	pthread_create(&thread2, NULL, &process2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
