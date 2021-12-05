#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_BUFFER 5
char dht11_dat[5];
int main(void)
{
	int fd,i,flag1,flag2;
	if((fd = open("/dev/mydrv" , O_RDWR)) < 0 )
	{
		perror("open error");
		return -1;
	}
	while(1){
	sleep(5);
	flag1 = read(fd , dht11_dat , MAX_BUFFER*sizeof(char));
	if(flag1<0){
		printf("reading failed!!!!\n");
	}
	else{
	printf("humidity = %d.%d %% Temperature = %d.%d *C \n", dht11_dat[0], dht11_dat[1], dht11_dat[2], dht11_dat[3]);
	}
}
}
