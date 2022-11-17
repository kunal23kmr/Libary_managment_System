#include <stdio.h>
typedef union car
{
    char model[10];
    int speed;
} car;

int main()
{
    int n;
    printf("\nEnter the number of car:");
    scanf("%d", &n);
    printf("\n\n");
    car c[100];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the model of %d car and the MAX speed of car in kmph: ", i + 1);
        scanf("%s %d", c[i].model, &(c[i].speed));

        printf("\n");
    }
    for (int i = 0; i < n; i++)
    {
        printf("The car model of %d car: '%s' and MAX speed is '%d' kmph. \n", i + 1, c[i].model, c[i].speed);
        printf("\n\n");
    }
    return 0;
}