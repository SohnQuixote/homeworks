#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER 50
char buf_in[MAX_BUFFER];
int main(void)
{
	int fd,i,flag;
	if((fd = open("/dev/mydrv" , O_RDWR)) < 0 )
	{
		perror("open error");
		return -1;
	}
	
	sleep(2);
	flag = read(fd , buf_in , MAX_BUFFER);
	if(flag <0)
	{
		fprintf(stderr , "mtest3 read failed\n");
	}
	else
	{
		fprintf(stderr , "mtest3 read succeeded\n");
	}
}
