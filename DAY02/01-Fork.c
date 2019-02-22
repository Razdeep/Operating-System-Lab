/**
 * Forking a process
 * 
 */
#include <unistd.h>
#include <string.h>
int main()
{
    fork();
    char str[] = "Hello\n";
    write(0, str, strlen(str));
    return 0;
}