#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
void main()
{
	int status,pid,child_pid;
	pid=fork();
	if(pid==-1)
	{
		printf("Child process creation Failed");
		exit(0);
	}
	else if(pid==0)
	{
		printf("Process of Child Process : %d",getpid());
		execlp("/bin/date","date",NULL);
		exit(0);
	}
	else{
		child_pid=wait(&status);
		printf("Process of Parent process :%d",getpid());
		printf("Succesfully Created Child Process");
	}
}
