#include<stdio.h>
int main()
{
int a;
printf("Enter the number you want check-\n");
scanf("%d", &a);
if (a % 2 == 0)
    printf("You entered a even number");
    else    
    printf("Your number is odd");
return 0;
}