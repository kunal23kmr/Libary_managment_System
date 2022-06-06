#include<stdio.h>
int main()
{
    float a,b,c,sum,avg;
    printf("Enter the marks of first student\n");
    scanf("%f", &a);
    printf("Enter the marks of second student\n");
    scanf("%f", &b);
    printf("Enter the marks of third student\n");
    scanf("%f", &c);
    sum=a+b+c;
    avg=(a+b+c)/3;
    printf("Sum=%0.2f\n", sum);
    printf("Avg. of there marks=%0.2f\n", avg);   
    return 0; 
}