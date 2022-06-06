#include <stdio.h>
int main()
{
    char a[100];
    printf("Enter the string\n");
    scanf("%[^\n]s", &a);
    int length = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        length++;
    }
    int arr[length], max = 0,t=0;
    for (int i = 0; i < length; i++)
    {
        int f = 0;
        for (int j = 0; j < length; j++)
        {
            if (a[i] == a[j])
            {
                f++;
            }
        }
        arr[i] = f;
        if (max < f)
        {
            max = f,t=i;
        }
    }
    printf("'%c' has maximum frequency\n", a[t]);
    return 0;
}