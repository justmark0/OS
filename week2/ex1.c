#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    printf("Integer max = %d\nFloat max = %f\nDouble max = %f\n", i, f, d);
    printf("Integer size = %d\nFloat size = %d\nDouble size = %d", sizeof(i), sizeof(f), sizeof(d));
    return 0;
}
