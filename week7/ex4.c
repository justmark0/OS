#include <stdlib.h>
#include <stdio.h>
/*
– realloc() changes the size of the memory block pointed to by
ptr to size bytes. The contents will be unchanged in the range
from the start of the region up to the minimum of the old and
new sizes.
– Newly allocated memory will be uninitialized
– If ptr is NULL, the call is equivalent to malloc(size)
– If size is equal to zero, the call is equivalent to free(ptr)
– Unless ptr is NULL, it must have been returned by an earlier
call to malloc(), calloc() or realloc()

 */

int* my_realloc(int* a, size_t size){

    if(size == 0){
        free(a);
        return a;
    }
    int* a1 = malloc(size);
    if(a == NULL)
        return a;

    for(int i = 0; i < size/sizeof(int); i++){
        a1[i] = a[i];
    }
    free(a);
    return a1;
}


int main(){
    int* a;
    int n1, n2;
    printf("Write size of the array:\n");
    scanf("%d", &n1);
    printf("Your array: ");
    a = malloc(n1*sizeof(int));
    for(int i = 0 ; i < n1; i++){
        printf("%d ", a[i]);
    }
    printf("\nWrite new size of the array:");
    scanf("%d", &n2);
    a = my_realloc(a, n2*sizeof(int));
    printf("New array: ");
    for(int i = 0 ; i < n2; i++){
        printf("%d ", a[i]);
    }
    return 0;
}
/*
So I dont set values of the array because there wasn't this requirement in the task.
I got this output:

Write size of the array:
3
Your array: 7274688 7274688 0
Write new size of the array:5
New array: 7274688 7274688 0 0 -1975684891
 
 */
