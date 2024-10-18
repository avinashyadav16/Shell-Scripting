// AVINASH YADAV    |   AP22110010366       |       B. Tech. CSE - L
//  +--------------------------------------------------------------------------------------+
//  | Implement the following CPU Scheduling algorithm using C programming.                |
//  |                   1. Priority Scheduling Algorithm                                   |
//  | THUMB RULE TO BE FOLLOWED: Smaller Priority Value => Higher Priority of the process  |
//  +--------------------------------------------------------------------------------------+

/*
Brief Explanation With Example:
-------------------------------

PID     PRIORITY    BURST TIME
P1      3           10
P2      1           1
P3      4           2
P4      5           1
P5      2           5

Order of Execution:
P2 (Priority: 1, Burst Time: 1)     =>  Since the priority of P2 process is 1 which is smallest among all the process, therefore it is given the highest priority.
P5 (Priority: 2, Burst Time: 5)     =>  P5 has second smallest priority
P1 (Priority: 3, Burst Time: 10)    =>  P1 will be executed next as its priority is at the third position
P3 (Priority: 4, Burst Time: 2)     =>  P3 will follow after the execution of P1
P4 (Priority: 5, Burst Time: 1)     =>  The process P4 will be executed at the last as its priority value is greatest, so it will be executed at the last.
*/

#include <stdio.h>

// Structure to represent a process
// Basically for the priority scheduling algorithm,
// We require the process id represented by pid here
// then we require the priority of the process and
// lastly we require the burst time meaning the total CPU time the process will take for its execution.
typedef struct Process
{
    int pid;
    int priority;
    int burstTime;
} Process;

void priorityScheduling(Process processes[], int n)
{
    // Sorting all the process present in the ready queue based on thier priority value
    // Means if a process has smaller priority value that means it has higher priority for its execution than the process with smaller priority value
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (processes[i].priority > processes[j].priority)
            {
                // Swap processes
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    printf("\nOrder of Execution:\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d (Priority: %d, Burst Time: %d)\n", processes[i].pid, processes[i].priority, processes[i].burstTime);
    }
}

int main()
{
    // Here we are defining the number of total processes in the ready queue that are waiting for the CPU time:
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("\n");

    // Creating an array of process in the form of structure which lists the 'n' processes in the ready queue:
    Process processes[n];
    for (int i = 0; i < n; i++)
    {
        // Taking the process ID, priority, and burst time  for each of the processes in the ready queue one by one:
        printf("Enter the process ID, priority, and burst time for process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].pid, &processes[i].priority, &processes[i].burstTime);
    }

    // Calling the function for the non-premptive version of the priority scheduling algorithms,
    // Where the processes with the higher priority are given the CPU time if the CPU is free at that moment.
    // It frees the CPU only when its execution is completed or the processes gets terminated.
    priorityScheduling(processes, n);

    return 0;
}

/* OUTPUT:
---------------------------------------------------------------------
Enter the number of processes: 5

Enter the process ID, priority, and burst time for process 1: 1 3 10
Enter the process ID, priority, and burst time for process 2: 2 1 1
Enter the process ID, priority, and burst time for process 3: 3 4 2
Enter the process ID, priority, and burst time for process 4: 4 5 1
Enter the process ID, priority, and burst time for process 5: 5 2 5

Order of Execution:
P2 (Priority: 1, Burst Time: 1)
P5 (Priority: 2, Burst Time: 5)
P1 (Priority: 3, Burst Time: 10)
P3 (Priority: 4, Burst Time: 2)
P4 (Priority: 5, Burst Time: 1)

*/