#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main() {
    int* a;
    for(int i = 0 ; i < 10; i++){
        int num_of_ints = (((i+ 1) * 1000000) / sizeof(int)); // + 10 magabytes each iteration
        a = realloc(a, sizeof(int) * num_of_ints);
        memset(a, 0, sizeof(int) * num_of_ints);
	struct rusage usage;
        getrusage(RUSAGE_SELF,&usage);
        printf("Max: %ld\n", usage.ru_maxrss);
        sleep(1);
    }
    return 0;
}

/*
Output of thr program:

Max: 4508
Max: 4508
Max: 4508
Max: 5124
Max: 6180
Max: 7236
Max: 8028
Max: 9028
Max: 10084
Max: 11140
*/

