/**
 * ----------------------------------------
 * Using threads in C under Linux
 * ----------------------------------------
 * Note: While compiling, add the flag `-lpthread` to the gcc command.
 * This links all the dependencies of pthread functions
 * 
 * Explanation:
 * The last argument of pthread_create(...) can be also used to pass argument
 * to the called thread function. 
 * 
 */

#include <stdio.h>
#include <pthread.h>
typedef long long ll;
void *factorial(ll n)
{
    ll s = 1;
    for (ll i = 1; i <= n; i++)
        s *= i;
    printf("Factorial of %lld is %lld\n", n, s);
}
int main(int argc, const char **argv)
{
    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, factorial, 5LL);
    pthread_join(thread_1, NULL);
    return 0;
}