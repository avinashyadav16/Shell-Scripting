//  +--------------------------------------------------------------------------------------+
//  | Implement the following CPU Scheduling algorithm using C++ programming.                |
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

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a process
// Basically for the priority scheduling algorithm,
// We require the process id represented by pid here
// then we require the priority of the process and
// lastly we require the burst time meaning the total CPU time the process will take for its execution.
struct Process
{
    int pid;
    int priority;
    int burstTime;
};

void priorityScheduling(vector<Process>& processes)
{
    // Sorting all the processes based on their priority value
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b) {
        return a.priority < b.priority;
    });

    cout << "\nOrder of Execution:\n";
    for (const auto& process : processes)
    {
        cout << "P" << process.pid << " (Priority: " << process.priority << ", Burst Time: " << process.burstTime << ")\n";
    }
}

int main()
{
    // Here we are defining the number of total processes in the ready queue that are waiting for the CPU time:
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "\n";

    // Creating an array of process in the form of structure which lists the 'n' processes in the ready queue:
    vector<Process> processes(n);
    for (int i = 0; i < n; i++)
    {
        // Taking the process ID, priority, and burst time  for each of the processes in the ready queue one by one:
        cout << "Enter the process ID, priority, and burst time for process " << i + 1 << ": ";
        cin >> processes[i].pid >> processes[i].priority >> processes[i].burstTime;
    }

    // Calling the function for the non-premptive version of the priority scheduling algorithms,
    // Where the processes with the higher priority are given the CPU time if the CPU is free at that moment.
    // It frees the CPU only when its execution is completed or the processes gets terminated.
    priorityScheduling(processes);

    return 0;
}