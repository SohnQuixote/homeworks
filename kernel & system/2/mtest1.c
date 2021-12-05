#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER 50
char buf_out[MAX_BUFFER];

int main (void)
{
	int fd,i,flag;
	if((fd = open("/dev/mydrv" , O_RDWR)) < 0 )
	{
		perror("open error");
		return -1;
	}
	for(i=0;i<MAX_BUFFER;i++)
	{
		buf_out[i] = 65;
	}
	fprintf(stderr , "mtest1: \n");
	/*for(i=0;i<MAX_BUFFER;i++)
	{
		
		fprintf(stderr , "%c"  ,buf_out[i]);
	}*/
	fprintf(stderr , "\n");
	flag = write(fd , buf_out , MAX_BUFFER);
	if(flag<0)
	{
		fprintf(stderr , "mtest1 first write failed\n");
	}
	sleep(3);
	flag = write(fd , buf_out , MAX_BUFFER);
	if(flag<0)
	{
		fprintf(stderr , "mtest1 second write failed\n");
	}
	fprintf(stderr , "mtest1 first and second write succeeded\n");
}
