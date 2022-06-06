#include <stdio.h>
/*
void swap(int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
*/
int main()
{
    int arr[5] = {1, 2, 3, 4, 5}, a, n = 5;
    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        a = arr[i];
        arr[i] = arr[j];
        arr[j] = a;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}