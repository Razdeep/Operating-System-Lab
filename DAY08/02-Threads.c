/**
 * Write a c program that has a parent thread which stores elements 
 * in the array by passing the array from the user and a child that performs
 * addition of all elements in the array and display it
 * 
 */
// @TODO
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#define debug(a, n) for(int i=0;i<n;i++) printf("%d", a[i])
int n;
void* childProcess(void *a)
{
    int* arr = (int*) a;
    // debug(arr, n);
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    // printf("%d\n", sum);
    pthread_exit(&sum); // @FIX_THIS
}
void* parentProcess()
{
    printf("Enter the number of array elements ");
    scanf("%d", &n);
    int *arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int result;
    pthread_t thread2;
    pthread_create(&thread2, NULL, &childProcess, arr);
    pthread_join(thread2, result);
    printf("Sum of array elements is %d", result);
}
int main(int argc, const char **argv)
{
    pthread_t thread1;
    pthread_create(&thread1, NULL, &parentProcess, NULL);
    pthread_join(thread1, NULL);
    return 0;
}