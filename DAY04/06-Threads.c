/**
 * 
 * Passing multiple parameters to pthread_create(...)
 *
 */
#include <stdio.h>
#include <pthread.h>

typedef unsigned long long ull;

struct S1{
    int a, b;
};
void *fun(void *args)
{
    struct S1 *arg = args;
    printf("%d", arg->a);
    pthread_exit(NULL);
}
int main(int argc, const char **argv)
{
    pthread_t t;
    struct S1 ar;
    ar.a = 9;
    ar.b = 6;
    pthread_create(&t, NULL, fun, &ar);
    pthread_join(t, NULL);
    return 0;
}