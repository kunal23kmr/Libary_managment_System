#include <stdio.h>
#include <math.h>

int main()
{
    FILE *f = NULL;
    f = fopen("output_2.txt", "w");
    fclose(f);
    f = fopen("output_2.txt", "a");

    int T, input[100];
    char number[50];
    scanf("%d", &T);
    if (T < 1 || T > 100)
    {
        return 0;
    }
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &input[i]);
        if (input[i] < 1 || input[i] > 50)
        {
            return 0;
        }
        long long int X = pow(10, input[i] - 1);
        while (X < pow(10, input[i]))
        {
            if ((X / 4) % 2 != 0)
            {
                sprintf(number, "%lld\n", X);
                fputs(number, f);
                fflush(stdin);
                break;
            }
            X++;
        }
        }
    fclose(f);
    return 0;
}