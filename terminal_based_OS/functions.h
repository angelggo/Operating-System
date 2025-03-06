#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <filesystem>
#include "ProcessManager.h"


#ifdef _WIN32
    #include <conio.h> // For Windows input handling
#else
    #include <termios.h>
    #include <unistd.h>
#endif

namespace fs = std::filesystem;

// Global variables for login details
extern std::string USERNAME;
extern std::string PASSWORD;

// Function declarations
void clearScreen();
void displayAsciiArt(const std::string& folderName, const std::string& fileName);
void displayBootingAnimation();
std::string getPassword();
void displayLogin(std::string* username, std::string* password);
void idle(std::string* command, ProcessManager manager);
void displayCommands();
void displayProcessAnimation();
void screenSleep(int amount);


#endif // FUNCTIONS_H