/**
 * Create two child process of a parent process
 * Print process id's of each
 */
#include <stdio.h>
#include <unistd.h>
int main()
{
    int pid = fork();
    if (pid == 0)
    {
        printf("This is a child process having id %d\n", getpid());
    }
    else{
        
        int pid2 = fork();
        if(pid == 0)
        {
            printf("This is a child process having pid %d\n", getpid());
        }
        else{
            printf("This is a parent process having id %d\n", getpid());
        }
    }
    return 0;
}