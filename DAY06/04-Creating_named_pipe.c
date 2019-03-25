/**
 * Creating Named pipe
 * 
 */
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h> // for mkfifo
int main(int argc, const char **argv)
{
    int res;
    res = mkfifo("fifo1", 0777);
    printf("Named pipe created\n");
    return 0;
}