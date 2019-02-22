/**
 * Wait is used to make sure that child gets terminated before the parent
 */
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int println(const char* str)
{
    write(0, "\n", 1);
    write(0, str, strlen(str));
}
int main()
{
    pid_t n = fork();
    char str[] = "\nHello";
    write(0, str, strlen(str));
    if( n < 0 )
        println("No child is created");
    else if( n == 0 )
        println("Child process");
    else
    {
        wait(NULL);
        println("Parent process");
    }
    println("------------------");
    return 0;
}