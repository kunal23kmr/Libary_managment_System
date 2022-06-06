#include <stdio.h>
void mat_multi(int a, int b, int c, int arr1[a][b], int arr2[b][c], int arr3[a][c])
{
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < c; j++)
        {
            arr3[i][j] = 0;
            for (int k = 0; k < b; k++)
            {
                int o = arr1[i][k], p = arr2[k][j];
                arr3[i][j] = o * p;
            }
        }
    }
}
int main()
{
    int a, b, c;
    printf("Enter the size of aXb mattrix(i.e value of a and b)\n");
    scanf("%d%d", &a, &b);
    int arr1[a][b];
    for (int i = 0; i < a; i++)
    {
        printf("Enter the element of %d row of mattrix aXb\n", i + 1);
        for (int j = 0; j < b; j++)
        {
            scanf("%d", &arr1[i][j]);
        }
    }
    printf("Enter the size of bXc mattrix(i.e value of b and c)\n");
    scanf("%d%d", &b, &c);
    int arr2[b][c];
    for (int i = 0; i < b; i++)
    {
        printf("Enter the element of %d row of mattrix bXc\n", i + 1);
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &arr2[i][j]);
        }
    }
    int arr3[a][c];
    mat_multi(a, b, c, arr1, arr2, arr3);
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%d ", arr3[i][j]);
        }
        printf("\n");
    }
    return 0;
}