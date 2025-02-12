#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <filesystem>
#ifdef _WIN32
    #include <conio.h> // For _getch() on Windows
#else
    #include <termios.h>
    #include <unistd.h>
#endif

namespace fs = std::filesystem;
using namespace std;

std::string USERNAME, PASSWORD;


void displayAsciiArt(const std::string& folderName, const std::string& fileName) {
    // Get the path where the executable is located
    fs::path execPath = fs::current_path();  
    fs::path fullPath = execPath / folderName / fileName;

    std::ifstream file(fullPath);
    if (!file) {
        std::cerr << "❌ Error: Could not open file: " << fullPath << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape code to clear screen
}

void displayBootingAnimation(){
    std::string folderPath = "art_folder";  // Folder where the .txt file is located
    std::string fileName = "booting_system_art.txt"; // File containing ASCII art

    displayAsciiArt("art_folder", "booting_system_art_0.txt");
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait 3 seconds
    clearScreen();

    displayAsciiArt("art_folder", "booting_system_art_1.txt");
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait 3 seconds
    clearScreen();

    displayAsciiArt("art_folder", "booting_system_art_2.txt");
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait 3 seconds
    clearScreen();

    displayAsciiArt("art_folder", "booting_system_art_3.txt");
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Wait 3 seconds
    clearScreen();

    displayAsciiArt("art_folder", "booting_system_art_4.txt");
    std::this_thread::sleep_for(std::chrono::seconds(3)); // Wait 3 seconds
    clearScreen();

    displayAsciiArt("art_folder", "booting_system_art_5.txt");
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait 3 seconds
    clearScreen();

}

// Function to securely get password input (hides user input with '*')
string getPassword() {
    std::string password;
    
    #ifdef _WIN32
        char ch;
        while ((ch = _getch()) != '\r') { // Read characters until Enter is pressed
            if (ch == '\b' && !password.empty()) { // Handle backspace
                std::cout << "\b \b";
                password.pop_back();
            } else if (ch != '\b') {
                std::cout << '*';
                password += ch;
            }
        }
    #else
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt); // Get terminal attributes
        newt = oldt;
        newt.c_lflag &= ~ECHO; // Disable echo
        tcsetattr(STDIN_FILENO, TCSANOW, &newt); // Apply new settings

        std::getline(std::cin, password); // Read password input

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // Restore terminal settings
    #endif
    
    std::cout << std::endl; // Move to the next line
    return password;
}

// Function to prompt for username and password
void displayLogin(std::string* username, std::string* password) {
    std::cout << "Enter Username: ";
    std::getline(std::cin, *username); // Store input in username pointer

    std::cout << "Enter Password: ";
    *password = getPassword(); // Store hidden password input
}


void idle(std::string* command) {
    std::string username = USERNAME;  // Change if needed
    std::string systemName = "doors";

    while (true) {  // Infinite loop to mimic an idle terminal
        std::cout << username << "@" << systemName << " ~ % ";
        std::getline(std::cin, *command);  // Store user input

        if (*command == "exit") { // Exit condition
            std::cout << "Exiting terminal...\n";
            break;
        }

        std::cout << "Command received: " << *command << std::endl;  // Mimic processing
    }
}


int main() {
    string command;

    displayBootingAnimation();

    displayLogin(&USERNAME, &PASSWORD);

    displayAsciiArt("art_folder", "welcome_art.txt");

    idle(&command);
    

    return 0;
}