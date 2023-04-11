#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	int  n,f,f1;
	char buff[10];
	f=open("seeking",O_RDWR);//1234567890abcdefghijx1x2x3x4x5
	read(f,buff,10);//1234567890
	write(1,buff,10);
	lseek(f,10,SEEK_CUR);
	read(f,buff,10);//x1x2x3x4x5
	write(1,buff,10);
}
