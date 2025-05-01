#include <iostream>
#include <fstream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

const int MAX_PROCESSES = 100;

// Structure for a Process
struct Process {
    int id;             // Process ID
    int arrival;        // Arrival time
    int burst;          // CPU burst time
    int priority;       // Priority of the process
    int remaining;      // Remaining burst time for tracking purposes
    bool completed;     // Flag to indicate if the process has finished execution
    int termination;    // The time when the process finishes its execution
    int firstResponse;  // The time when the process starts executing for the first time
};

// Structure for a Gantt Chart Block
struct GanttBlock {
    int timeElapsed;    // The time at which this block begins
    int processId;      // ID of the process that is executing at this time (or -1 for idle time)
    int cpuUsed;        // Amount of CPU time used in this block
    bool finished;      // Flag to indicate if the process in this block has finished its execution
};


// Sort by arrival time
void sortByArrival(Process p[], int n) {
    std::sort(p, p + n, [](const Process &a, const Process &b) {
        return a.arrival < b.arrival;
    });
}

// Function to clean and output the Gantt chart
void outputGanttChart(GanttBlock gantt[], int ganttSize, int testCaseNum, ofstream &outFile) {
    outFile << testCaseNum << "\n";
    for (int i = 0; i < ganttSize; ++i) {
        if (gantt[i].processId == -1) continue;

        outFile << gantt[i].timeElapsed << " " << gantt[i].processId << " " << gantt[i].cpuUsed;
        if (gantt[i].finished) outFile << "X";
        outFile << "\n";
    }
}


// Function to generate and output performance metrics
void generateMetrics(Process p[], int count, int totalTime, int cpuBusy, ofstream &outFile) {
    int totalTurnaround = 0;
    int totalWaiting = 0;
    int totalResponse = 0;

    for (int i = 0; i < count; ++i) {
        int turnaround = p[i].termination - p[i].arrival;
        int waiting = turnaround - p[i].burst;
        int response = p[i].firstResponse - p[i].arrival;

        totalTurnaround += turnaround;
        totalWaiting += waiting;
        totalResponse += response;

        outFile << "Process " << p[i].id << ": ";
        outFile << "Waiting Time = " << waiting << "ns, ";
        outFile << "Turnaround Time = " << turnaround << "ns, ";
        outFile << "Response Time = " << response << "ns\n";
    }

    outFile << "CPU Utilization = " << (cpuBusy * 100) / totalTime << "%\n";
    outFile << "Throughput = " << count << " / " << totalTime
            << " = " << (float)count / totalTime << " processes/ns\n";
    outFile << "Average Waiting Time = " << totalWaiting / count << "ns\n";
    outFile << "Average Turnaround Time = " << totalTurnaround / count << "ns\n";
    outFile << "Average Response Time = " << totalResponse / count << "ns\n";
}

// Function to run the FCFS scheduling algorithm
void runFCFS(Process p[], int count, int testCaseNum, ofstream &outFile) {
    // Sort processes by arrival time
    sortByArrival(p, count);

    // Initialize Gantt chart and other variables
    GanttBlock gantt[MAX_PROCESSES * 2];
    int ganttSize = 0;
    int time = 0;
    int totalTurnaround = 0;
    int totalWaiting = 0;
    int totalResponse = 0;
    int cpuBusy = 0;

    // Run the FCFS logic
    for (int i = 0; i < count; ++i) {
        // Handle CPU idle time if current process arrives after the CPU is idle
        if (time < p[i].arrival) {
            // If CPU is idle, record idle time in the Gantt chart
            gantt[ganttSize++] = {time, -1, p[i].arrival - time, false};
            time = p[i].arrival;  // Move time forward to the arrival time of the current process
        }

        // Mark the first response of the process
        p[i].firstResponse = time;

        // Record the process execution in the Gantt chart array
        gantt[ganttSize++] = {time, p[i].id, p[i].burst, true};
        time += p[i].burst;  // Increase time by the process's burst time

        // Update process information after execution
        p[i].termination = time;
        p[i].completed = true;
        cpuBusy += p[i].burst;  // Add the process burst time to CPU usage
    }

    // The total time is the time after the last process finishes
    int totalTime = time;

    // Output the Gantt chart and metrics
    outputGanttChart(gantt, ganttSize, testCaseNum, outFile);
    generateMetrics(p, count, totalTime, cpuBusy, outFile);
}

// Function to run the SJF scheduling algorithm (non-preemptive)
void runSJF(Process p[], int count, int testCaseNum, ofstream &outFile) {
    // Initialize Gantt chart and other variables
    GanttBlock gantt[MAX_PROCESSES * 2];
    int ganttSize = 0;
    int time = 0;
    int cpuBusy = 0;
    int completed = 0;

    // Run the SJF logic
    while (completed < count) {
        int idx = -1;
        int minBurst = INT_MAX;

        // Find the process with the shortest burst time that has arrived
        for (int i = 0; i < count; ++i) {
            if (!p[i].completed && p[i].arrival <= time && p[i].burst < minBurst) {
                minBurst = p[i].burst;
                idx = i;
            }
        }

        // If no process is ready, increment time (CPU is idle)
        if (idx == -1) {
            time++;
            continue;
        }

        // Schedule the selected process
        p[idx].firstResponse = time;
        gantt[ganttSize++] = {time, p[idx].id, p[idx].burst, true};
        time += p[idx].burst;
        p[idx].termination = time;
        p[idx].completed = true;
        completed++;
        cpuBusy += p[idx].burst;
    }

    int totalTime = time;

    // Output the Gantt chart and metrics
    outputGanttChart(gantt, ganttSize, testCaseNum, outFile);
    generateMetrics(p, count, totalTime, cpuBusy, outFile);
}

// Function to run the SRTF scheduling algorithm (preemptive)
void runSRTF(Process p[], int count, int testCaseNum, ofstream &outFile) {
    // Initialize Gantt chart and other variables
    GanttBlock gantt[MAX_PROCESSES * 100];
    int ganttSize = 0;
    int time = 0;
    int completed = 0;
    int cpuBusy = 0;
    int lastProcess = -1;

    // Run the SRTF logic
    while (completed < count) {
        int idx = -1;
        int minRemaining = INT_MAX;

        // Look for the process with the shortest remaining time that has arrived
        for (int i = 0; i < count; ++i) {
            if (!p[i].completed && p[i].arrival <= time && p[i].remaining < minRemaining && p[i].remaining > 0) {
                minRemaining = p[i].remaining;
                idx = i;
            }
        }

        // If no process is ready, increment time (CPU is idle)
        if (idx == -1) {
            // CPU idle
            if (lastProcess != -1) {
                gantt[ganttSize++] = {time, -1, 1, false};
                lastProcess = -1;
            }
            time++;
            continue;
        }

        // Record first response if this is the first time the process is running
        if (p[idx].remaining == p[idx].burst) {
            p[idx].firstResponse = time;
        }

        // Add to Gantt chart if process changes
        if (lastProcess != p[idx].id) {
            gantt[ganttSize++] = {time, p[idx].id, 1, false};
        } else {
            gantt[ganttSize - 1].cpuUsed++;
        }

        // Simulate 1 time unit of execution
        p[idx].remaining--;
        time++;
        cpuBusy++;
        lastProcess = p[idx].id;

        // If process finishes
        if (p[idx].remaining == 0) {
            p[idx].termination = time;
            p[idx].completed = true;
            gantt[ganttSize - 1].finished = true;
            completed++;
        }
    }

    int totalTime = time;

    // Output the Gantt chart and metrics
    outputGanttChart(gantt, ganttSize, testCaseNum, outFile);
    generateMetrics(p, count, totalTime, cpuBusy, outFile);
}

// Function to run the Priority scheduling algorithm (preemptive)
void runPriority(Process p[], int count, int testCaseNum, ofstream &outFile) {
    // Initialize Gantt chart and other variables
    GanttBlock gantt[MAX_PROCESSES * 2];
    int ganttSize = 0;
    int time = 0;
    int completed = 0;
    int cpuBusy = 0;
    int lastProcess = -1;

    while (completed < count) {
        int idx = -1; // Start with no process selected
        int highestPrio = INT_MIN;

        // Select process with highest priority that has arrived and is not completed
        for (int i = 0; i < count; ++i) {
            if (!p[i].completed && p[i].arrival <= time && p[i].priority > highestPrio) {
                highestPrio = p[i].priority;
                idx = i;
            }
        }

        // If no process is ready, increment time (CPU is idle)
        if (idx == -1) {
            // CPU idle
            if (lastProcess != -1) {
                gantt[ganttSize++] = {time, -1, 1, false}; // Record idle time
                lastProcess = -1;
            }
            time++;
            continue;
        }

        // Mark the first response time if it's the first time this process runs
        if (p[idx].remaining == p[idx].burst) {
            p[idx].firstResponse = time;
        }

        // Add to Gantt chart if process changes (similar to SRTF)
        if (lastProcess != p[idx].id) {
            gantt[ganttSize++] = {time, p[idx].id, 1, false}; // Record process start
        } else {
            gantt[ganttSize - 1].cpuUsed++; // If same process, just increase CPU usage
        }

        // Simulate 1 time unit of execution
        p[idx].remaining--;
        time++;
        cpuBusy++;
        lastProcess = p[idx].id;

        // If the process finishes
        if (p[idx].remaining == 0) {
            p[idx].termination = time;
            p[idx].completed = true;
            gantt[ganttSize - 1].finished = true; // Mark as finished in Gantt chart
            completed++;
        }

        // After executing 1 unit of time, check for higher priority processes (preemption)
    }

    int totalTime = time;

    // Output the Gantt chart and metrics
    outputGanttChart(gantt, ganttSize, testCaseNum, outFile);
    generateMetrics(p, count, totalTime, cpuBusy, outFile);
}

// Function to run the RR scheduling algorithm
void runRR(Process p[], int count, int testCaseNum, int quantum, ofstream &outFile) {
    // Initialize Gantt chart and other variables
    GanttBlock gantt[MAX_PROCESSES * 100];
    int ganttSize = 0;
    int time = 0;
    int completed = 0;
    int cpuBusy = 0;

    int readyQueue[MAX_PROCESSES * 100];   // Manual implementation of a queue
    int front = 0, rear = 0;               // Pointers for queue front and rear
    bool inQueue[MAX_PROCESSES] = {false}; // Tracks if a process is already in queue

    sortByArrival(p, count);               // Sort processes by arrival time for easier tracking
    int nextArrival = 0;                   // Index of next arriving process

    // Run the RR logic
    while (completed < count) {
        // Add newly arrived processes to the FRONT of the queue
        int temp[MAX_PROCESSES];           // Temporary array to collect new arrivals
        int tempSize = 0;

        // Collect all processes that have just arrived at current time
        while (nextArrival < count && p[nextArrival].arrival <= time) {
            if (!inQueue[nextArrival] && !p[nextArrival].completed) {
                temp[tempSize++] = nextArrival;
                inQueue[nextArrival] = true;
            }
            nextArrival++;
        }

        // Sort new arrivals by arrival time
        for (int i = 0; i < tempSize - 1; ++i) {
            for (int j = i + 1; j < tempSize; ++j) {
                if (p[temp[i]].arrival > p[temp[j]].arrival) {
                    int t = temp[i];
                    temp[i] = temp[j];
                    temp[j] = t;
                }
            }
        }

        // Insert new arrivals to the FRONT of the ready queue
        for (int i = tempSize - 1; i >= 0; --i) {
            // Shift queue to the right to make space at front
            for (int j = rear; j > front; --j) {
                readyQueue[j] = readyQueue[j - 1];
            }
            readyQueue[front] = temp[i]; // Insert at front
            rear++;
        }

        // If no process is ready, CPU is idle
        if (front == rear) {
            gantt[ganttSize++] = {time, -1, 1, false}; // Record idle period
            time++;
            continue;
        }

        // Dequeue and run the process at the front
        int idx = readyQueue[front++];     // Get process index
        inQueue[idx] = false;              // Mark it as not in queue

        // Record first run time (used for response time)
        if (p[idx].burst == p[idx].remaining)
            p[idx].firstResponse = time;

        int execTime = min(quantum, p[idx].remaining); // Time slice to run
        gantt[ganttSize++] = {time, p[idx].id, execTime, false}; // Add to Gantt

        time += execTime;
        cpuBusy += execTime;
        p[idx].remaining -= execTime;

        // Check for new arrivals during execution
        tempSize = 0;
        while (nextArrival < count && p[nextArrival].arrival <= time) {
            if (!inQueue[nextArrival] && !p[nextArrival].completed) {
                temp[tempSize++] = nextArrival;
                inQueue[nextArrival] = true;
            }
            nextArrival++;
        }

        // Sort the newly arrived processes by arrival time again
        for (int i = 0; i < tempSize - 1; ++i) {
            for (int j = i + 1; j < tempSize; ++j) {
                if (p[temp[i]].arrival > p[temp[j]].arrival) {
                    int t = temp[i];
                    temp[i] = temp[j];
                    temp[j] = t;
                }
            }
        }

        // Insert those arrivals at the front of the queue
        for (int i = tempSize - 1; i >= 0; --i) {
            for (int j = rear; j > front; --j) {
                readyQueue[j] = readyQueue[j - 1];
            }
            readyQueue[front] = temp[i];
            rear++;
        }

        // Check if current process finished
        if (p[idx].remaining == 0) {
            p[idx].termination = time;
            p[idx].completed = true;
            gantt[ganttSize - 1].finished = true;
            completed++;
        } else {
            // If not finished, return it to the end of the queue
            readyQueue[rear++] = idx;
            inQueue[idx] = true;
        }
    }

    int totalTime = time;

    // Output the Gantt chart and metrics
    outputGanttChart(gantt, ganttSize, testCaseNum, outFile);
    generateMetrics(p, count, totalTime, cpuBusy, outFile);
}

int main() {
    // Read the number of test cases
    int T;
    cin >> T;
    ofstream outFile("output.txt");

    // Loop through each test case
    for (int t = 1; t <= T; ++t) {
        int X;
        string algo;
        int quantum = -1;

        // If the algorithm is RR, get the quantum value
        cin >> X >> algo;
        if (algo == "RR") cin >> quantum;

        // Get arrival, burst, and priority for each process
        Process p[MAX_PROCESSES];
        for (int i = 0; i < X; ++i) {
            cin >> p[i].arrival >> p[i].burst;
            
            while (true) {
                cin >> p[i].priority;
                if (p[i].priority >= -20 && p[i].priority <= 20)
                    break;
                cout << "Invalid priority\n";   // Prompt for valid input
            }

            p[i].id = i + 1;
            p[i].remaining = p[i].burst;
            p[i].completed = false;
        }

        // Run the selected scheduling algorithm
        if (algo == "FCFS") {
            runFCFS(p, X, t, outFile);
        } else if (algo == "SJF") {
            runSJF(p, X, t, outFile);
        } else if (algo == "SRTF") {
            runSRTF(p, X, t, outFile);
        } else if (algo == "P") {
            runPriority(p, X, t, outFile);
        } else if (algo == "RR") {
            runRR(p, X, t, quantum, outFile);
        } else {
            outFile << algo << " not implemented.\n";
        }    
    }

    outFile.close();
    return 0;
}