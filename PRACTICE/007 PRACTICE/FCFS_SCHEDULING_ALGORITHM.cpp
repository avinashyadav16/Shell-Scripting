/*
    => Brief:
            C++ Program to implement First Come First Serve (FCFS) scheduling algorithm

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

#include <bits/stdc++.h>
using namespace std;

// Calculating the completion time for each process, Time at which the process completed.
void findCompletionTime(const vector<int> &burst_time, vector<int> &comp_time)
{
    // The completion time of the first process is equal to its burst time
    comp_time[0] = burst_time[0];

    // For other processes, completion time is the sum of its burst time and the completion time of the previous process
    for (size_t i = 1; i < burst_time.size(); i++)
    {
        comp_time[i] = comp_time[i - 1] + burst_time[i];
    }
}

// Calculating turn around time for each process, where Turnaround time (TAT) = Completion Time (CT) - Arrival Time (AT)
void findTurnAroundTime(const vector<int> &comp_time, vector<int> &tat)
{
    // Since all arrival times are 0 in our example, So TAT is the same as CT
    for (size_t i = 0; i < comp_time.size(); i++)
    {
        tat[i] = comp_time[i];
    }
}

// Calculating waiting time for each process, where Waiting time (WT) = Turnaround Time (TAT) - Burst Time (BT)
void findWaitingTime(const vector<int> &burst_time, const vector<int> &tat, vector<int> &wait_time)
{
    for (size_t i = 0; i < burst_time.size(); i++)
    {
        wait_time[i] = tat[i] - burst_time[i];
    }
}

// Calculating and displaying average waiting and turn around times
void fcfs_Algo(const vector<int> &burst_time)
{
    // Arrays to store CT, TAT, and WT
    vector<int> comp_time(burst_time.size()), tat(burst_time.size()), wait_time(burst_time.size());

    // Variables to store total WT and TAT
    int total_wait_time = 0, total_tat = 0;

    // Calculate completion time for each process
    findCompletionTime(burst_time, comp_time);

    // Calculate turn around time for each process
    findTurnAroundTime(comp_time, tat);

    // Calculate waiting time for each process
    findWaitingTime(burst_time, tat, wait_time);

    // Display the results
    cout << "Processes   Arrival Time(AT)   Burst Time(BT)   Completion Time(CT)   Turn-Around Time(TAT)   Waiting Time(WT)\n";

    for (size_t i = 0; i < burst_time.size(); i++)
    {
        total_wait_time += wait_time[i];
        total_tat += tat[i];
        cout << "    P" << (i + 1) << "             " << 0 << "              " << burst_time[i] << "                        " << comp_time[i] << "                  " << tat[i] << "                  " << wait_time[i] << endl;
    }

    // Calculating and printing the average waiting time and turn around time
    cout << "\nAverage Waiting Time: " << (float)total_wait_time / burst_time.size();
    cout << "\nAverage Turn-Around Time: " << (float)total_tat / burst_time.size() << endl;
}

int main()
{
    // Process IDs
    vector<int> processes = {1, 2, 3, 4, 5};

    // Burst time of each process
    vector<int> burst_time = {5, 8, 10, 12, 15};

    // Calculate and display average times
    fcfs_Algo(burst_time);

    return 0;
}
