#include<unistd.h>
#include<pthread.h>
#include<stdio.h>
void *fun1();
void *fun2();

int main()
{
    pthread_t thread1,thread2;
    pthread_create(&thread1,NULL,fun1,NULL);
    pthread_create(&thread2,NULL,fun2,NULL);
    pthread_join(thread1,NULL);
    pthread_join(thread2,NULL);
   

    int i;
    printf("Enter the number: ");
    scanf("%d",&i);
    for(int i;i>=1;i+=2)
    {
        printf("Thread 1 : %d\n",i);
        sleep(1);
    }

 return 0;
}


void *fun2()
{
    int j;
     printf("Enter the number: ");
    scanf("%d",&j);
    for(int j;j>=1;j+=2)
    {
        printf("Thread 2 : %d\n",j);
        sleep(1);
    }
}