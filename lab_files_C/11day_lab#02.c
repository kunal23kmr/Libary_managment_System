#include <stdio.h>
void digitsum(int n);

int main()
{
    int n;
    printf("Enter an integer number: ");
    scanf("%d", &n);
    digitsum(n);
    return 0;
}
void digitsum(int n)
{
    int temp=0;
    while (n > 0)
    {
        temp += n % 10;
        n/=10;
    }
    printf("The sum of all digites present in the number is %d",temp);
}