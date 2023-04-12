#include<unistd.h>
#include<errno.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main(int arc,char *argv[])
{
extern int errno;
int fd;
char *filename=argv[1];
fd=open(filename,O_WRONLY|O_CREAT);
printf("file descritptor %d\n",fd);
if(errno == 1)
printf("error: %d\noperation not permitted",errno);
else if(errno == 2)
printf("error: %d\nNo such file or directory",errno);
else if(errno == 13)
printf("error: %d\npermission denied",errno);
return 0;
}
