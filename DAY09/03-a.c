/**
 * Exercise #3
 * 
 * Write a program to send a message from parent process to child process
 * using pipes
 * 
 * Pitfall:
 *  Never interchange pipe indices
 * 
 * Quickfix:
 *  Write on the fd[1], and read from fd[0]
 */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX 100

int main(int argc, const char** argv)
{
    int fd[2];
    pipe(fd);
    char buffer[MAX];
    pid_t id = fork();
    if (id > 0){
        close(fd[0]);
        printf("Passing value to child");
        write(fd[1], "buffer", sizeof(char) * strlen("buffer"));
        wait(NULL);
    }
    else if (id == 0)
    {
        close(fd[1]);
        int last = read(fd[0], buffer, MAX);
        buffer[last] = '\0';
        write(1, buffer, strlen(buffer));
        // printf("%s\n", buffer);
    }
    
    return 0;
}