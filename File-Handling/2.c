#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
int f;
char c='A';
f=open("2.hex",O_APPEND | 50);
for(int i=1;i<=50;i++,c++)
{
write(f,&c,1);
}
return 0;
}
