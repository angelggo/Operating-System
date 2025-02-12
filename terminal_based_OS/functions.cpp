#include "functions.h"

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
void idle(std::string* command) {
    std::string username = USERNAME;  
    std::string systemName = "doors";

    while (true) {
        std::cout << username << "@" << systemName << " ~ % ";
        std::getline(std::cin, *command);

        if (*command == "exit") {
            std::cout << "Exiting terminal...\n";
            exit(0);
        }

        std::cout << "Command received: " << *command << std::endl;
    }
}