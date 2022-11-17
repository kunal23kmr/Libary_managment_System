#include <stdio.h>
#include <string.h>
void main()
{
    int i, j, n;
    char name_book[1000][40], temp[40];
    printf("Enter number of names :\n");
    scanf("%d", &n);
    printf("Enter names in any order:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%s", name_book[i]);
    }
    for(int i=0;i<n;i++){
        strlwr(name_book[i]);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(name_book[i], name_book[j]) > 0)
            {
                strcpy(temp, name_book[i]);
                strcpy(name_book[i], name_book[j]);
                strcpy(name_book[j], temp);
            }
            fflush(stdout);
        }
    }
    printf("\nThe sorted order of names are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%s\n", name_book[i]);
    }
}
