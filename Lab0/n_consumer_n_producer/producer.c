#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <pthread.h>
#include "shared.h"

void *producer(void *arg) {
    int item;
    int id = *((int *)arg);  // Get producer id
    for (int i = 0; i < 10; i++) {  // Produce 10 items for this example
        item = rand() % 100;  // Produce an item

        // Check if the buffer is full
        if (sem_trywait(empty) != 0) {
            printf("Producer %d waiting, buffer is full...\n", id);
            sem_wait(empty);  // Wait for an empty slot
        }

        pthread_mutex_lock(mutex);  // Lock the buffer

        printf("Producer %d arrived, buffer before: ", id);
        print_buffer("before");  // Print buffer before adding item

        // Add item to the buffer
        buffer[*count] = item;
        printf("Producer %d produced: %d\n", id, item);
        (*count)++;

        printf("Buffer after: ");
        print_buffer("after");  // Print buffer after adding item

        pthread_mutex_unlock(mutex);  // Unlock the buffer
        sem_post(full);  // Signal that there’s a new full slot

        usleep(200000);  // Simulate time taken to produce
    }
    return NULL;
}

int main() {
    setup_shared_memory();

    int n = 3;  // Set the number of producers
    pthread_t producers[n];
    int ids[n];

    // Create producer threads
    for (int i = 0; i < n; i++) {
        ids[i] = i + 1;
        pthread_create(&producers[i], NULL, producer, &ids[i]);
    }

    // Wait for all producers to finish
    for (int i = 0; i < n; i++) {
        pthread_join(producers[i], NULL);
    }

    cleanup_shared_memory();
    return 0;
}
