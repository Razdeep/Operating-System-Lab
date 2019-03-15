/**
 * WAP that creates a thread, the thread prints number from 0 to n,
 * where value of n is passed from the main process to the thread.
 * The main process also waits for the thread to finish first and then
 * prints from 20 to 24
 * 
 */

#include <stdio.h>
#include <pthread.h>

void *fire(void *n)
{
    int *casted_n = (int*) n;
    for (int i = 0; i < *casted_n; i++)
    {
        printf("%d ", i);
    }
}
int main(int argc, const char **argv)
{
    pthread_t mythread;
    int n;
    printf("Enter the value of n ");
    scanf("%d", &n);
    pthread_create(&mythread, NULL, fire, (void*)&n);
    pthread_join(mythread, NULL);
    for (int i = 22; i <= 24; i++)
    {
        printf("%d ", i);
    }
    return 0;
}