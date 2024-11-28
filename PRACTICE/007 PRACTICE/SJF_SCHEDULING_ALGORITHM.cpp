/*
    => Lab_Task_07
    => Name: Avinash Yadav
    => Reg. No.: AP22110010366


    => Brief:
            C++ Program to implement Shortest Job First (SJF) scheduling algorithm (Non-preemptive)


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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to swap two values
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Function to sort the processes based on burst time (SJF criterion)
void sortProcessesByBurstTime(vector<int> &processes, vector<int> &burst_time)
{
    int n = processes.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Sorting based on burst time
            if (burst_time[i] > burst_time[j])
            {
                // Swap process IDs
                swap(processes[i], processes[j]);

                // Swap burst times
                swap(burst_time[i], burst_time[j]);
            }
        }
    }
}

// Function to calculate completion time for each process
void findCompletionTime(const vector<int> &burst_time, vector<int> &comp_time)
{
    int n = burst_time.size();
    // Completion time for the first process is its burst time
    comp_time[0] = burst_time[0];

    // Calculate completion time for other processes
    for (int i = 1; i < n; i++)
    {
        comp_time[i] = comp_time[i - 1] + burst_time[i];
    }
}

// Function to calculate turn around time (TAT) for each process
void findTurnAroundTime(const vector<int> &comp_time, vector<int> &tat)
{
    int n = comp_time.size();
    // TAT = Completion Time - Arrival Time (AT), since AT = 0 for all processes, TAT = CT
    for (int i = 0; i < n; i++)
    {
        tat[i] = comp_time[i];
    }
}

// Function to calculate waiting time (WT) for each process
void findWaitingTime(const vector<int> &burst_time, const vector<int> &tat, vector<int> &wait_time)
{
    int n = burst_time.size();
    // WT = TAT - BT for each process
    for (int i = 0; i < n; i++)
    {
        wait_time[i] = tat[i] - burst_time[i];
    }
}

// Function to calculate average waiting time and turn around time
void SJF_Algo(vector<int> &processes, vector<int> &burst_time)
{
    int n = processes.size();
    // Vectors to store CT, TAT, and WT
    vector<int> comp_time(n), tat(n), wait_time(n);

    // Total waiting time and total turn around time
    int total_wait_time = 0, total_tat = 0;

    // Sort processes by burst time (SJF scheduling)
    sortProcessesByBurstTime(processes, burst_time);

    // Calculate completion time for each process
    findCompletionTime(burst_time, comp_time);

    // Calculate turn around time for each process
    findTurnAroundTime(comp_time, tat);

    // Calculate waiting time for each process
    findWaitingTime(burst_time, tat, wait_time);

    // Display process details and results
    cout << "Processes   Arrival Time(AT)   Burst Time(BT)   Completion Time(CT)   Turn-Around Time(TAT)   Waiting Time(WT)\n";

    for (int i = 0; i < n; i++)
    {
        total_wait_time += wait_time[i];
        total_tat += tat[i];

        cout << "P" << (i + 1) << "\t\t\t " << 0 << "\t\t\t " << burst_time[i] << "\t\t\t " << comp_time[i] << "\t\t\t " << tat[i] << "\t\t\t " << wait_time[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << (float)total_wait_time / n;
    cout << "\nAverage Turn-Around Time: " << (float)total_tat / n << "\n";
}

int main()
{
    // Process IDs
    vector<int> processes = {1, 2, 3, 4, 5};

    // Burst time of each process
    vector<int> burst_time = {10, 5, 15, 8, 6};

    // Calculate and display average times
    SJF_Algo(processes, burst_time);

    return 0;
}
