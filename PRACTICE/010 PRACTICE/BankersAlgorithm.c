#include <stdio.h>
#define MAX_PROCESSES 5
#define MAX_RESOURCES 3

/**
 * @brief Function to calculate the need matrix, which is the difference
 *        between the max matrix and the allocation matrix.
 */
void NeedMatrix(int need[MAX_PROCESSES][MAX_RESOURCES],
                int max[MAX_PROCESSES][MAX_RESOURCES],
                int allocation[MAX_PROCESSES][MAX_RESOURCES],
                int total_processes,
                int resources)
{
    for (int i = 0; i < total_processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }
}

/**
 * @brief Function to determine if the system is in a safe state by using
 *        Banker's algorithm.
 */
int isInSafe(int processes[],
             int available[],
             int max[][MAX_RESOURCES],
             int allocation[][MAX_RESOURCES],
             int total_processes,
             int resources)
{
    int need[MAX_PROCESSES][MAX_RESOURCES];
    NeedMatrix(need, max, allocation, total_processes, resources);

    // Array to track if each process has finished
    int finish[MAX_PROCESSES] = {0};

    // To store the safe sequence of process execution
    int safeSequence[MAX_PROCESSES];

    // Available resources during each step
    int work[MAX_RESOURCES];

    // Initialize work with available resources
    for (int i = 0; i < resources; i++)
    {
        work[i] = available[i];
    }

    printf("\nInitial Available Resources: ");
    for (int i = 0; i < resources; i++)
    {
        printf("%d ", available[i]);
    }
    printf("\n");

    printf("\nMax Matrix:\n");
    for (int i = 0; i < total_processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    printf("\nAllocation Matrix:\n");
    for (int i = 0; i < total_processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }

    printf("\nNeed Matrix:\n");
    for (int i = 0; i < total_processes; i++)
    {
        for (int j = 0; j < resources; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    int count = 0;
    while (count < total_processes)
    {
        // Flag to check if a process can be executed
        int found = 0;

        for (int i = 0; i < total_processes; i++)
        {
            // If the process has not finished and its needs can be met with available resources
            if (!finish[i])
            {
                int j;
                for (j = 0; j < resources; j++)
                {
                    // If need is greater than available resources
                    if (need[i][j] > work[j])
                        break;
                }

                // If all resources needed by process i can be satisfied
                if (j == resources)
                {
                    for (int k = 0; k < resources; k++)

                        // Release resources after process execution
                        work[k] += allocation[i][k];

                    // Add process to safe sequence
                    safeSequence[count++] = i;

                    // Mark process as finished
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // If no process could be executed, the system is not in a safe state
        if (!found)
        {
            printf("\nSystem is not in a safe state.\n");
            return 0;
        }
    }

    // If system is in safe state
    printf("\nSystem is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < total_processes; i++)
    {
        printf("P%d ", safeSequence[i]);
    }
    printf("\n");

    return 1;
}

int main()
{
    int total_processes, resources;

    int max[MAX_PROCESSES][MAX_RESOURCES] = {{7, 5, 3},
                                             {3, 2, 2},
                                             {9, 0, 2},
                                             {2, 2, 2},
                                             {4, 3, 3}};

    int allocation[MAX_PROCESSES][MAX_RESOURCES] = {{0, 1, 0},
                                                    {2, 0, 0},
                                                    {3, 0, 2},
                                                    {2, 1, 1},
                                                    {0, 0, 2}};

    int available[MAX_RESOURCES];

    printf("Enter number of processes (<= 5): ");
    scanf("%d", &total_processes);
    if (total_processes > MAX_PROCESSES)
    {
        printf("Exceeds maximum allowed processes.\n");
        return -1;
    }

    printf("Enter number of resources (<= 3): ");
    scanf("%d", &resources);
    if (resources > MAX_RESOURCES)
    {
        printf("Exceeds maximum allowed resources.\n");
        return -1;
    }

    for (int i = 0; i < resources; i++)
    {
        printf("Enter available resource %d: ", i + 1);
        scanf("%d", &available[i]);
    }

    int processes[MAX_PROCESSES];
    for (int i = 0; i < total_processes; i++)
    {
        processes[i] = i;
    }

    isInSafe(processes, available, max, allocation, total_processes, resources);

    return 0;
}
