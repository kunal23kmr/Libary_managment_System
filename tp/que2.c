#include <stdio.h>
#include <windows.h>

int main() {
    if (CreateProcess(NULL, NULL, NULL, NULL, FALSE, 0, NULL, NULL, NULL, NULL) ||CreateProcess(NULL, NULL, NULL, NULL, FALSE, 0, NULL, NULL, NULL, NULL) ) {
        CreateProcess(NULL, NULL, NULL, NULL, FALSE, 0, NULL, NULL, NULL, NULL);
    }
    
    printf("1");
    
    return 0;
}
