/*
    => Lab_Task_07
    => Name: Avinash Yadav
    => Reg. No.: AP22110010366


    => Brief:
            C Program to implement First Come First Serve (FCFS) scheduling algorithm


    => Algorithm:
            1. Calculate waiting time for each process
            2. Calculate turn around time for each process
            3. Calculate average waiting time and turn around time


    => Solved Example:
        Processes Arrival Time(AT)  Burst Time(BT) Completion Time(CT)  Turn-Around Time(TAT = CT - AT)  Waiting Time(WT = TAT - BT)
        P1               0               5                5                         5                                0
        P2               0               8                13                        13                               5
        P3               0               10               23                        23                               13
        P4               0               12               35                        35                               23
        P5               0               15               50                        50                               35


    => Output:
        Average Waiting Time:   15.20
        Average Turn-Around Time:   25.20

*/









#include <stdio.h>
// Calculating the completion time for each process, Time at which the process completed.
void findCompletionTime(int processes[], int n, int burst_time[], int comp_time[])
{
    // The completion time of the first process is equal to its burst time
    comp_time[0] = burst_time[0];

    // For other processes, completion time is the sum of its burst time and the completion time of the previous process
    for (int i = 1; i < n; i++)
    {
        comp_time[i] = comp_time[i - 1] + burst_time[i];
    }
}

// Calculating turn around time for each process, where Turnaround time (TAT) = Completion Time (CT) - Arrival Time (AT)
void findTurnAroundTime(int processes[], int n, int burst_time[], int comp_time[], int tat[])
{
    // Since all arrival times are 0 in our example, So TAT is the same as CT
    for (int i = 0; i < n; i++)
    {
        tat[i] = comp_time[i];
    }
}

// Calculating waiting time for each process, where Waiting time (WT) = Turnaround Time (TAT) - Burst Time (BT)
void findWaitingTime(int processes[], int n, int burst_time[], int tat[], int wait_time[])
{
    for (int i = 0; i < n; i++)
    {
        wait_time[i] = tat[i] - burst_time[i];
    }
}

// Calculating and displaying average waiting and turn around times
void findAvgTime(int processes[], int n, int burst_time[])
{
    // Arrays to store CT, TAT, and WT
    int comp_time[n], tat[n], wait_time[n];

    // Variables to store total WT and TAT
    int total_wait_time = 0, total_tat = 0;

    // Calculate completion time for each process
    findCompletionTime(processes, n, burst_time, comp_time);

    // Calculate turn around time for each process
    findTurnAroundTime(processes, n, burst_time, comp_time, tat);

    // Calculate waiting time for each process
    findWaitingTime(processes, n, burst_time, tat, wait_time);

    // Display the results
    printf("Processes   Arrival Time(AT)   Burst Time(BT)   Completion Time(CT)   Turn-Around Time(TAT)   Waiting Time(WT)\n");

    for (int i = 0; i < n; i++)
    {
        total_wait_time += wait_time[i];
        total_tat += tat[i];
        printf("    P%d ", (i + 1));
        printf("             %d ", 0);
        printf("              %d ", burst_time[i]);
        printf("               %d ", comp_time[i]);
        printf("                  %d ", tat[i]);
        printf("                  %d\n", wait_time[i]);
    }

    // Calculating and printing the average waiting time and turn around time
    printf("\nAverage Waiting Time: %.2f", (float)total_wait_time / (float)n);
    printf("\nAverage Turn-Around Time: %.2f\n", (float)total_tat / (float)n);
}








int main()
{
    // Process IDs
    int processes[] = {1, 2, 3, 4, 5};

    // Number of processes
    int n = sizeof(processes) / sizeof(processes[0]);

    // Burst time of each process
    int burst_time[] = {5, 8, 10, 12, 15};

    // Calculate and display average times
    findAvgTime(processes, n, burst_time);

    return 0;
}










///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////











/*
    => Lab_Task_07
    => Name: Avinash Yadav
    => Reg. No.: AP22110010366


    => Brief:
            C Program to implement Shortest Job First (SJF) scheduling algorithm (Non-preemptive)


    => Algorithm:
            1. Sort the processes based on burst time (BT) in ascending order.
            2. Calculate waiting time for each process.
            3. Calculate turn around time for each process.
            4. Calculate average waiting time and turn around time.


    => Solved Example:
        Processes Arrival Time(AT)  Burst Time(BT) Completion Time(CT)  Turn-Around Time(TAT = CT - AT)  Waiting Time(WT = TAT - BT)
        P1               0               5                5                         5                                0
        P2               0               8                13                        13                               5
        P3               0               10               23                        23                               13
        P4               0               12               35                        35                               23
        P5               0               15               50                        50                               35


    => Output:
        Average Waiting Time:   12.80
        Average Turn-Around Time:   21.60

*/








#include <stdio.h>

// Function to swap two values
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort the processes based on burst time (SJF criterion)
void sortProcessesByBurstTime(int processes[], int n, int burst_time[])
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Sorting based on burst time
            if (burst_time[i] > burst_time[j])
            {
                // Swap process IDs
                swap(&processes[i], &processes[j]);

                // Swap burst times
                swap(&burst_time[i], &burst_time[j]);
            }
        }
    }
}

// Function to calculate completion time for each process
void findCompletionTime(int processes[], int n, int burst_time[], int comp_time[])
{
    // Completion time for the first process is its burst time
    comp_time[0] = burst_time[0];

    // Calculate completion time for other processes
    for (int i = 1; i < n; i++)
    {
        comp_time[i] = comp_time[i - 1] + burst_time[i];
    }
}

// Function to calculate turn around time (TAT) for each process
void findTurnAroundTime(int processes[], int n, int burst_time[], int comp_time[], int tat[])
{
    // TAT = Completion Time - Arrival Time (AT), since AT = 0 for all processes, TAT = CT
    for (int i = 0; i < n; i++)
    {
        tat[i] = comp_time[i];
    }
}

// Function to calculate waiting time (WT) for each process
void findWaitingTime(int processes[], int n, int burst_time[], int tat[], int wait_time[])
{
    // WT = TAT - BT for each process
    for (int i = 0; i < n; i++)
    {
        wait_time[i] = tat[i] - burst_time[i];
    }
}

// Function to calculate average waiting time and turn around time
void findAvgTime(int processes[], int n, int burst_time[])
{
    // Arrays to store CT, TAT, and WT
    int comp_time[n], tat[n], wait_time[n];

    // Total waiting time and total turn around time
    int total_wait_time = 0, total_tat = 0;

    // Sort processes by burst time (SJF scheduling)
    sortProcessesByBurstTime(processes, n, burst_time);

    // Calculate completion time for each process
    findCompletionTime(processes, n, burst_time, comp_time);

    // Calculate turn around time for each process
    findTurnAroundTime(processes, n, burst_time, comp_time, tat);

    // Calculate waiting time for each process
    findWaitingTime(processes, n, burst_time, tat, wait_time);

    // Display process details and results
    printf("Processes   Arrival Time(AT)   Burst Time(BT)   Completion Time(CT)   Turn-Around Time(TAT)   Waiting Time(WT)\n");

    for (int i = 0; i < n; i++)
    {
        total_wait_time += wait_time[i];
        total_tat += tat[i];

        printf("P%d \t\t\t ", (i + 1));
        printf("%d \t\t\t ", 0);
        printf("%d \t\t\t ", burst_time[i]);
        printf("%d \t\t\t ", comp_time[i]);
        printf("%d \t\t\t ", tat[i]);
        printf("%d \t\t\t \n", wait_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f", (float)total_wait_time / (float)n);
    printf("\nAverage Turn-Around Time: %.2f\n", (float)total_tat / (float)n);
}

int main()
{
    // Process IDs
    int processes[] = {1, 2, 3, 4, 5};

    // Number of processes
    int n = sizeof(processes) / sizeof(processes[0]);

    // Burst time of each process
    int burst_time[] = {10, 5, 15, 8, 6};

    // Calculate and display average times
    findAvgTime(processes, n, burst_time);

    return 0;
}
