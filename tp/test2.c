#include <stdio.h>
int main()
{
    int di, mi, yi, dt, mt, yt, totalday = 0;
    printf("Enter your date of birth:(DD/MM/YYYY) ");
    scanf("%d%d%d", &di, &mi, &yi);
    printf("Enter todays date:(DD/MM/YYYY) ");
    scanf("%d%d%d", &dt, &mt, &yt);
    while (1)
    {
        if (di == dt && mi == mt && yi == yt)
        {
            break;
        }
        di++;
        totalday++;
        if (mi == 1 || mi == 3 || mi == 5 || mi == 7 || mi == 8 || mi == 10 || mi == 12)
        {
            if (di > 31)
            {
                mi++;
                di = 1;
            }
        }
        else if (mi == 4 || mi == 6 || mi == 9 || mi == 11)
        {
            if (di > 30)
            {
                mi++;
                di = 1;
            }
        }
        else if (mi == 2)
        {
            if (yi % 4 == 0)
            {
                if (di > 29)
                {
                    mi++;
                    di = 1;
                }
            }
            else
            {
                if (di > 28)
                {
                    mi++;
                    di = 1;
                }
            }
        }
        if (mi > 12)
        {
            yi++;
            mi = 1;
        }
    }
    printf("The total number of days:%d",totalday);
    return 0;
}