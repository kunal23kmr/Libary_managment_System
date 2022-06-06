#include <stdio.h>
int main()
{
    char a[100];
    printf("Enter the String\n");
    scanf("%[^\n]c", a);
    int length = 0;
    for (int i = 0; a[i] != '\0'; i++)
    {
        length++;
    }
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length;)
        {
            if (a[i] == a[j])
            {
                for (int k = j + 1, l = j; k < length; k++, l++)
                {
                    a[l] = a[k];
                }
                length--;
            }
            else
                j++;
        }
    }
    for (int i = 0; i < length; i++)
    {
        printf("%c", a[i]);
    }
    return 0;
}