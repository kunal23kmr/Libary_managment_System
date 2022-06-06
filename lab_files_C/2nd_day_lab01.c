#include <stdio.h>

int main()
{
    int a, b;
    float c, d;
    printf("Enter Two number 'a' and 'b'\n");
    scanf("%d %d", &a, &b);
    printf("Enter Two number 'C' and 'D'\n");
    scanf("%f %f", &c, &d);
    printf("The sum of a and b (a+b)= %d\n", a + b); 
    printf("The diffrence of a and b= %d\n", a-b);  
    printf("The sum of c and d (c+d)= %0.2f\n", c + d);
    printf("The diffrence of c and d(c-d)= %0.2f\n", c - d);


}