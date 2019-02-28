/**
 * Make the hierarchy as
 * A -> B -> C
 * @TODO
 * Show the hierarchy
 */
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int println(const char *str)
{
    write(0, "\n", 1);
    write(0, str, strlen(str));
}
int main()
{
    pid_t pid = fork();
    if (pid < 0)
        printf("Fork failed");
    else if (pid == 0) //Child process
    {
        pid_t pid2 = fork();
        if ( pid2 < 0 )
            printf("fork #2 failed");
        else if (pid2 == 0)
        {
            pid_t pid3 = fork();
            printf("\npid = %d", getpid());
            printf("\nppid = %d", getppid());
        }
        printf("\n%d", getpid());
        printf("\n%d", getppid());
    }
    else
    {
        printf("\nParent\t%d", getpid());
    }
    return 0;
}