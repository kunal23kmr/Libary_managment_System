#include <stdio.h>

int main()
{
    FILE *f1, *f2, *f3,*f4;
    char file1[200],file2[200],buffer[400];
    f1 = fopen("File_1.txt", "r");
    fgets(file1,200,f1);
    printf("\n\nThe content of file 1 is:\n%s\n\n",file1);
    f2 = fopen("File_2.txt", "r");
    fgets(file2,200,f2);
    printf("The content of file 2 is:\n%s\n\n",file2);
    remove("File_3.txt");
    f3 = fopen("File_3.txt", "a");    
    //inputing in file3
    fputs(file1,f3);
    fputs(file2,f3);
    fclose(f3);
    f4=fopen("File_3.txt","r");
    fgets(buffer,400,f4);
    printf("The content of file merged file:\n%s\n\n",buffer);
    fclose(f1);
    fclose(f2);
    
    return 0;
}