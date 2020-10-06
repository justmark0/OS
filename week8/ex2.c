#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <string.h>

int main() {
    int* a;
    for(int i = 0 ; i < 10; i++){
        int num_of_ints = (((i+ 1) * 1000000) / sizeof(int)); // + 10 magabytes each iteration
        a = realloc(a, sizeof(int) * num_of_ints);
        memset(a, 0, sizeof(int) * num_of_ints);
        sleep(1);
    }
    return 0;
}

/*
Ex 2:
Swappouts and swappins stayed the same, free memory decreased by about 10 megabytes each second.
Output:
procs -----------memory---------- ---swap-- -----io---- -system-- ------cpu-----
 r  b   swpd   free   buff  cache   si   so    bi    bo   in   cs us sy id wa st
 2  0      0 3200140  82736 2493132    0    0    82    30  270  690  6  3 91  0  0
 1  0      0 3199328  82736 2493204    0    0     0     0  809 1720  1  1 98  0  0
 1  0      0 3198700  82736 2493204    0    0     0     0  968 2122  1  1 97  0  0
 1  0      0 3197768  82736 2493236    0    0     0     0 1550 3486  3  2 96  0  0
 0  0      0 3198356  82744 2493228    0    0     0   228  814 1772  1  1 97  0  0
 1  0      0 3197524  82744 2493124    0    0     0     0  650 1315  1  1 98  0  0
 1  0      0 3196452  82744 2493124    0    0     0     0  724 1407  1  1 98  0  0
 1  0      0 3195388  82744 2492888    0    0     0     0  661 1404  1  1 98  0  0
 1  0      0 3194592  82744 2492752    0    0     0     0  639 1370  1  1 98  0  0
[1]  - 7130 done       ./ex2my
 1  0      0 3202412  82744 2493908    0    0     0     0 1743 3869  2  3 95  0  0


Ex 3:
Physical and virtual memory is increased by about 100M.
*/
