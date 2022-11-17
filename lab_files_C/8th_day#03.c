#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
void update(int *a, int *b)
{
    int t1, t2;
    t1 = *a + *b;
    t2 = abs(*a - *b);
    *a = t1;
    *b = t2;
    printf("So the updated value is:\n");
    Beep(2000,200);
}

int main()
{
    int a, b;
    int *pa = &a, *pb = &b;
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);
    return 0;
}
