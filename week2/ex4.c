#include <stdio.h>

void swap(int *a, int *b)
{
    int p;
    p  = *b;
    *b = *a;
    *a = p;
}

int main(int argc,char* argv[])
{
    int a, b;
    scanf("%d %d", &a, &b);
    swap(&a, &b);
    printf("%d %d", a, b);
    return 0;
}

