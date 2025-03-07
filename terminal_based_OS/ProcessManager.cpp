#include "ProcessManager.h"
#include "functions.h"
#include <iostream>
#include <algorithm>  // For sorting
#include <vector>
#include <unordered_set>

void ProcessManager::createProcess(const std::string& name) {
    Process new_process(name);
    processes.push_back(new_process);
    std::cout << "Process \"" << name << "\" created.\n";
}

void ProcessManager::displayProcessInfo(const std::string& name) const {
    for (const auto& process : processes) {
        if (process.getName() == name) {
            process.displayInfo();
            return;
        }
    }
    std::cout << "Process \"" << name << "\" not found.\n";
}

void ProcessManager::runProcess(const std::string& name) {
    for (auto& process : processes) {
        if (process.getName() == name) {
            std::cout << "Starting process: " << name << std::endl;
            process.run();  // Runs the process simulation
            return;
        }
    }
    std::cout << "Process \"" << name << "\" not found.\n";
}

void ProcessManager::moveProcessesToReadyQueue() {
    // Track existing PIDs in the ready queue to prevent duplicates
    std::unordered_set<int> readyPIDs;
    std::priority_queue<Process, std::vector<Process>, CompareProcess> tempQueue = readyQueue;

    // Extract PIDs from the current ready queue
    while (!tempQueue.empty()) {
        readyPIDs.insert(tempQueue.top().getPid());
        tempQueue.pop();
    }

    // Move only "Ready" state processes that are NOT already in the ready queue
    for (const Process& p : processes) {  
        if (p.getState() == "Ready" && readyPIDs.find(p.getPid()) == readyPIDs.end()) { 
            readyQueue.push(p); // Push into the priority queue (auto-sorted by burst time)
            std::cout << "[READY] " << p.getName() << " (PID: " << p.getPid() << ") moved to Ready Queue.\n";
        }
    }

    std::cout << "All new 'Ready' processes moved to Ready Queue (sorted by burst time).\n";
}


void ProcessManager::displayProcessVector(const std::vector<Process>& processes) {
    if (processes.empty()) {
        std::cout << "No processes available in the vector.\n";
        return;
    }

    std::cout << std::setw(15) << std::left << "Process Name"
              << std::setw(10) << "PID"
              << std::setw(20) << "Arrival Time"
              << std::setw(15) << "Burst Time"
              << std::setw(10) << "State"
              << std::setw(15) << "Remaining Time"
              << std::setw(15) << "Waiting Time"
              << std::setw(20) << "Turnaround Time"
              << std::setw(15) << "Memory Req."
              << std::endl;

    std::cout << std::string(140, '-') << "\n";

    for (const auto& process : processes) {
        std::cout << std::setw(15) << std::left << process.getName()
                  << std::setw(10) << process.getPid()
                  << std::setw(20) << process.getArrivalTime()
                  << std::setw(15) << process.getBurstTime()
                  << std::setw(10) << process.getState()
                  << std::setw(15) << process.getRemainingTime()
                  << std::setw(15) << process.getWaitingTime()
                  << std::setw(20) << process.getTurnaroundTime()
                  << std::setw(15) << process.getMemoryRequired()
                  << std::endl;
    }

    std::cout << std::string(140, '-') << "\n";
}

void ProcessManager::runTasks() {
    int processCounter = 0;
    cycles = 0;
    
    while (cycles < 33) {
        clearScreen();
        screenSleep(1000);


        //cheks if 5 cycles have past if so, then creates new process and displays all proces information
        //aswell as a message indicating process creation was sucessfull.
        if (cycles % 10 == 0) {
            processCounter++;
            std::string processName = "Process_" + std::to_string(processCounter);
            createProcess(processName);
            setArrivalTime(processName, cycles);
            moveProcessesToReadyQueue();


            // Display cycle information and process status
            clearScreen();
            std::cout << "Cycle: " << cycles << "\n";
            displayProcesesWhileExecution();
        
            // Output the currently running process
            std::cout << "\nNew Process Created: " << processName<< "\n";


            screenSleep(3000);
        }

        // Extract the process with the shortest remaining time from the ready queue
        Process currentRunningProcess = extractShortestRemainingTimeProcess();

        // run the current process which is the process with the lowest ammount of remainingtime;
        //What this does is peretty much just decrement the remaiing time as a simulation it is underestood
        //that when a process is running the ramiaingrunningtime would lower.
        runProcess(currentRunningProcess);
        cycles ++;
        incrementWaitingTimeForReadyProcesses();

        // If the process still has remaining time, push it back into the ready queue
        if (currentRunningProcess.getRemainingTime() > 0) {

            // Display cycle information and process status
            clearScreen();
            
            
            std::cout << "Cycle: " << cycles << "\n";
            displayProcesesWhileExecution();
            // Output the currently running process
            std::cout << "\nCurrently Running Process: " << currentRunningProcess.getName() << " (PID: " << currentRunningProcess.getPid() << ")\n";

            screenSleep(1000);



            currentRunningProcess.updateState("Ready");
            readyQueue.push(currentRunningProcess);  // Re-push it if it still needs to run



            
        } else {
            // If the process is finished (remaining time is 0), update its state to "Terminated"
            currentRunningProcess.updateState("Terminated");
            for (Process& p : processes) { // Use reference (&) to modify the actual object
                if (p.getPid() == currentRunningProcess.getPid()) {
                    p.updateState("Terminated");
                    p.setTurnAroundTime(p.getBurstTime() + p.getWaitingTime());
                    break;            // Stop searching after finding it
                }
            }

            // Output the terminated process
            // Display cycle information and process status
            clearScreen();
            std::cout << "Cycle: " << cycles << "\n";
            displayProcesesWhileExecution();

            std::cout << "\nTerminated Process: " << currentRunningProcess.getName() << " (PID: " << currentRunningProcess.getPid() << ")\n";
            screenSleep(2500);
        }
    }

    std::cout << "\nAverage Waiting time: " << std::to_string(getAverageWaitingTime()) 
            << "\n" << "Average Turnaround time: " << std::to_string(getAverageTurnAroundTime()) << "\n";
}


void ProcessManager::runProcess(Process& process) {

    // Decrement the remaining time and update its state
        process.decrementRemainingTime();
        process.updateState("Running");
        for (Process& p : processes) { // Use reference (&) to modify the actual object
            if (p.getPid() == process.getPid()) {
                p.decrementRemainingTime();
                p.updateState("Running");
                break;            // Stop searching after finding it
            }
        }
}

void ProcessManager::displayProcesesWhileExecution(){

     // Display all processes at the top
        std::cout << std::left
                  << std::setw(15) << "Process Name"
                  << std::setw(8) << "PID"
                  << std::setw(15) << "State"
                  << std::setw(15) << "Burst Time"
                  << std::setw(18) << "Remaining Time"
                  << std::setw(15) << "Priority"
                  << std::setw(15) << "Memory Req."
                  << std::setw(15) << "Waiting Time"
                  << std::setw(15) << "Turnaround Time"
                  << std::setw(20) << "Arrival Time"
                  << "\n--------------------------------------------------------------------------------------------------------------------------------\n";

    for (Process& p : processes) {
            std::cout << std::setw(15) << p.getName()
                      << std::setw(8) << p.getPid()
                      << std::setw(15) << p.getState()
                      << std::setw(15) << p.getBurstTime()
                      << std::setw(18) << p.getRemainingTime()
                      << std::setw(15) << p.getPriority()
                      << std::setw(15) << p.getMemoryRequired()
                      << std::setw(15) << p.getWaitingTime()
                      << std::setw(15) << p.getTurnaroundTime()
                      << std::setw(20) << p.getArrivalTime()
                      << "\n";
        }
    
}


Process ProcessManager::extractShortestRemainingTimeProcess() {
    if (readyQueue.empty()) {
        throw std::runtime_error("Ready queue is empty, no process available.");
    }

    // Find the process with the shortest remaining time
    std::vector<Process> tempStorage;
    Process shortestRemainingTimeProcess = readyQueue.top();
    readyQueue.pop();  // Remove the assumed shortest process

    while (!readyQueue.empty()) {
        Process current = readyQueue.top();
        readyQueue.pop();

        if (current.getRemainingTime() < shortestRemainingTimeProcess.getRemainingTime()) {
            tempStorage.push_back(shortestRemainingTimeProcess); // Save the previous one
            shortestRemainingTimeProcess = current; // Update to the new shortest
        } else {
            tempStorage.push_back(current);
        }
    }

    // Push back all the other processes into the queue (except the one being extracted)
    for (Process& p : tempStorage) {
        readyQueue.push(p);
    }

    return shortestRemainingTimeProcess; // Return the process with the shortest remaining time
}

void ProcessManager::setArrivalTime(std::string processName, int amt){
    for (Process& p : processes) { // Use reference (&) to modify the actual object
            if (p.getName() == processName) {
                p.setArrivalTime(amt);
                break;            // Stop searching after finding it
            }
        }
}

void ProcessManager::setTurnAroundTime(std:: string processName, int amt){
    for (Process& p : processes) { // Use reference (&) to modify the actual object
            if (p.getName() == processName) {
                p.setTurnAroundTime(amt);
                break;            // Stop searching after finding it
            }
        }
}


void ProcessManager::setWaitingTime(std:: string processName, int amt){
    for (Process& p : processes) { // Use reference (&) to modify the actual object
            if (p.getName() == processName) {
                p.setWaitingTime(amt);
                break;            // Stop searching after finding it
            }
        }
}


void ProcessManager::incrementWaitingTimeForReadyProcesses() {
    std::priority_queue<Process, std::vector<Process>, CompareProcess> tempQueue;
    
    // Process each element in readyQueue
    while (!readyQueue.empty()) {
        Process p = readyQueue.top();  // Get the top process
        readyQueue.pop();  // Remove it from the queue
        
        // Increment waiting time if the process is in the "Ready" state
        if (p.getState() == "Ready") {
            p.setWaitingTime(p.getWaitingTime() + 1);  // Increment by 1

            for (Process& pro : processes) { // Use reference (&) to modify the actual object
            if (pro.getName() == p.getName()) {
                pro.setWaitingTime(pro.getWaitingTime() + 1);
                break;            // Stop searching after finding it
            }
        }

        }

        // Store the modified process in the temporary queue
        tempQueue.push(p);
    }

    // Restore the modified queue back into readyQueue
    readyQueue = std::move(tempQueue);
    

}

float ProcessManager:: getAverageWaitingTime(){
    int totalWaitTime = 0;
    int totalNumberOfProcess = 0;
    float averageWaitingTime;

    for (Process& p : processes) { 
        totalNumberOfProcess ++;
        int currentProcessWaitTime = p.getWaitingTime();
        totalWaitTime += currentProcessWaitTime;
    }

    averageWaitingTime = (float)totalWaitTime/totalNumberOfProcess;
    return averageWaitingTime;
        
}

float ProcessManager::getAverageTurnAroundTime(){
    int totalAverateTurnAroundTime = 0;
    int totalNumberOfProcess = 0;
    float averageTurnAroundTime;

    for (Process& p : processes) { 
        totalNumberOfProcess ++;
        int currentProcessTurnAroundTime = p.getTurnaroundTime();
        totalAverateTurnAroundTime += currentProcessTurnAroundTime;
    }

    averageTurnAroundTime = (float)totalAverateTurnAroundTime / totalNumberOfProcess;
    return averageTurnAroundTime;

}
