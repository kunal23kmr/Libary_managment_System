#include <stdio.h>
void selectionSort(int array[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int k=n-1,j = k - 1; j >= 0,k>0; j--,k--)
        {
            if (array[k] < array[j])
            {
                int temp;
                temp = array[k];
                array[k] = array[j];
                array[j] = temp;
            }
        }
        for(int k=0;k<n;k++)
        {
            printf("%d ", array[k]);
        
        }
        printf("\n");
    }
}
int main()
{
    int n;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the element of array\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    selectionSort(arr, n);
    printf("Sorted array\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}