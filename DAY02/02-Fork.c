/**
 * Forking a process a thrice
 * Result: 8 times "Hello" would be printed
 * Explanation: @TODO
 */
#include <unistd.h>
#include <string.h>
int main()
{
    fork();
    fork();
    fork();
    char str[] = "Hello\n";
    write(0, str, strlen(str));
    return 0;
}