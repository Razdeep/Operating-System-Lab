/**
 * WAP to reverse a string from a file
 */
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
void strrev(char *str)
{
	char temp;
	int i = 0;
	int n = strlen(str);
	while( i<n/2 )
	{
		temp = str[i];
		str[i] = str[n - i - 1];
		str[n - i - 1] = temp;
		i++;
	}
}
int main(int argc, char **argv)
{
	const int MAX = 100;
	char str[MAX];
	size_t file_descriptor = open("file.txt", O_RDONLY, 0777);
	read(file_descriptor, str, MAX);
	strrev(str);
	write(0, str, strlen(str));
	return 0;
}
