#include "functions.h"
#include "ProcessManager.h"

int main() {

    ProcessManager manager;
    manager.createProcess("ProcessA");
    manager.setArrivalTime("ProcessA", 0);
    manager.createProcess("ProcessB");
    manager.setArrivalTime("ProcessB", 0);


    std::string command;

    displayBootingAnimation();
    displayLogin(&USERNAME, &PASSWORD);

    clearScreen();
    displayAsciiArt("art_folder", "welcome_art.txt");

    idle(&command, manager);

    return 0;
}