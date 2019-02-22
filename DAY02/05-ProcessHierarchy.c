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
        pid_t pid = fork();
        if (pid == 0)
        {
            // fork();
            // printf("\n%d", getpid());
            // printf("\n%d", getppid());
        }
        printf("\n%d", getpid());
        printf("\n%d", getppid());
    }
    else
    {
        // printf("\nParent\t%d", getpid());
    }
    return 0;
}