#include <stdio.h>
#include <malloc.h>

int main() {
    int n;
    printf("Write size of the array:\n");
    scanf("%d", &n);
    int* a = malloc(n*sizeof(int));
    for(int i = 0 ; i < n ; i++){
        a[i] = i + 1;
        printf("%d ", a[i]);
    }
    return 0;
}
