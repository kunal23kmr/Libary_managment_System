/*Given an array of integers, sort the array in ascending order using the Bubble Sort algorithm
above. Once sorted, print the following three lines:
1. Array is sorted in numSwaps swaps., where  is the number of swaps that took place.
2. First Element: firstElement, where  is the first element in the sorted array.
3. Last Element: lastElement, where  is the last element in the sorted array.
*/
#include <stdio.h>
void swap(int *a, int *b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int swapCount = 0, n = 0, arr[n];
    // printf("Enter the number of elements\n");
    scanf("%d", &n);
    // printf("Enter inputes\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                swap(&arr[j - 1], &arr[j]);
                swapCount++;
            }
        }
    }
    printf("Array is sorted in numSwaps:%d\n", swapCount);
    printf("First Elemen: %d\n", arr[0]);
    printf("Last Element: %d\n", arr[n - 1]);

    return 0;
}