/**
 * Reading from pipe
 * 
 */
#include <stdio.h>
int main(int argc, const char** argv)
{
    FILE *rd;
    char buffer[50];
    rd = popen("ls", "r");
    fread(buffer, sizeof(char), 50, rd);
    printf("%s\n", buffer);
    pclose(rd);
}