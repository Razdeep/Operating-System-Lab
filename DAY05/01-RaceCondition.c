/**
 * ----------------------------------
 *    Race condition using threads
 * ----------------------------------
 * Explanation: 
 * How does a race condition occur? 
 *    Whenever two processes in their critical section reads a shared
 * variable at same time and they both perform different operations in their
 * local copy of the share variable. One of them writes the updated value
 * to the original shared variable. Everything seems to be okay upto this.
 *    But the problem is that the second process still performs operations
 * on the initial read instead of the updated value. Thus after the operation
 * of the second process, it replaces the shared variable value discarding
 * the changes made by the first process.
 * 
 * Intuition:
 *    Consider, a Noob bank where you have an initial balance of Rs 1000,
 * and you are crediting(200Rs) and debiting(400Rs) from your account at the same time. 
 * For both the transactions the Noob Bank reads your initial balance as 1000 Rs.
 * For the first transaction, adds 200 Rs and the final result becomes 1200,
 * and flushes to the bank transaction book.
 * For the second transaction, deducts 400 Rs from the initial balance(Rs 1000)
 * instead of the updated balance(Rs 1200), this result becomes 600.
 * But in reality the answer must be 1000 + 200 - 400 = 800
 *
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int shared_variable = 0;

void *process1()
{
    int x = shared_variable;
    x++;
    sleep(1);
    shared_variable = x;
}
void *process2()
{
    int x = shared_variable;
    x--;
    sleep(1);
    shared_variable = x;
}
int main(int argc, const char **argv)
{
    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, &process1, NULL);
    pthread_create(&thread_2, NULL, &process2, NULL);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    printf("Shared variable = %d\n", shared_variable);
    return 0;
}