/**
 * -------------------------------------------
 * USING STRUCT TO PASS MULTIPLE ARGUMENTS
 * -------------------------------------------
 * Passing multiple parameters to pthread_create(...)
 * 
 * Explanation:
 * Since only one element can be passed through the pthread_create(...),
 * so we have to pack all of our arguments in data structure like
 * a struct or an array
 * 
 */
#include <stdio.h>
#include <pthread.h>

typedef long long ll;

struct Argument
{
    ll a, b;
};

ll gcdUtility(ll a, ll b)
{
    if (b == 0 || b == 1)
        return 1;
    return gcdUtility(b, a % b);
}
void *gcd(void *argument)
{
    struct Argument *parsed_argument = (struct Argument *)argument;
    return gcdUtility(parsed_argument->a, parsed_argument->b);
}
int main(int argc, const char **argv)
{
    ll result;
    struct Argument *argument = (struct Argument *)malloc(sizeof(struct Argument));
    printf("Enter the value of a and b ");
    ll a, b;
    scanf("%lld%lld", &a, &b);
    argument->a = a;
    argument->b = b;
    pthread_t my_thread;
    pthread_create(&my_thread, NULL, gcd, argument);
    pthread_join(my_thread, (void *)&result);
    printf("GCD of %lld and %lld is %lld", argument->a, argument->b, result);
    return 0;
}