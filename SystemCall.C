#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<stdio.h>
int main()
{
	int n, f;
	char buffer[50];

	printf("Enter data to be entered in the file:\n");

	n = read(0, buffer, 50);

	f = open("file", O_CREAT | O_RDWR, 0777);

	write(f, buffer, n);
	write(1, buffer, n);

	int close(int f);

	return 0;
}
