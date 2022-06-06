#include <stdio.h>
int main()
{
    int i = 3, a = 1, b = 1, c, j;
    printf("Enter number of terms:");
    scanf("%d", &j);
    if (j == 0)
        printf(" ");
    else if (j == 1)
        printf("%d ", a);
    else if (j == 2)
        printf("%d %d ",a, b);
    else if (j >= 3)
    {
        printf("%d ", a);
        printf("%d ", b);
        while (i <= j)
        {
            c = a + b;
            printf("%d ", c);
            i++;
            a = b;
            b = c;
        }
    }
    else
        printf("Invalid Input");
    return 0;
}