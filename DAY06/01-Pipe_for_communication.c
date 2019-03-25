/**
 * Using pipes for communication
 * 
 */
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#include <string.h>

int main(int argc, const char** argv)
{
    int fd[2], n;
    char buffer[100];
    pid_t p;
    pipe(fd);
    p = fork();
    if(p>0)
    {
        close(fd[0]);
        printf("Passing value to child\n");
        write(fd[1], "Hello\n", strlen("Hello\n"));
        wait(NULL);
    }
    else{
        close(fd[1]);
        n = read(fd[0], buffer, 100);
        write(1, buffer, n);
    }
    return 0;
}