/**
 * Opening directory from POSIX
 * d_types are integer type values
 * '4' represents directory
 * '8' represents file
 */
#include <dirent.h>
#include <stdio.h>
int main()
{
    DIR *dir = opendir("abc");
    struct dirent *entry;
    if (dir == NULL)
        printf("\nDirectory not found");
    else
    {
        printf("\nContents are\n");
        entry = readdir(dir);
        while (entry != NULL)
        {
            printf("%s\tType : %d\n", entry->d_name, entry->d_type);
            entry = readdir(dir);
        }
    }
    closedir(dir);
    return 0;
}
