#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Input the number:- \n");
    scanf("%d", &a);
    if(a<2)
    printf("Not a prime number\n");
    else
       
       {
            for (b = 2; b < a; b++)
        {
            c = a % b;
            if(c==0)
            break;
        }
        if (c == 0)
            printf("number that you input is not a prime number\n");
    
        else
        printf("number that you input is a prime number\n");
       }

    return 0;
}