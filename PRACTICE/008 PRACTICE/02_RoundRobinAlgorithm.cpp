//  +--------------------------------------------------------------------------------------+
//  | Implement the following CPU Scheduling algorithm using C++ programming.              |
//  |                          2. Round Robin Algorithm                                    |
//  | THUMB RULE TO BE FOLLOWED: Smaller Priority Value => Higher Priority of the process  |
//  +--------------------------------------------------------------------------------------+

#include <iostream>
#include <vector>

using namespace std;

// Structure for representing a process
// Each process has a Process ID (pid), burst time, and remaining time for execution
struct Process
{
    int pid;          // Process ID
    int burstTime;    // Total CPU time required by the process
    int remainingTime; // Time remaining for the process to complete execution
};

// Round Robin Scheduling Algorithm
void roundRobin(vector<Process>& processes, int quantum)
{
    int totalTime = 0; 

    // Calculating the total burst time
    for (const auto& process : processes)
    {
        totalTime += process.burstTime;
    }

    int time = 0;

    // Total time passed
    // Continue execution until all processes are finished
    while (totalTime > 0)
    {
        for (auto& process : processes)
        {
            // Check if the process still has time remaining for execution
            if (process.remainingTime > 0)
            {
                int executedTime = (process.remainingTime < quantum) ? process.remainingTime : quantum;

                // Deduct the executed time from the remaining time
                process.remainingTime -= executedTime;

                // Update the total time passed
                time += executedTime;

                // Print how long the process executed and its remaining time
                cout << "P" << process.pid << " executed for " << executedTime << " units, remaining time: " << process.remainingTime << endl;

                // If the process has finished executing
                if (process.remainingTime == 0)
                {
                    // Print a message indicating that the process has finished
                    cout << "\t\t\t    => P" << process.pid << " finished" << endl;
                    // Reduce the total remaining time by the burst time of the finished process
                    totalTime -= process.burstTime;
                }
            }
        }
    }
}

int main()
{
    int n;

    // Entering the number of processes
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << endl;

    vector<Process> processes(n);

    // Inputting the process ID and burst time for each process
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the process ID and burst time for process " << i + 1 << ": ";
        cin >> processes[i].pid >> processes[i].burstTime;

        // Initially, we will take remaining time is equal to the burst time
        processes[i].remainingTime = processes[i].burstTime;
    }
    cout << endl;

    int quantum;

    // Define the time quantum
    cout << "Enter the time quantum: ";
    cin >> quantum;
    cout << endl;

    // Call the Round Robin function to execute the processes
    roundRobin(processes, quantum);

    return 0;
}
