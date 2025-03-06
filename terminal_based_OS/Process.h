#ifndef PROCESS_H
#define PROCESS_H

#include <string>
#include <chrono>

class Process {
public:
    Process(const std::string& name);  // Constructor to set pid, name, and arrival_time

    void displayInfo() const;
    void run();  // Simulates running the process
    void updateState(const std::string& newState);
    void updateRemainingTime(const int newRemainingTime);
    void decrementRemainingTime();


    std::string getName() const { return name; }
    int getPid() const { return pid; }
    long long getArrivalTime() const { return arrival_time; }
    int getBurstTime() const {return burst_time;}
    std::string getState() const {return state; }
    int getRemainingTime() const {return remaining_time;}
    int getWaitingTime() const {return waiting_time;}
    int getMemoryRequired() const {return memory_required;}
    int getTurnaroundTime() const {return turnaround_time;}
    int getPriority() const {return priority;}

    

private:
    int pid;
    std::string name;
    long long arrival_time; // Time in milliseconds since epoch

    int burst_time;
    int priority;
    std::string state;
    int remaining_time;
    int waiting_time;
    int turnaround_time;
    int memory_required;
    bool io_operations;

    static int generateUniquePid();
    // Declaration with the default argument
    static int generateRandomValue(int min, int max, int multiple = 0);
};

#endif