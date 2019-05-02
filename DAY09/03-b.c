/**
 * Exercise #3
 * 
 * Write a program to create a child process. The parent proces print 30-34
 * and child process prints 5-9. Also both the process prints a common message.
 * 
 */
#include <stdio.h>
#include <unistd.h>
int main(int argc, const char **argv)
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("In the child process\n");
        for (int i = 5; i <= 9; i++)
            printf("%d\n", i);
    }
    else
    {
        printf("In the parent process\n");
        for (int i = 30; i <= 34; i++)
            printf("%d\n", i);
    }

    return 0;
}