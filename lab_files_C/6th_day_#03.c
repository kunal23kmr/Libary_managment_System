#include <stdio.h>
#include <ctype.h>
int main()
{
    char a[1000], b[1000], c[1000];
    int sizeB = 0, scape = 0;
    printf("Enter the words with space between them\n");
    scanf("%[^=\n]", a);
    for (int i = 0; a[i] != '\0'; i++)
    {
        if (a[i] != ' ')
            b[sizeB] = a[i], sizeB++;
        else
            scape++;
    }
    for (int j = 0, scape = 0; a[j] != '\0'; j++)
    {
        c[j] = tolower(b[j]);
        if (a[j] == ' ')
        {
            c[j - scape] = toupper(b[j - scape]);
            scape++;
        }
    }
    c[sizeB] = '\0';
    printf("The word in camelCase is:-> %s, and number of words are %d ", c,scape+1);
    return 0;
}