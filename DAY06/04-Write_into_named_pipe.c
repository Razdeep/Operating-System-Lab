#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main(int argc, const char **argv)
{
    int res, n;
    res = open("fifo1", O_WRONLY);
    write(res, "written\n", strlen("written\n"));
    printf("Process %d finished\n", getpid());
    return 0;
}