#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    printf("Fork here.\n");
    pid = fork();
    if(pid == -1)
    {
        return (1);
    }
    printf("\nFork Successful!\n");
    if (pid == 0)
    {
        printf("child:i'm the child,my internal pid is %d.\n",pid);

    }
    else if (pid > 0)
    {
        printf("Parent: i'm the parent, my child's pid is %d.\n",pid);
    }
    return(0);
}