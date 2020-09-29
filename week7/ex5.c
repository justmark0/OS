#include <stdio.h>
#include <stdlib.h>

int main() {
    char **s = malloc(sizeof(char*));
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %s\n", *s);
    *s[0] = foo[0];
    printf("s[0] is %c\n", *s[0]);
    return 0;
}
