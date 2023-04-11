#include<sys/stat.h>
#include<unistd.h>
#include<sys/types.h>
#include<pthread.h>
#include<fcntl.h>
void *fun1();
void *fun2();
int fd;
pthread_mutex_t l;

int main()
{
    pthread_mutex_init(&l,NULL);
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,fun1,NULL);
    pthread_create(&thread2,NULL,fun2,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
 return 0;
}

void *fun1()
{
    pthread_mutex_lock(&l);
    fd=open("temp.txt",O_WRONLY|O_APPEND|O_CREAT);
    char c='A';
    for(c='A';c<='Z';c++)
    write(fd,&c,1);
    pthread_mutex_unlock(&l);
}

void *fun2()
{
    sleep(1);
    pthread_mutex_lock(&l);
    char c='a';
    for(c='a';c<='z';c++)
    write(fd,&c,1);
    pthread_mutex_unlock(&l);
}