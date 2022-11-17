#include <stdio.h>

int main()
{
    FILE *ptr;
    ptr = fopen("labFILE.txt", "r");
    int wordCount = 0, spaceCount = 0, lineCount = 1;

    char readDATA[400];

    if (ptr != NULL)
    {
        printf("\nFile is Opened...\n\n");
        while (fgets(readDATA, 400, ptr) != NULL)
        {
            int i = 0, temp1 = 0, temp2 = 0, j = 0;
            printf("%s", readDATA);
            while (readDATA[i] != '\0')
            {
                if (readDATA[i] == ' ')
                {
                    spaceCount++;
                    temp1++;
                }
                else if (readDATA[i] == '\n')
                {
                    lineCount++;
                    break;
                }

                if (j < i)
                {
                    j = i;
                }
                while (((readDATA[j] > 64 && readDATA[j] < 91) || (readDATA[j] > 96 && readDATA[j] < 123)) && temp1)
                {
                    temp2++, j++;
                }

                if (temp2)
                {
                    wordCount++, temp2 = 0, temp1 = 0;
                }
                i++;
            }
        }
    }
    else
    {
        printf("There is an error in opening...\n");
    }
    printf("\nWord Count=%d\nSpaceCount=%d\nLineCount=%d", wordCount, spaceCount, lineCount);
    fclose(ptr);
    return 0;
}