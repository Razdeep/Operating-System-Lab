/**
 * Why isn't the last printf not being executed?
 * 
 *     The entire process image is being replaced by the new process,
 * so the control from the new process never returns back to
 * the calling process.
 */
#include <unistd.h>
#include <stdio.h>

int main()
{
    execl("./hello_world", "hello_world", NULL);
    printf("You failed if this line gets printed in the screen");
    return 0;
}