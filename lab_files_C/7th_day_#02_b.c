#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of rows you wanna in your pattern: ");
    scanf("%d", &n);
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (n - i); j++)
        {
            printf("  ");
        }
        for (int k = 0; k <= (i * 2); k++)
        {
            printf("* ");
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}