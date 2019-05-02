/**
 * Exercise #2
 * 
 * Write a program to copy contents of a file to another using system calls
 * 
 */

#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#define MAX 50
int main(int argc, const char** argv)
{
    char buffer[MAX];
    int file_descriptor_1 = open("abc.txt", O_RDONLY, 0777);
    int last = read(file_descriptor_1, buffer, MAX);
    buffer[last] = '\0';
    int file_descriptor_2 = open("xyz.txt", O_CREAT | O_RDWR, 0777);
    write(file_descriptor_2, buffer, strlen(buffer));
    close(file_descriptor_1);
    close(file_descriptor_2);
    return 0;
}