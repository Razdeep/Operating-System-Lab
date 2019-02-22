/**
 * Replace a process using execl
 * Expected Output:
 * 
 * Explanation:
 * execl() is used to replace the current process with process specified.
 * 
 */
#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("\nBefore execl");
    fflush(stdout); // This makes sure that the print buffer is cleared 
                    // before it is replaced.
    execl("/bin/ps", "ps", NULL);
    printf("\nAfter execl");
    fflush(stdout);
    return 0;
}