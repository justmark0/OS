#include <stdio.h>

int main() {
    FILE *devRandom = fopen("/dev/random", "rb");
    char string[21];
    fread(string, sizeof(char), 20, devRandom);
    string[20] = '\0';
    printf("%s", string);
    return 0;
}
