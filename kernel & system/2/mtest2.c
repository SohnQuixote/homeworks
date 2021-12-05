#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER 50
char buf_in[MAX_BUFFER];
int main(void)
{
	int fd,i,flag1,flag2;
	if((fd = open("/dev/mydrv" , O_RDWR)) < 0 )
	{
		perror("open error");
		return -1;
	}
	sleep(1);
	flag1 = read(fd , buf_in , MAX_BUFFER);
	if(flag1 <0)
	{
		fprintf(stderr , "mtest2 first read failed\n");
	}
	sleep(2);
	flag2 = read(fd , buf_in , MAX_BUFFER);
	if(flag2 <0)
	{
		fprintf(stderr , "mtest2 second read failed\n");
	}
	if (flag1>0 && flag2>0)
	{
		fprintf(stderr , "mtest2 first and second read succeded\n");
	}
}
