#include<stdio.h>
#include"calc.h"

int main()
{
    int a,b;
    printf("Enter the first number :- ");
    scanf("%d",&a);
    printf("Enter the second number :- ");
    scanf("%d",&b);
    add(a,b);
    sub(a,b);
    mul(a,b);
    div(a,b);
    fact(a);
    return 0;
}
