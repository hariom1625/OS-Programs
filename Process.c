// UNIX/lINUX system calls to create 10 Processes
#include<stdio.h>


int main()
{
	for (int i = 0; i < 10; i++) 
	{
		if (fork() == 0)
		{
			printf("Child PID: %d from Parent PID %d\n", getpid(), getppid());
			exit(0);
		}
	}
	for (int i = 0; i < 5; i++) 
		wait(NULL);

}
