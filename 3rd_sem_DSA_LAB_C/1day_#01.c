#include <stdio.h>
void printarray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
void sort(int *arr, int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
void delete (int *arr, int size, int index)
{
    if (index < size - 1)
    {
        for (int i = 0; i < (size - index - 1); i++)
        {
            arr[index + i] = arr[index + i + 1];
        }
    }
    size--;
    printf("The array with deleted element is: ");
    printarray(arr, size);
    printf("\n\nThe sorted array with deleted element is: ");
    sort(arr, size);
    printarray(arr, size);
}
void insert(int *arr, int size, int index)
{
    int insertElement;

    printf("Enter the element that you want to insert: ");
    scanf("%d", &insertElement);
    for (int i = 0; i < size - index; i++)
    {
        arr[size - i] = arr[size - i - 1];
    }
    arr[index] = insertElement;
    size++;
    printf("The array with inserted element is: ");
    printarray(arr, size);
    printf("\n\nThe sorted array with inserted element is: ");
    sort(arr, size);
    printarray(arr, size);
}

int main()
{
    int arr1[7] = {1, 7, 4, 20, 40, 2, 0}, index, operation;
    printf("\n\n");
    printf("Your array is: ");
    printarray(arr1, 7);
    printf("\n\n\n");
    printf("Enter the index of that array you wanna insert or delete: ");
    scanf("%d", &index);

    printf("Enter 1(to delete), 2(for insert): ");
    scanf("%d", &operation);
    switch (operation)
    {
    case 1:
        if (index < 0 || index > 6)
            return 0;
        delete (arr1, 7, index);
        break;
    case 2:
     if(index<0||index>7)
    return 0;
        insert(arr1, 7, index);
        break;
    default:
        printf("Invalid input");
        return 0;
    }

    return 0;
}