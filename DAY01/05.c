/**
 * Opening directory from POSIX
 */
// @TODO
#include <dirent.h>
#include <stdio.h>
int main()
{
    DIR *dir;
    struct dirent *entry;
    if((dir* opendir("abc"))==NULL)
    printf("Directory not found\n");
    else
    {
        printf("Contents are\n");
        while(entry=readdir(dir)!=NULL)
        {
            printf("%s\n",entry->d_name);

        }

    }
    return 0;
}