#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
int old_fd,new_fd;

old_fd=open("16_dup_demo.txt",O_RDWR);
printf("file descriptor %d\n",old_fd);
write(old_fd,"Hello world",15);
new_fd=dup(old_fd);

printf("New file descriptor is %d\n",new_fd);
write(old_fd,"i am sumit\n",17);
printf("Now using new file descriptor\n");
write(new_fd,"This line by new_fd",19);
return 0;
}
