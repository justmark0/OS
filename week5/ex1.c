#include <stdio.h>
#include <pthread.h>

void *func(void* vararg) {
    printf("Thread ID: %lu, cool text\n", pthread_self());
}

int main() {
    const int n = 5;
    pthread_t thread;
    for (int i = 0; i < n; i++) {
        pthread_create(&thread, NULL, func, NULL);
        printf("Created thread %lu\n", thread);
        pthread_join(thread, NULL);
    }
    return 0;
}

