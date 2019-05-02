/**
 * Exercise #1
 * 
 * Write a program to display last 10 characters of a file using system calls
 * 
 */
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
	int file_descriptor = open("abc.txt", O_RDONLY, 0777);
	char buffer[100];
	int last = read(file_descriptor, buffer, 10);
	buffer[last] = '\0';
	write(0, buffer, strlen(buffer));
	return 0;
}
