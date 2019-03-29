/**
 * ------------------
 *  SET B QUESTION 1
 * ------------------
 * Create a scenario where a process creates a thread and passed
 * an integer and a character to the the thread, which in turn
 * prints the value of received integer & character
 * 
 * NOTE: Compile with `gcc -lpthread`
 * 
 */
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

struct Argument
{
    int a;
    char b;
};
void *func1(void *argument)
{
    struct Argument *parsed_argument = (struct Argument *)parsed_argument;
    printf("Value of int a: %d\n", parsed_argument->a);
    printf("Value of char b: %c\n", parsed_argument->b);
}
int main()
{
    struct Argument argument;
    argument.a = 10;
    argument.b = 'a';

    pthread_t thread;
    pthread_create(&thread, NULL, func1, &argument);
    pthread_join(thread, NULL);
    return 0;
};
