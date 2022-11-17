#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    char *A;
    A = malloc(sizeof(char) * 100);
    printf("\n");
    printf("Enter the sentence: ");
    scanf("%[^\n]s", A);
    int length = strlen(A);
    printf("\n");
    for (int i = 0; i < length; i++)
    {
        if (A[i] != ' ')
        {
            printf("%c", A[i]);
        }
        else if (A[i] == ' ')
        {
            printf("\n");
        }
    }
    printf("\n");
    return 0;
}
