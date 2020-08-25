#include <stdio.h>
#include <stdlib.h>
int n, i;

void print_borders(){
    for(int j = 0 ; j < ((2*n - 1) - (i * 2 + 1))/2; j++)
        printf(" ");
}


int main(int argc, char *argv[]) {
    char *p;
    n = strtol(argv[1], &p, 10);
    for(i = 0 ; i < n ;i ++){
        print_borders();
        for(int j = 0; j < i*2 + 1; j++)
            printf("*");
        print_borders();
        printf("\n");
    }
    return 0;
}
