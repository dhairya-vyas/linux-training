#include<stdio.h>
#include<errno.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
char *path = argv[1];
int rval;

rval = access(path, F_OK);

if(rval == 0)
{

printf("%s exists\n",path);

if(errno == EACCES)
printf("%s is not accessible\n",path);

rval = access(path,R_OK);

if(rval == 0)
printf("%s is readable\n",path);
else 
printf("%s is not readable (access denied)\n",path);

rval = access(path,W_OK);

if(rval == 0)
printf("%s is writable\n",path);

else if(rval == EACCES)
printf("%s not writable (access denied)\n",path);

else if(rval == EROFS)
printf("%s is not writable (read-only filesystem)\n",path);

}
else
printf("%s does not exit",path);
return 0;
}
