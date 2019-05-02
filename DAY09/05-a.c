/**
 * Create two threads, first thread is going to create a file
 * and second will take input from the user and store it into
 * into the file
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <fcntl.h>

void *process1()
{
    open("qwerty.txt", O_CREAT, 0777);
}
void *process2()
{
	sleep(1);
	int file_descriptor = open("qwerty.txt", O_RDWR, 0777);
	printf("Enter a text ");
	char buffer[100];
	scanf("%s", buffer);
	write(file_descriptor, buffer, strlen(buffer));
}
int main()
{
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, &process1, NULL);
	pthread_create(&thread2, NULL, &process2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
