#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdio.h>
int main()
{
int line_input;
int line_number=1;
char c;
int fd=open("5temp.txt",O_RDONLY);
if(fd==-1)
{
printf("Error: couldn't open file");
return 0;
}
else
{

printf("opened file successfully, now enter the line you want to read:");

scanf("%d",&line_input);

if(!read(fd,&c,1))
{
printf("file is empty!\n");
return 0;
}
else
{

lseek(fd,0,SEEK_SET);

while(read(fd,&c,1))
{
if(line_number==line_input)
{
write(1,&c,1);
}
if(c=='\n')
line_number++;
}

}


}
return 0;
}
