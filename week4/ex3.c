#include <stdio.h>
#include <unistd.h>

int main() {
   char str[100];
   scanf("%s", &str);
   system(str);
   return 0;
}
