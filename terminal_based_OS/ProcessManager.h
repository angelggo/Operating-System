#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include "Process.h"
#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <iomanip>
#include <type_traits>

// Comparator for Priority Queue (Sorts by shortest burst time)
struct CompareProcess {
    bool operator()(const Process &a, const Process &b) {
        return a.getBurstTime() > b.getBurstTime();  // Min-Heap (Shortest Burst Time First)
    }
};

class ProcessManager {
public:
    template <typename Container>
    void displayAllProcesses(const Container& processes) const;

    int cycles = 0;
    void createProcess(const std::string& name);  
    void displayProcessInfo(const std::string& name) const;
    void runProcess(const std::string& name);  
    void moveProcessesToReadyQueue();
    void displayProcessVector(const std::vector<Process>& processes);
    void runTasks();
    void runProcess(Process& process);
    void displayProcesesWhileExecution();
    Process extractShortestRemainingTimeProcess();

    std::vector<Process> processes;
    std::priority_queue<Process, std::vector<Process>, CompareProcess> readyQueue;
    std::queue<Process> waitingQueue;
    std::queue<Process> runningQueue;
};


#endif // PROCESSMANAGER