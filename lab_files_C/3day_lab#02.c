#include <stdio.h>

int main()
{
    int a;
    int numbers[10];
    printf("Enter the marks of students \n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    printf("Enter the index (roll no)of the student whose marks you want to delete \n");
    scanf("%d", &a);
    for (int i = a; i < 9; i++)
    {
        numbers[i] = numbers[i + 1];
    }
    printf("so the final marks list is \n");
    for (int i = 0; i < 9; i++)
    {
        printf("%d ", numbers[i]);
    }

    return 0;
}