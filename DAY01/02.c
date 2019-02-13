/**
 * Using lseek for moving the file cursor
 * 
 * Argument Constants for lseek
 * SEEK_SET - Set the cursor to the beginning of the file
 * SEEK_CUR - Set the cursor to the current position
 * SEEK_END - Set the cursor to the Ending of the file
 * -------------------------------------------------------------------
 * Note: It is wise to use the constant as 'whence' from the 'offset'
 * -------------------------------------------------------------------
 */
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define MAX 50

int main()
{
    int chars_to_be_read = 5;
    char buffer[MAX];
    size_t file_descriptor = open("file.txt", O_RDONLY, 0777);
    read(file_descriptor, buffer, chars_to_be_read);
    write(1, buffer, strlen(buffer));

    lseek(file_descriptor, 0, SEEK_SET); // SEEKSET refers to beginning
    read(file_descriptor, buffer, chars_to_be_read);
    write(1, buffer, strlen(buffer));

    write(1, "\n", 1);                  // New line

    lseek(file_descriptor, -3, SEEK_END);
    read(file_descriptor, buffer, 3);   // @TODO: increase 3 to 5
    /* NOTE : read() doesnt put a null character at the end of the string*/
    buffer[3] = '\0'; // It's better to put a null character manually like this

    write(1, buffer, strlen(buffer));
    return 0;
}