/**
 * WAP to demonstrate an orphan process
 * Idea: Make the child sleep, by that time parent terminates.
 */
#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("\nNo child");
    }
    else if (pid == 0)
    {
        sleep(10);
        printf("\nI am a child");
        printf("\nChild id = %d and my parent id is = %d", getpid(), getppid());
    }
    else
    {
        printf("\nI am parent process");
        printf("\nParent's id is %d", getpid());
    }
    return 0;
}