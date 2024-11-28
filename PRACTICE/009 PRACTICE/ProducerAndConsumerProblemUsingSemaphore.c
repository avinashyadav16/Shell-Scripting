//  +--------------------------------------------------------------------------------------+
//  |   Write a C program to implement the Producer & consumer Problem using Semaphore.    |
//  +--------------------------------------------------------------------------------------+

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Size of Buffer
#define BUFFER_SIZE 5
// Shared Buffer
int buffer[BUFFER_SIZE];

// Positions of Producer And Consumer Pointers
int in = 0, out = 0;

// Semaphore Variables
int empty = BUFFER_SIZE; // Available Empty Slots
int full = 0;            // Available Full Slots

// Mutex Variables
int mutex = 1; // Mutual Exclusion

// Wait (decrement) a semaphore
void wait(int *sem)
{
    while (*sem <= 0)
        ; // Spinlock: Wait if semaphore is 0 or negative

    (*sem)--;
}

// Signal (increment) a semaphore
void signal(int *sem)
{
    (*sem)++;
}

// Simulating Mutex Lock
void lock_mutex()
{
    wait(&mutex);
}

// Simulating Mutex Unlock
void unlock_mutex()
{
    signal(&mutex);
}

// DISPLAYING THE IN, OUT, AND BUFFER STATUS:
void display_buffer()
{
    printf("Buffer: [ ");
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        if (buffer[i] == 0)
            printf("_ ");
        else
            printf("%d ", buffer[i]);
    }
    printf("]\n\t in = %d\n\t out = %d\n", in, out);
}

// PRODUCER:
void producer()
{
    // Wait if buffer is full
    if (empty <= 0)
    {
        printf("Buffer is full! Producer is waiting...\n");
    }

    // Decrement empty slots count
    wait(&empty);

    // Lock buffer for producing
    lock_mutex();

    // Produce an item
    static int item = 1;
    buffer[in] = item;
    printf("\nProducer produced item %d at position %d\n", item, in);
    item++;

    // Move `in` pointer in circular buffer
    in = (in + 1) % BUFFER_SIZE;

    // Display current buffer status
    display_buffer();

    // Unlock buffer
    unlock_mutex();

    // Signal that buffer has a new item
    signal(&full);
}

// CONSUMER:
void consumer()
{
    // Wait if buffer is empty
    if (full <= 0)
    {
        printf("Buffer is empty! Consumer is waiting...\n");
    }

    // Decrement full slots count
    wait(&full);

    // Lock buffer for consuming
    lock_mutex();

    // Consume an item
    int item = buffer[out];

    // Reset consumed buffer slot
    buffer[out] = 0;
    printf("\nConsumer consumed item %d from position %d\n", item, out);

    // Move `out` pointer in circular buffer
    out = (out + 1) % BUFFER_SIZE;

    // Display current buffer status
    display_buffer();

    // Unlock buffer
    unlock_mutex();

    // Signal that buffer has an empty slot
    signal(&empty);
}

int main()
{
    int choice;
    while (1)
    {
        printf("\nSelect Option:\n");
        printf("1. Producer\t 2. Consumer\t 3. Exit\n");
        printf("Enter Option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            producer();
            break;
        case 2:
            consumer();
            break;
        case 3:
            printf("Exiting from the code...\n");
            return 0;
        default:
            printf("Invalid Input Choice.\n");
        }
    }

    return 0;
}
