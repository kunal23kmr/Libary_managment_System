#include <stdio.h>

int main()
{
    int sum = 0, N, M, x, y;
    printf("Enter the size of matrix (N*M)\n");
    scanf("%d%d", &N, &M);
    int arr[N][M];
    for (int i = 0; i < N; i++)
    {
        printf("Enter the M element of %d row with space\n", i + 1);
        for (int j = 0; j < M; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    printf("Enter the size of query mattrix\n");
    scanf("%d%d", &x, &y);
    if (x <= N && y <= M)
    {
        int sum2 = 0;
        for (int i = 0; i < x; i++)
        {

            for (int j = 0; j < y; j++)
            {
                sum2 = sum2 + arr[i][j];
            }
            printf("Sum of %d row is %d\n", i + 1, sum2);
        }
        printf("The final Sum= %d", sum2);
    }
    else
        printf("Enter right value of X and Y\n");
    return 0;
}