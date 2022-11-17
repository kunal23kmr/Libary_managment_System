#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct node
{
    int val;
    struct node *next;
} node;

void insert(struct node **head, int value)
{
    node *new = NULL;
    new = (node *)malloc(sizeof(node));

    if (new == NULL)
    {
        printf("Failed to enter the value");
    }

    new->val = value;
    new->next = *head;
    *head = new;
}
int main()
{
    int size, input;
    node *head = NULL;

    printf("\n\nEnter size of list: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &input);
        insert(&head, input);
    }

    printf("The required linked list is: \n");
    printf("head-> ");
    int a = size;
    while (head)
    {
        printf("%d", head->val);
        head = head->next;
        if (a > 1)
        {
            printf("-> ");
        }
        a--;
    }
}
