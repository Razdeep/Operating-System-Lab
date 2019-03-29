/**
 * ------------------
 *  SET A Question 2
 * ------------------
 * Create a scenario where there are three threads -
 * One is writing the value of the shared variable
 * and the other two are reading the value of the shared
 * variable. Whne thread is writinh, no thrad is allowed to
 * read and there can be concurrent reads by 2 threads.
 * Synchronize the threads.
 * 
 * NOTE: Compile with `gcc -lpthread`
 * 
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared_variable = 0;

pthread_mutex_t mutex1, mutex2;

void *readProcess1()
{

	pthread_mutex_lock(&mutex1);

	int x = shared_variable;
	sleep(1);
	printf("In read process1, Read value of shared variable is %d\n", x);

	pthread_mutex_unlock(&mutex1);
}
void *readProcess2()
{
	pthread_mutex_lock(&mutex2);
	int x = shared_variable;
	sleep(1);
	printf("In read process2, Read value of shared variable is %d\n", x);
	pthread_mutex_unlock(&mutex2);
}
void *writeProcess()
{
	pthread_mutex_lock(&mutex1);
	pthread_mutex_lock(&mutex2);
	int x = shared_variable;
	sleep(1);
	x++;
	shared_variable = x;
	printf("In write process, Updated the shared variable to %d\n", x);
	pthread_mutex_unlock(&mutex1);
	pthread_mutex_unlock(&mutex2);
}
int main()
{
	pthread_mutex_init(&mutex1, 0);
	pthread_mutex_init(&mutex2, 0);
	pthread_t thread1, thread2, thread3;

	// pthread_create(&thread2, NULL, &readProcess1, NULL);
	// pthread_create(&thread3, NULL, &readProcess2, NULL);
	printf("Initial value of shared variable is %d\n", shared_variable);
	pthread_create(&thread1, NULL, &writeProcess, NULL);
	pthread_create(&thread2, NULL, &readProcess1, NULL);
	pthread_create(&thread3, NULL, &readProcess2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	return 0;
}
