#include<fcntl.h>
#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
int main()
{
int fd;
char *buff[10];
fd = open("15_test.txt",O_RDWR| O_CREAT);
lseek(fd,10,SEEK_SET);
read(fd,buff,6);
write(1,buff,6);
return 0;
}
