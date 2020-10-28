#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main(){
    int source = open("ex1.txt", O_RDWR);
    int destination = open("ex1.memcpy.txt", O_RDWR);
    
    char *str;
    char* s;
    struct stat buff = {};
    fstat(source, &buff);
    off_t size = buff.st_size;
    truncate("ex1.memcpy.txt", size);
    s = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, source, 0);
    str = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, destination, 0);
    strcpy(str, s);
    return 0;
}
