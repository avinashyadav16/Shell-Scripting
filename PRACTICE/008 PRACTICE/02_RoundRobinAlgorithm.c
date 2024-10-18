//  +--------------------------------------------------------------------------------------+
//  | Implement the following CPU Scheduling algorithm using C programming.                |
//  |                          2. Round Robin Algorithm                                    |
//  | THUMB RULE TO BE FOLLOWED: Smaller Priority Value => Higher Priority of the process  |
//  +--------------------------------------------------------------------------------------+

#include <stdio.h>

// Structure for representing a process
// Each process has a Process ID (pid), burst time, and remaining time for execution
typedef struct Process
{
    // Process ID
    int pid;

    // Total CPU time required by the process
    int burstTime;

    // Time remaining for the process to complete execution
    int remainingTime;

} Process;

// Round Robin Scheduling Algorithm
void roundRobin(Process processes[], int n, int quantum)
{
    // Total time needed to execute all processes
    int totalTime = 0; 

    // Calculating the total burst time
    for (int i = 0; i < n; i++)
    {
        totalTime += processes[i].burstTime;
    }

    int time = 0;

    // Total time passed
    // Continue execution until all processes are finished
    while (totalTime > 0)
    {
        for (int i = 0; i < n; i++)
        {
            // Check if the process still has time remaining for execution
            if (processes[i].remainingTime > 0)
            {
                // Determine the time the process will execute in this round
                // It can execute for either the time quantum or the remaining time, whichever is smaller
                int executedTime = (processes[i].remainingTime < quantum) ? processes[i].remainingTime : quantum;

                // Deduct the executed time from the remaining time
                processes[i].remainingTime -= executedTime;

                // Update the total time passed
                time += executedTime;

                // Print how long the process executed and its remaining time
                printf("P%d executed for %d units, remaining time: %d\n", processes[i].pid, executedTime, processes[i].remainingTime);

                // If the process has finished executing
                if (processes[i].remainingTime == 0)
                {
                    // Print a message indicating that the process has finished
                    printf("\t\t\t    => P%d finished\n", processes[i].pid);
                    // Reduce the total remaining time by the burst time of the finished process
                    totalTime -= processes[i].burstTime;
                }
            }
        }
    }
}

int main()
{
    // Total Number of processes
    int n;

    // Entering the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\n");

    // Array of processes
    Process processes[n];

    // Inputing the process ID and burst time for each process
    for (int i = 0; i < n; i++)
    {
        printf("Enter the process ID and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].pid, &processes[i].burstTime);

        // Initially, we will take remaining time is equal to the burst time
        processes[i].remainingTime = processes[i].burstTime;
    }
    printf("\n");

    // Time quantum (the time slice given to each process)
    int quantum;

    // Define the time quantum
    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

    printf("\n");

    // Call the Round Robin function to execute the processes
    roundRobin(processes, n, quantum);

    return 0;
}

/* OUTPUT:
------------------------------------------------------
Enter the number of processes: 4

Enter the process ID and burst time for process 1: 1 5
Enter the process ID and burst time for process 2: 2 4
Enter the process ID and burst time for process 3: 3 2
Enter the process ID and burst time for process 4: 4 1

Enter the time quantum: 2

P1 executed for 2 units, remaining time: 3
P2 executed for 2 units, remaining time: 2
P3 executed for 2 units, remaining time: 0
                            => P3 finished
P4 executed for 1 units, remaining time: 0
                            => P4 finished
P1 executed for 2 units, remaining time: 1
P2 executed for 2 units, remaining time: 0
                            => P2 finished
P1 executed for 1 units, remaining time: 0
                            => P1 finished
*/
