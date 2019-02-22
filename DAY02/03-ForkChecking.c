/**
 * Forking a process
 * 
 * Let n be the return of the fork
 * 1. if n < 0, fork failed
 * 2. if n == 0, child is running currently
 * 3. if n > 0, parent is running currently
 * 
 * Note: Sometimes parent might exit before the execution of the child
 * Resolution: wait()
 */
#include <unistd.h>
#include <string.h>
int println(const char* str)
{
    write(0, "\n", 1);
    write(0, str, strlen(str));
}
int main()
{
    int n = fork();
    char str[] = "\nHello";
    write(0, str, strlen(str));
    if( n < 0 )
        println("No child is created");
    else if( n == 0 )
        println("Child process");
    else
        println("Parent process");
    println("------------------");
    return 0;
}