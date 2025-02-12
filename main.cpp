#include "functions.h"
#include <FL/Fl.H>

int main() {
    Fl::scheme("plastic");  // Ensures proper rendering on macOS

    show_boot_animation("Starting System...");

    // Create the global main window
    main_window = new Fl_Window(700, 500, "Main Window");
    Fl_Box* welcome_text = new Fl_Box(0, 200, 700, 100, "Welcome to Doors!");
    welcome_text->labelsize(24);
    welcome_text->align(FL_ALIGN_CENTER);
    main_window->end();

    show_login_window();

    return Fl::run();
}