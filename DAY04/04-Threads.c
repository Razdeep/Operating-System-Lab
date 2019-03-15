/**
 * ----------------------------------------
 * Using threads in C under Linux
 * ----------------------------------------
 * Note: While compiling, add the flag `-lpthread` to the gcc command.
 * This links all the dependencies of pthread functions
 * 
 * Instead of return values directly, prefer to use pthread_exit() to
 * return from the thread function
 * 
 * Explanation:
 * The last argument of pthread_create(...) can be also used to pass argument
 * to the called thread function. 
 * 
 */

#include <stdio.h>
#include <pthread.h>

typedef long long ll;

void *factorial(void *n)
{
    ll* casted_n = (ll*) n;
    ll s = 1;
    for (ll i = 1; i <= *casted_n; i++)
        s *= i;
    return s;
}
int main(int argc, const char **argv)
{
    ll result = -1;
    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, factorial, (void*)5LL);
    pthread_join(thread_1, (void*)&result);
    printf("Result is %lld\n", result);
    return 0;
}