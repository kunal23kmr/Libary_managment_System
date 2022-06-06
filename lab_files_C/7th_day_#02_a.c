#include <stdio.h>
int main()
{    int layer, n;
    printf("Enter the number of layers you want in your SQUAR:- ");
    scanf("%d", &layer);
    printf("\n");
    n = layer;
    int squar[(2 * n) - 1][(2 * n) - 1];
    int start = 0, end = ((2 * n) - 2);
    for (int i = 0; i < n; i++)
    {
        for (; layer > 0,start <= end; layer--, ++start, --end)
        {
            for (int k = start; k <= end; k++)
            {
                for (int l = start; l <= end; l++)
                {
                    squar[k][l] = layer;
                }
            }
        }
    }
    for (int i = 0; i < ((2 * n) - 1); i++)
    {
        for (int j = 0; j < ((2 * n) - 1); j++)
        {
            printf(" %d ", squar[i][j]);
        }
        printf("\n");
    }
    return 0;
}