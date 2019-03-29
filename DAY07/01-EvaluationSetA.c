/**
 * ------------------
 *  SET A Question 1
 * ------------------
 * A process wants to do 2 tasks
 * 1. Create a file
 * 2. Receive input from user and save into the newly
 *    created file.
 *
 * Achieve both tasks by creating separate thread
 *
 * NOTE: Compile with `gcc -lpthread`
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <fcntl.h>
#include <string.h>
const int SIZE = 50;
void *process1()
{
	printf("In process1\n");
	int file_descriptor = open("rrc.txt", O_CREAT, 0777);
}
void *process2()
{
	sleep(1);
	printf("In process2\n");
	char text[SIZE];
	printf("Enter some text ");
	scanf("%s", text);
	//printf("@DEBUG TEXT TO BE SAVED %s", text);
	int file_descriptor = open("rrc.txt", O_RDWR, 0777);
	write(file_descriptor, text, strlen(text));
	close(file_descriptor);
}
int main(int argc, const char **argv)
{
	pthread_t thread1, thread2;
	pthread_create(&thread1, NULL, &process1, NULL);
	pthread_create(&thread2, NULL, &process2, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	return 0;
}
