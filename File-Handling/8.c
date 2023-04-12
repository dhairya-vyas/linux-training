#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
int main(int argc, char *argv[])
{
int fd;
char *path=argv[1];
fd=open(path,O_RDONLY);
struct stat status;
mode_t permissions;
stat(path,&status);
permissions = status.st_mode;
return 0;
}
