#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(){
    char text[] = "Hello";
    setvbuf(stdout, NULL,_IOFBF, 0);
    for (int i = 0; i < strlen(text); i++){
        printf("%c\n", text[i]);
        sleep(1);
    }
    return 0;
}
