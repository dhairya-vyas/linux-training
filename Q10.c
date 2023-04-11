#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include<string.h>
#include<errno.h>

int main()
{
    int number_byter=0,file;
    file=open("Name.txt",O_CREAT|O_WRONLY|O_TRUNC);
    if(file==-1)
    {
        if(errno==EACCES)
        printf("Permission denied\n");
        else if(errno==ENOENT)
        printf("No such file or directory\n");
    }
    else{
        char name_surname[30];
        printf("enter the name:");
        scanf("%s",name_surname);
        number_bytes=write(file,&name_surname,strlen(name_surname));
        printf("\n enter your surname:");
        scanf("%s",name_surname);
        number_bytes=write(file,&name_surname,strlen(name_surname)) + number_bytes;
        number_bytes;

        printf("\nfile descriptor: %d\n",file);
        printf("number of nytes written successfully:%d",number_bytes);
    }
    return 0;
    
}