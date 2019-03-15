/**
 * DOING THE SAME WITH CHARACTER INSTEAD OF INTEGER
 * 
 * NOTE: variables cannot have void type, it only allows void pointer
 * 
 */
#include <stdio.h>
#include <pthread.h>
void *isVowel(void *ch)
{
    char casted_ch = (char *)ch;
    return casted_ch == 'a' || casted_ch == 'e' || casted_ch == 'i' || casted_ch == 'o' || casted_ch == 'u' || casted_ch == 'A' || casted_ch == 'E' || casted_ch == 'I' || casted_ch == 'O' || casted_ch == 'U';
}
int main(int argc, const char **argv)
{
    int result;
    char ch;
    printf("Enter a character ");
    scanf("%c", &ch);
    pthread_t thread_1;
    pthread_create(&thread_1, NULL, isVowel, ch);
    pthread_join(thread_1, (void **)&result);
    if (result)
        printf("The entered charater %c is a vowel", ch);
    else
        printf("The entered charater %c is not a vowel", ch);
    return 0;
}