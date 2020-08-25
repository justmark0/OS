#include <stdio.h>
#include <string.h>

int main() {
    char a[1000];
    char b[1000];
    scanf("%s", a);
    int n = strlen(a);
    for(int i = 0; i < n; i++){
        b[i] = a[n - i - 1];
    }
    printf("%s\n", b);
    return 0;
}
