#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER 1
char buf[MAX_BUFFER];

int main (void)
{
	int fd,i,flag;
	if((fd = open("/dev/mydrv" , O_RDWR)) < 0 )
	{
		perror("open error");
		return -1;
	}
	flag = read(fd , buf , MAX_BUFFER);
	if(flag <0)
	{
		fprintf(stderr , "mtest2 first read failed\n");
	}
	fprintf(stderr , "%d wake up!!\n" , buf[0]);
}
