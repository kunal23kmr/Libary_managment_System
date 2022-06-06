#include <stdio.h>

int main()
{
    char word[20];
    printf("Enter the word\n");
    scanf("%[^\n]s", word);
    int length = 0, A;
    for (int i = 0; word[i] != '\0'; i++)
    {
        length++;
    }
    char invWord[length];
    for (int i = 0; i < length; i++)
    {
        invWord[i] = word[length - i - 1];
    }
    for (int i = 0; i < length; i++)
    {
        if (word[i] != invWord[i])
        {
            A = 0;
            break;
        }
        else
            A = 1;
    }
    (A == 1) ? (printf("The word is Palindrome")) : (printf("Not palindrome"));
    return 0;
}