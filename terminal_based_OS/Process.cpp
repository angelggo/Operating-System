#include "Process.h"
#include <iostream>
#include <unordered_set>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <thread>
#include <chrono>
#include "functions.h"


static std::unordered_set<int> used_pids;

// Generate a unique PID for each process between 1 and 10000
int Process::generateUniquePid() {
    int new_pid;
    do {
        new_pid = rand() % 10000 + 1;  
    } while (used_pids.find(new_pid) != used_pids.end());
    used_pids.insert(new_pid);
    return new_pid;
}


// Definition without the default argument
int Process::generateRandomValue(int min, int max, int multiple) {
    int randomValue = rand() % (max - min + 1) + min;

    if (multiple > 0) {
        // Ensure the value is a multiple of 'multiple'
        randomValue = (randomValue / multiple) * multiple;
    }

    return randomValue;
}

// Constructor
Process::Process(const std::string& process_name) 
    : name(process_name), state("Ready"), waiting_time(0), turnaround_time(0) {
    pid = generateUniquePid();

    // Get current system time
    auto now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(now);
    arrival_time = static_cast<long long>(time_t_now);  // Store as timestamp if needed

    // Initialize randomized values
    burst_time = generateRandomValue(1, 100, 10);           // Random burst time between 1 and 100 ms
    priority = generateRandomValue(1, 10);              // Random priority between 1 and 10
    remaining_time = burst_time;
    memory_required = generateRandomValue(4, 512);      // Random memory required between 4 MB and 512 MB
    io_operations = generateRandomValue(0, 1);          // Random boolean (0 or 1)
    
}

// Display process information
void Process::displayInfo() const {

    // Convert arrival_time from timestamp to readable format
    std::time_t time = static_cast<std::time_t>(arrival_time);
    std::tm* time_info = std::localtime(&time);

    std::ostringstream time_stream;
    time_stream << std::put_time(time_info, "%I:%M %p");

    //Displa all the information in a formated cout 
    std::cout << "Process Name: " << name
              << "\nPID: " << pid
              << "\nArrival Time: " << time_stream.str()
              << "\nBurst Time: " << burst_time << " ms"
              << "\nPriority: " << priority
              << "\nState: " << state
              << "\nRemaining Time: " << remaining_time << " ms"
              << "\nWaiting Time: " << waiting_time << " ms"
              << "\nTurnaround Time: " << turnaround_time << " ms"
              << "\nMemory Required: " << memory_required << " MB"
              << "\nI/O Operations: " << (io_operations ? "Yes" : "No")
              << "\n-------------------------------------\n";
}

void Process::run() {
    std::cout << "Process " << name << " (PID: " << pid << ") is now running...\n";
    updateState("Running");

    for (int i = 0; i < burst_time; ++i) {

        std::this_thread::sleep_for(std::chrono::milliseconds(1));
        remaining_time--;

        // Display relevant attributes every 10ms
        if (i % 10 == 0) {

            //SLeep timer that way it creates an animation effect, making illusion the process is running.
            
            std::this_thread::sleep_for(std::chrono::seconds(1));

            std::cout << "Process: " << name
                      << " | PID: " << pid
                      << " | Remaining Time: " << remaining_time << " ms"
                      << " | Priority: " << priority
                      << " | State: " << state
                      << " | Memory Required: " << memory_required
                      << std::endl;
        }
    }

    std::cout << "Process " << name << " has finished execution.\n";
    updateState("Terminated");
}

// Updates the state of the process
void Process::updateState(const std::string& newState) {
    state = newState;
    std::cout << "Process " << name << " changed state to: " << state << "\n";
}

void Process::updateRemainingTime(const int newRemainingTime){
    remaining_time = newRemainingTime;
    
}

void Process::decrementRemainingTime(){
    remaining_time -= 10;
}