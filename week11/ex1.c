#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main(){
    int FILE = open("ex1.txt", O_RDWR);
    char *s;
    char text[] = "This is a nice day";
    int size = strlen(text);
    truncate("ex1.txt", size);
    s = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, FILE, 0);
    if (s == MAP_FAILED){
        printf("mmap error\n");
    }
    strcpy(s, text);
    return 0;
}
