#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#define N 5

bool producer_sleeping = false;
bool consumer_sleeping = false;
int* buff[N];
int size = 0;

void *producer() {
    while (true) {
        if (!producer_sleeping) {
            if (size == N) {
                *(&producer_sleeping) = true;
                continue;
            }
            buff[size] = malloc(sizeof(int));
            *(buff[size]) = 1;
            if (size == 0) {
                *(&consumer_sleeping) = false;
            }
            size++;
        }
    }
}

int main() {
    pthread_t prod_ID;
    pthread_create(&prod_ID, NULL, producer, NULL);

    while (true) {
        if (!consumer_sleeping) {
            if (size == 0) {
                *(&consumer_sleeping) = true;
                continue;
            }
            *(buff[size]) = 0;
            free(buff[size]);
            if (size == N) {
                *(&consumer_sleeping) = false;
            }
            size--;
        }
    }
}

