#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
int file;
char buffer[50];
file=open("1.txt",O_RDONLY);
while(1)
{
read(file,&buffer,50);
write(1,&buffer,50);
lseek(file,50,SEEK_CUR);
}
return 0;
}
