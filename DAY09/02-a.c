/**
 * Exercise #2
 * 
 * Write a program to create a thread that calculates the average marks
 * of a student. Pass the marks from main process to the thread 
 */
// @TODO
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 5
void *averageProcess(void *marks)
{
    float *fetched_marks = (float *)marks;
    float *sum = (float*)calloc(1, sizeof(float));
    for (int i = 0; i < MAX; i++)
    {
        *sum += fetched_marks[i];
    }
    *sum /= MAX;
    // printf("debug %f", *sum);
    pthread_exit((void*)sum);
}
int main(int argc, const char **argv)
{
    float marks[MAX], average;
    printf("Enter marks of 5 subjects");
    for (int i = 0; i < MAX; i++)
        scanf("%f", &marks[i]);
    pthread_t thread;
    pthread_create(&thread, NULL, &averageProcess, marks);
    pthread_join(thread, (void*)&average);
    printf("The average of the marks is %f", average);
    return 0;
}
