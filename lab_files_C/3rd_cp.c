#include<stdio.h>
int main()
{
int a,b,c;
printf(" Enter 1st number\n");
scanf("%d", &a);
printf(" Enter 1st number\n");
scanf("%d", &b);
c=b;
b=a;
a=c;
printf(" After swaping 1st is %d And 2nd is %d", a,b);
return 0;
}