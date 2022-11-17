#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void replaceword()
{
    FILE *f, *f2;
    char word[100], ch, read[100], replace[100];
    int word_len, i, p = 0;
    f = fopen("file.txt", "a");
    fclose(f);
    f = fopen("file.txt", "r");
    f2 = fopen("replace.txt", "w+");
    if (f == NULL || f2 == NULL)
    {
        printf("cant open");
        exit(0);
    }
    puts("file content: \n");
    while (1)
    {
        ch = fgetc(f);
        if (ch == EOF)
        {
            break;
        }
        printf("%c", ch);
    }
    puts("\nenter word to find: ");
    fgets(word, 100, stdin);
    word[strlen(word) - 1] = word[strlen(word)];
    puts("Enter the word to replace it with :");
    fgets(replace, 100, stdin);
    replace[strlen(replace) - 1] = replace[strlen(replace)];
    fprintf(f2, "%s - %s\n", word, replace);
    rewind(f);
    while (!feof(f))
    {
        fscanf(f, "%s", read);
        if (strcmp(read, word) == 0)
        {
            strcpy(read, replace);
        }
        fprintf(f2, "%s ", read);
    }
    rewind(f2);
    while (1)
    {
        ch = fgetc(f2);
        if (ch == EOF)
        {
            break;
        }
        printf("%c", ch);
    }
    fclose(f);
    fclose(f2);
}
void main()
{
    replaceword();
}