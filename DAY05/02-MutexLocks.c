/**
 * -------------
 *  Mutex Locks
 * -------------
 * Explanation:
 * To fix the issue described in the previous program, we can use the
 * concept of mutex. Mutex is used to check whether someone is already making
 * changes to the critical section variable.
 * If someone is changing variables, then wait for them to finish, and only
 * after that READ THE UPDATED VALUE.
 * 
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
int shared_variable = 0;

void *process1()
{
    // This is actually a critical section
    pthread_mutex_lock(&mutex);
    int x = shared_variable;
    x++;
    sleep(1);
    shared_variable = x;
    pthread_mutex_unlock(&mutex);
}
void *process2()
{
    // This is actually a critical section
    pthread_mutex_lock(&mutex);
    int x = shared_variable;
    x--;
    sleep(1);
    shared_variable = x;
    pthread_mutex_unlock(&mutex);
}
int main(int argc, const char **argv)
{
    pthread_mutex_init(&mutex, NULL);
    pthread_t thread_1, thread_2;
    pthread_create(&thread_1, NULL, &process1, NULL);
    pthread_create(&thread_2, NULL, &process2, NULL);
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    printf("Shared variable = %d\n", shared_variable);
    return 0;
}