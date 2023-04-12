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
fd=open(filename,O_WRONLY);
printf("file descritptor %d\nerror number %d\nerror message ",fd,errno);
if(errno == 1)
printf("operation not permitted");
else if(errno == 2)
printf("No such file or directory");
else if(errno == 13)
printf("permission denied");
return 0;
}
