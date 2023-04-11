#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
void *fun1();
void *fun2();
int main()
{
    pthread_t thread1,thread2;
    pthread_create(&thread2,NULL,fun1,NULL);
    pthread_create(&thread1,NULL,fun2,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
    return 0;
}

void *fun1()
{
    printf("Thread1 pid: %d\n",getpid());
    printf("Thread1 thread id:%d\n",getppid());

}
void *fun2()
{
    printf("Thread2 pid: %d\n",getpid());
    printf("Thread1 thread id:%d\n",getppid());
}