//  +--------------------------------------------------------------------------------------+
//  |   Write a C++ program to implement the Producer & consumer Problem using Semaphore.  |
//  +--------------------------------------------------------------------------------------+

#include <bits/stdc++.h>
using namespace std;

// Size of Buffer
#define BUFFER_SIZE 5
// Shared Buffer
vector<int> buffer(BUFFER_SIZE, 0);

// Positions of Producer And Consumer Pointers
int in = 0, out = 0;

// Semaphore Variables
int empty_slots = BUFFER_SIZE; // Available Empty Slots
int full = 0;                  // Available Full Slots

// Mutex and Condition Variables
mutex mtx;
condition_variable cv_empty, cv_full;

// DISPLAYING THE IN, OUT, AND BUFFER STATUS:
void display_buffer()
{
    cout << "Buffer: [ ";
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        if (buffer[i] == 0)
            cout << "_ ";
        else
            cout << buffer[i] << " ";
    }
    cout << "]\n\t in = " << in << "\n\t out = " << out << endl;
}

// PRODUCER:
void producer()
{
    unique_lock<mutex> lock(mtx);

    // Wait if buffer is full
    cv_empty.wait(lock, []
                  { return empty_slots > 0; });

    // Produce an item
    static int item = 1;
    buffer[in] = item;
    cout << "\nProducer produced item " << item << " at position " << in << endl;
    item++;

    // Move `in` pointer in circular buffer
    in = (in + 1) % BUFFER_SIZE;

    // Display current buffer status
    display_buffer();

    // Update semaphore variables
    empty_slots--;
    full++;

    // Notify consumer
    cv_full.notify_one();
}

// CONSUMER:
void consumer()
{
    unique_lock<mutex> lock(mtx);

    // Wait if buffer is empty
    cv_full.wait(lock, []
                 { return full > 0; });

    // Consume an item
    int item = buffer[out];

    // Reset consumed buffer slot
    buffer[out] = 0;
    cout << "\nConsumer consumed item " << item << " from position " << out << endl;

    // Move `out` pointer in circular buffer
    out = (out + 1) % BUFFER_SIZE;

    // Display current buffer status
    display_buffer();

    // Update semaphore variables
    full--;
    empty_slots++;

    // Notify producer
    cv_empty.notify_one();
}

int main()
{
    int choice;
    while (true)
    {
        cout << "\nSelect Option:\n";
        cout << "1. Producer\t 2. Consumer\t 3. Exit\n";
        cout << "Enter Option: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            producer();
            break;
        case 2:
            consumer();
            break;
        case 3:
            cout << "Exiting from the code...\n";
            return 0;
        default:
            cout << "Invalid Input Choice.\n";
        }
    }

    return 0;
}
