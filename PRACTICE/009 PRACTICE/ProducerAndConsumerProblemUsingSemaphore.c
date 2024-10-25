//              AVINASH YADAV    |   AP22110010366       |       B. Tech. CSE - L
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

// =========>>> EXAMPLE OUTPUT <<<=========
/*
Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 1

Producer produced item 1 at position 0
Buffer: [ 1 _ _ _ _ ]
         in = 1
         out = 0

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 2

Consumer consumed item 1 from position 0
Buffer: [ _ _ _ _ _ ]
         in = 1
         out = 1

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 1

Producer produced item 2 at position 1
Buffer: [ _ 2 _ _ _ ]
         in = 2
         out = 1

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 1

Producer produced item 3 at position 2
Buffer: [ _ 2 3 _ _ ]
         in = 3
         out = 1

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 1

Producer produced item 4 at position 3
Buffer: [ _ 2 3 4 _ ]
         in = 4
         out = 1

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 1

Producer produced item 5 at position 4
Buffer: [ _ 2 3 4 5 ]
         in = 0
         out = 1

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 2

Consumer consumed item 2 from position 1
Buffer: [ _ _ 3 4 5 ]
         in = 0
         out = 2

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 1

Producer produced item 6 at position 0
Buffer: [ 6 _ 3 4 5 ]
         in = 1
         out = 2

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 2

Consumer consumed item 3 from position 2
Buffer: [ 6 _ _ 4 5 ]
         in = 1
         out = 3

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 1

Producer produced item 7 at position 1
Buffer: [ 6 7 _ 4 5 ]
         in = 2
         out = 3

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 2

Consumer consumed item 4 from position 3
Buffer: [ 6 7 _ _ 5 ]
         in = 2
         out = 4

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 2

Consumer consumed item 5 from position 4
Buffer: [ 6 7 _ _ _ ]
         in = 2
         out = 0

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 1

Producer produced item 8 at position 2
Buffer: [ 6 7 8 _ _ ]
         in = 3
         out = 0

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 1

Producer produced item 9 at position 3
Buffer: [ 6 7 8 9 _ ]
         in = 4
         out = 0

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 2

Consumer consumed item 6 from position 0
Buffer: [ _ 7 8 9 _ ]
         in = 4
         out = 1

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 1

Producer produced item 10 at position 4
Buffer: [ _ 7 8 9 10 ]
         in = 0
         out = 1

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 2

Consumer consumed item 7 from position 1
Buffer: [ _ _ 8 9 10 ]
         in = 0
         out = 2

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 2

Consumer consumed item 8 from position 2
Buffer: [ _ _ _ 9 10 ]
         in = 0
         out = 3

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 2

Consumer consumed item 9 from position 3
Buffer: [ _ _ _ _ 10 ]
         in = 0
         out = 4

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 2

Consumer consumed item 10 from position 4
Buffer: [ _ _ _ _ _ ]
         in = 0
         out = 0

Select Option:
1. Producer      2. Consumer     3. Exit
Enter Option: 3
Exiting from the code...
*/