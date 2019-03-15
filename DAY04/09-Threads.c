/** 
 * CONTROLLING THE ORDER OF EXECUTION OF THREADS
 * Scenario :
 * Thread 2 would execute first,
 * Thread 3 would execute second,
 * Thread 1 would execute last
 * 
 */
#include <stdio.h>
#include <pthread.h>
void task1()
{
    printf("I\'m thread 1\n");
}
void task2()
{
    printf("I\'m thread 2\n");
}
void task3()
{
    printf("I\'m thread 3\n");
}
int main(int argc, const char* argv)
{
    pthread_t thread_1, thread_2, thread_3;
    pthread_create(&thread_2, NULL, task2, NULL);
    pthread_create(&thread_1, NULL, task1, NULL);
    pthread_create(&thread_3, NULL, task3, NULL);
    
    pthread_join(thread_1, NULL);
    pthread_join(thread_2, NULL);
    pthread_join(thread_3, NULL);
    return 0;
}