/**
 * Reading from named pipe
 */
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
int main(int argc, const char ** argv)
{
    int res, n;
    char buffer[100];
    res = open("fifo1", O_RDONLY);
    n = read(res, buffer, 100);
    printf("Total bytes read : %d\n", n);
    printf("%s was passed to me\n", buffer);
    printf("Process %d finished", getpid());
    return 0;
}