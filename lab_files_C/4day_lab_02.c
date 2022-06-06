#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
int binarySearch(int arr[], int N, int key)
{
    int start = 0, end = N - 1, mid = (start / 2 + end / 2);
    while (start <= end)
    {
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
        {
            start = mid + 1;
            mid = (start / 2 + end / 2);
        }
        else if (arr[mid] > key)
        {
            end = mid - 1;
            mid = (start / 2 + end / 2);
        }
    }
    return (-1);
}
int main()
{
    int key, N = 0, arr[N], requiredIndex;
    printf("Enter the size of array\n");
    scanf("%d", &N);
    printf("Enter all the inputes\n");
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= N - 1; i++)
    {
        for (int j = 1; j <= N - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(&arr[j - 1], &arr[j]);
            }
        }
    }
    printf("Enter the key to be searched:\n");
    scanf("%d", &key);
    requiredIndex = binarySearch(arr, N, key);
    /*printf("Sorted array is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d", &arr[i]);
    }*/
    if ( requiredIndex == -1)
        printf("-1");
    else
        printf("The index of that element is: %d", requiredIndex);

    return 0;
}