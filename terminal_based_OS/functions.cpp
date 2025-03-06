#include "functions.h"
#include "Process.h"
#include <cstdlib>
#include <ctime>
#include "ProcessManager.h"

// Define global variables
std::string USERNAME;
std::string PASSWORD;

// **Clear Screen Function**
void clearScreen() {
    std::cout << "\033[2J\033[1;1H"; // ANSI escape code for Unix/macOS
}

// **Display ASCII Art from File**
void displayAsciiArt(const std::string& folderName, const std::string& fileName) {
    fs::path fullPath = fs::current_path() / folderName / fileName;
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

// **Boot Animation Function**
void displayBootingAnimation() {
    std::string folderPath = "art_folder";

    for (int i = 0; i <= 5; i++) {
        std::string fileName = "booting_system_art_" + std::to_string(i) + ".txt";
        displayAsciiArt(folderPath, fileName);
        std::this_thread::sleep_for(std::chrono::seconds(1));
        clearScreen();
    }
}

// **Secure Password Input Function**
std::string getPassword() {
    std::string password;
    
    #ifdef _WIN32
        char ch;
        while ((ch = _getch()) != '\r') { 
            if (ch == '\b' && !password.empty()) {
                std::cout << "\b \b";
                password.pop_back();
            } else if (ch != '\b') {
                std::cout << '*';
                password += ch;
            }
        }
    #else
        struct termios oldt, newt;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~ECHO;
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);

        std::getline(std::cin, password);

        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    #endif
    
    std::cout << std::endl;
    return password;
}

// **Login Function**
void displayLogin(std::string* username, std::string* password) {
    std::cout << "Enter Username: ";
    std::getline(std::cin, *username);

    std::cout << "Enter Password: ";
    *password = getPassword();
}

// **Idle Terminal Function**
void idle(std::string* command, ProcessManager manager) {
    std::string username = USERNAME;  
    std::string systemName = "doors";

    std::cout << "Enter ? for help" << std::endl;

    while (true) {
        std::cout << username << "@" << systemName << " ~ % ";
        std::getline(std::cin, *command);

        if (*command == "exit" || *command == "x") {
            std::cout << "Shutting Down...\n";
            std::this_thread::sleep_for(std::chrono::seconds(1));
            exit(0);
        } else if (*command == "Process"){
            srand(time(nullptr));

        } else if (*command == "?"){
            displayCommands();
        } else if (*command == "c" || *command == "clear") {
            clearScreen();
        } else if (*command == "v" || *command == "version") {
            std::cout << "OS version 1.44" << std::endl;
        } else if (*command == "r" || *command == "restart") {
            std::string command;

            displayBootingAnimation();
            displayLogin(&USERNAME, &PASSWORD);

            clearScreen();
            displayAsciiArt("art_folder", "welcome_art.txt");

            idle(&command, manager);
        } else if (*command == "p ls" || *command == "P ls") {
            manager.displayProcessVector(manager.processes);
        } else if (command->substr(0, 3) == "rp ") {  // Handle "rp <name>" command
            std::string processName = command->substr(3);  // Extract process name after "rp "
            if (!processName.empty()) {
                manager.runProcess(processName);
            } else {
                std::cout << "Error: Please specify a process name.\n";
            }
        } else if (command->substr(0, 3) == "pd ") {  // Handle "pd <name>" command
            std::string processName = command->substr(3);  // Extract process name after "pd "
            if (!processName.empty()) {
                manager.displayProcessInfo(processName);
            } else {
                std::cout << "Error: Please specify a process name.\n";
            }
        } else if (*command == "TaskManager" || *command =="taskmanager") {
            manager.runTasks();
            
            
        }  else {
            std::cout << "zsh: Command not found: " << *command << std::endl;
        }
    }
}

void screenSleep(int amount){
    std::this_thread::sleep_for(std::chrono::milliseconds(amount));
}



void displayCommands() {
    std::cout << "Available Commands:\n";
    std::cout << "  exit or x            - Shut Down OS\n";
    std::cout << "  TaskManager          - Display all process running.\n";
    std::cout << "  rp <processName>     - Run a specific process\n";
    std::cout << "  pd <processName>     - Show details of a specific process\n";
    std::cout << "  p ls                 - Display the list of available processes\n";
    std::cout << "  ?                    - Show this command list\n";
    std::cout << "  clear or c           - Clear the screen\n";
    std::cout << "  version or v         - Show OS version\n";
    std::cout << "  restart or r         - Restart the program\n";
    std::cout << "--------------------------------------\n";
}


void displayProcessAnimation(){
    std::srand(std::time(0));  // Seed the random number generator
    int randomNumber = std::rand() % 2 + 1;  // Generates 1 or 2

     std::string folderPath = "art_folder";

     for (int i = 0; i <= 2; i++) {

        for (int j = 1; j<=3; j++){
            std::string fileName = "Process_" +std::to_string(randomNumber) + "_loading_" + std::to_string(j) +  ".txt"; 
            displayAsciiArt(folderPath, fileName);
            std::this_thread::sleep_for(std::chrono::seconds(1));
            clearScreen();
        }
    }


}