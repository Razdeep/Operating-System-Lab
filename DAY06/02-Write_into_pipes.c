/**
 * Explanation:
 * @TODO
 * 
 */
#include <stdio.h>
#include <string.h>
int main(int argc, const char **argv)
{
    FILE *rd;
    char buffer[50];
    sprintf(buffer, "Rajdeep Roy Chowdhury");
    rd = popen("wc -c", "w");
    fwrite(buffer, sizeof(char), strlen(buffer), rd);
    pclose(rd);
    return 0;
}