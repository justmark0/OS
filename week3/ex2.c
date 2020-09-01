#include <stdio.h>

void bubble_sort(int *array, int size){
    for(int i = 0 ; i < size; i++){
        for(int j = 0; j < size; j++){
            if(array[j] > array[j + 1]){
                int a = array[j];
                array[j] = array[j + 1];
                array[j + 1] = a;
            }
        }
    }
}


int main() {
    int n;
    printf("Write amount of numbers and then values:\n");
    scanf("%d", &n);
    int a[n];
    for(int i = 0 ; i < n; i++)
        scanf("%d", &a[i]);
    bubble_sort(a, n);
    printf("sorted array = ");
    for(int i = 0 ; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
