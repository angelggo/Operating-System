#include "ProcessManager.h"
#include "functions.h"
#include <iostream>
#include <iomanip>

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

void ProcessManager::displayAllProcesses() const {
    if (processes.empty()) {
        std::cout << "No processes available.\n";
        return;
    }

    std::cout << std::setw(20) << std::left << "Process Name" 
              << std::setw(10) << "PID" 
              << std::setw(20) << "Arrival Time" << std::endl;
    std::cout << "-----------------------------------------------------------\n";

    for (const auto& process : processes) {
        std::cout << std::setw(20) << std::left << process.getName()
                  << std::setw(10) << process.getPid()
                  << std::setw(20) << process.getArrivalTime() << std::endl;
    }
    std::cout << "-----------------------------------------------------------\n";
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