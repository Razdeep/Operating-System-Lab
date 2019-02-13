/**
 * WAP to copy last 4 character from file.txt to a newfile.txt
 */
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main()
{
    const int MAX = 50;
    char buffer[MAX];
    size_t file_descriptor = open("file.txt", O_RDONLY, 0777);
    lseek(file_descriptor, -5, SEEK_END);
    read(file_descriptor, buffer, 4);
    file_descriptor = open("newfile.txt", O_RDWR, 0777);
    write(file_descriptor, buffer, strlen(buffer));
    return 0;
}