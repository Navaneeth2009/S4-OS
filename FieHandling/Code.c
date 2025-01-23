#include<sys/types.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<stdio.h>
void main()
{
	int fd,fd2;
	char wbuf[128];
	char rbuf[128];
	fd=open("file.txt",O_RDWR);
	printf("Enter file content :  ");
	scanf("%s",wbuf);
	write(fd,wbuf,strlen(wbuf));
	close(fd);
	fd2=open("file.txt",O_RDWR);
	read(fd2,rbuf,100);
	printf("%s",rbuf);
	close(fd2);
	
}
//Remember to create file before use
