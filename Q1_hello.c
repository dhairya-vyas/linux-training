#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
    int file;
    file=open("1.txt",O_WRONLY|O_CREAT);
    write (file,"Hello World /n",11);
    return 0;
}