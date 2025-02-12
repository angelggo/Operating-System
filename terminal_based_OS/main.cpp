#include "functions.h"

int main() {
    std::string command;

    displayBootingAnimation();
    displayLogin(&USERNAME, &PASSWORD);

    clearScreen();
    displayAsciiArt("art_folder", "welcome_art.txt");

    idle(&command);
    return 0;
}