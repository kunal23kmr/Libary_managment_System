#include <stdio.h>
#include <math.h>
int min1st(int arr[], int n)
{
    int min = pow(2, 31);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= min)
            min = arr[i];
    }
    return min;
}
int min2nd(int arr[], int n)
{
    int exclueded = min1st(arr, n);
    int min = pow(2, 31);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != exclueded && arr[i] <= min)
            min = arr[i];
    }
    return min;
}
int main()
{
    int n, s1 = 0, s2 = 0;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the element of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    s1 = min1st(arr, n);
    s2 = min2nd(arr, n);
    printf("%d is 1st min and %d is 2nd min element", s1, s2);

    return 0;
}