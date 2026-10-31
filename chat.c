#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// The worker function executed by both threads
void* worker(void* arg) {
    char* message = (char*) arg;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    char* msg1 = "Hello from Thread 1!";
    char* msg2 = "Hello from Thread 2!";

    // Spawn both threads simultaneously. No locks, pure chaos.
    pthread_create(&thread1, NULL, worker, (void*) msg1);
    pthread_create(&thread2, NULL, worker, (void*) msg2);

    // Force main to wait until both finish so the program doesn't die early
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
