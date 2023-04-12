#include<sys/types.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
int fd;
fd=open("14_test.txt",O_RDWR | O_CREAT);
if(fd<0)
{
printf("Couln't open file");
return 0;
}
printf("File descriptor: %d",fd);
return 0;
}
