/**
 * WAP to illustrate a zombie
 * Idea: Make the parent sleep, by that time the child terminates,
 * but the PCB of the child didn't return the value to parent as it is sleeping.
 * This PCB is a actually a zombie.
 * 
 * To check the processes,
 * $ ps aux | grep 'Z'
 * 
 * Explanation:
 * 'ps' tool returns the present processes.
 * 'grep' tool is used for pattern matching.
 * '|' is used to pass output of the left as the input of the right
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
        // sleep(10);
        printf("\nI am a child");
        printf("\nChild id = %d and my parent id is = %d", getpid(), getppid());
    }
    else
    {
        sleep(10);
        printf("\nI am parent process");
        printf("\nParent's id is %d", getpid());
    }
    return 0;
}