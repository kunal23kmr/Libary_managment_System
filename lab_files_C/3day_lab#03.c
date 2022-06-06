// 3. Write a program to find the most frequently occurring element in an array (mode of the array).
#include <stdio.h>

int main()
{
    int arr[10] = {1, 2, 2, 4, 5, 6, 7, 8, 8, 10}, n = 10, max = 0, count;
    int arr2[10] = {0};
    for (int i = 0; i < n; ++i)
    {
        count = 0;
        for (int j = 0; j < n; ++j)
        {
            if (arr[i] == arr[j] && arr[i] != 0)
            {
                count++;
                if (i < j)
                    arr[j] = 0;
            }
            arr2[i] = count;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (max <= arr2[i])
        {
            max = arr2[i];
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (arr2[i] == max)
            printf("%d ", arr[i]);
    }
    printf("ok");

    return 0;
}