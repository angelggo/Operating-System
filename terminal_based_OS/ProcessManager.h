#ifndef PROCESSMANAGER_H
#define PROCESSMANAGER_H

#include "Process.h"
#include <vector>
#include <string>

class ProcessManager {
public:
    void createProcess(const std::string& name);
    void displayProcessInfo(const std::string& name) const;
    void displayAllProcesses() const;
    void runProcess(const std::string& name);  

private:
    std::vector<Process> processes;
};

#endif