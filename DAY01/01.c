/**
 * Reading from file and displaying on the screen
 * 
 * Argument Constant for open() are
 * O_RDONLY
 * O_RDWR
 * O_CREAT
 * O_APPEND
 * O_TRUNC
 */
#include <unistd.h>
#include <fcntl.h>
int main()
{
    char str[50];
    int file_descriptor = open("file.txt", O_RDONLY, 0777);
    read(file_descriptor, str, 5);
    write(0, str, 5);
    read(file_descriptor, str, 5);
    write(0, str, 5);
    write(0, "\n", 1);
    return 0;
}
