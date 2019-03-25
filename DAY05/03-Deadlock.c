/**
 * Deadlock Demonstration
 * Idea:
 * @TODO
 * 
 * Explanation:
 * @TODO
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex_1, mutex_2;

void* process1()
{
    pthread_mutex_lock(&mutex_1);
    // sleep(1);
    printf("Process 1 has acquired lock 1\n");
    pthread_mutex_lock(&mutex_2);
    pthread_mutex_unlock(&mutex_1);
    pthread_mutex_unlock(&mutex_2);
    printf("Process 1 has unlocked both the mutex locks\n");
}
void* process2()
{
    pthread_mutex_lock(&mutex_2);
    // sleep(1);
    printf("Process 2 has acquired lock 2\n");
    pthread_mutex_lock(&mutex_1);
    pthread_mutex_unlock(&mutex_1);
    pthread_mutex_unlock(&mutex_2);
    printf("Process 2 has unlocked both the mutex locks\n");
}
int main(int argc, const char** argv)
{
    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, &process1, NULL);
    pthread_create(&thread_2, NULL, &process2, NULL);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    return 0;
}