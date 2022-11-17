#include <stdio.h>
void find(int *arrr, int n, int size)
{
    int temp = 0, index = 0,findindex;
    for (int i = 0; i < size; i++, index++)
    {
        if (*(arrr + i) == n)
            temp = 1,findindex=index;
    }
    if (temp == 1)
    {
        printf("Element is found index :%d\n", findindex);
    }
    if(temp==0)
    {
        printf("Element is not found\n");
    }
}
int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6}, n;
    printf("Enter The Number You wanna check:");
    scanf("%d", &n);
    printf("\n");
    find( &arr[0], n, 10);
    return 0;
}