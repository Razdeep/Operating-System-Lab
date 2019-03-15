/**
 * ----------------------------------------
 * Using threads in C under Linux
 * ----------------------------------------
 * Note: While compiling, add the flag `-lpthread` to the gcc command.
 * This links all the dependencies of pthread functions
 * 
 * Explanation:
 * pthread_create(...) is used to run a function using a separate thread
 * pthread_join(...) is used to prevent the parent to quit
 * the second parameter of pthread_join(...) is used for return values
 * from the function
 * 
 */

#include <stdio.h>
#include <pthread.h>

void* infinity()
{
    while(1){
        printf("one");
    }
}
void* infinity2()
{
    while(1){
        printf("two");
    }
}
int main(int argc, const char** argv)
{
    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, infinity, NULL);
    pthread_create(&thread_2, NULL, infinity2, NULL);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    return 0;
}