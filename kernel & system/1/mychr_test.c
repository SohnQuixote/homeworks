#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER 26
char buf_in[MAX_BUFFER];
char buf_out[MAX_BUFFER];

int main(void)
{
	int fd,i,c = 65;
	if((fd = open("/dev/mydrv" , O_RDWR)) < 0 )
	{
		perror("open error");
		return -1;
	}
	for (i=0;i<MAX_BUFFER;i++){
		buf_out[i] = c++;
		buf_in[i] = 65;
		}
	for (i = 0 ; i<MAX_BUFFER;i++){
		fprintf(stderr , "%c"  ,buf_in[i]);
	}
	fprintf(stderr , "\n");
	
	write(fd , buf_out , MAX_BUFFER);
	read(fd , buf_in , MAX_BUFFER);
	
	for(i=0;i<MAX_BUFFER;i++)
	{
		fprintf(stderr , "%c"  ,buf_in[i]);	
	}
	fprintf(stderr , "\n");
		
	c = 65;
	for (i=0;i<MAX_BUFFER;i++){
		buf_out[i] = c++;
		buf_in[i] = 65;
		}
	for (i = 0 ; i<MAX_BUFFER;i++){
		fprintf(stderr , "%c"  ,buf_in[i]);
	}
	fprintf(stderr , "\n");
	
	write(fd , buf_out , MAX_BUFFER);
	read(fd , buf_in , MAX_BUFFER);
	
	for(i=0;i<MAX_BUFFER;i++)
	{
		fprintf(stderr , "%c"  ,buf_in[i]);	
	}
	fprintf(stderr , "\n");
	close(fd);
	return 0;	
}
