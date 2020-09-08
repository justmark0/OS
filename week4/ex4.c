#include <stdio.h>
int input(char *s,int length);

int main()
{
    char buffer[32];
    char *b = buffer;
    size_t bufsize = 32;
    size_t characters;
    characters = getline(&b,&bufsize,stdin);
    system(buffer);
    return(0);
}

