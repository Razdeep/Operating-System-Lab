/** 
 * PASSING ARRAY IN THE THREAD PROCESS
 * NOT WORKING
 */
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void *sumOfArray(void *arr)
{
    int *casted_array = (int *)arr;
    int n = sizeof(arr) / sizeof(int);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += casted_array[i];
    }
    return sum;
}
int main(int argc, const char **argv)
{
    pthread_t thread_1;
    int n, result;
    printf("Enter the value of n ");
    scanf("%d", &n);
    int *arr = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    pthread_create(&thread_1, NULL, sumOfArray, (void *)arr);
    pthread_join(thread_1, &result);
    printf("Sum of the array is %d\n", result);
    return 0;
}