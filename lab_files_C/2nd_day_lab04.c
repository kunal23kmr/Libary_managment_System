#include<stdio.h>

int main(){
    int a,i;
    long int fac=1;
    printf("Enter the Number\n");
    scanf("%d",&a);
    if (a<0)
    printf("enter biger number\n");
    else{
    for(i=1;i<=a;i++){
        fac=fac*i;
    }
    printf("The factorial =%ld", fac);
    }
    return 0;
}