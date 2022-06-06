#include <stdio.h>
void fun(int n, int a, int b)
{
    int temp = 0, x = n;
    if (x > 0)
    {
        printf("%d ", a);
        temp = b + a;
        a = b;
        b = temp;
        fun(--x, a, b);
    }
}
int main()
{
    int n, a = 0, b = 1;
    printf("Enter the number of terms ,You wanna print:- ");
    scanf("%d", &n);
    printf("\n");
    fun(n, a, b);
    return 0;
}