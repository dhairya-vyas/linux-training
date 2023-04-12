#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{

int fd=open("4_test.txt",O_RDWR|O_TRUNC);
char c;
int file_size=0;
char *buffer=NULL;
if(fd==-1)
printf("Error occured: couldn't open the file");

else
{
printf("File opened successfully\n");
printf("Reverse operation started\n");

file_size=(int)lseek(fd,(size_t)0,SEEK_END);
printf("size of file: %d",file_size);
buffer=(char*)malloc(file_size * sizeof(char));

lseek(fd,0,SEEK_SET);

read(fd,&buffer,file_size);
/*for(int i=0;i,file_size/2;i++)
{

}*/




}
return 0;
}
