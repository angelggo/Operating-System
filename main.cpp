#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <iostream>

// Callback function for the button
void button_callback(Fl_Widget* w, void* data) {
    std::cout << "Button clicked!" << std::endl;
}

int main(int argc, char **argv) {
    Fl_Window window(400, 300, "FLTK Example");  // Create window
    Fl_Button button(150, 130, 100, 50, "Send");  // Create button
    button.callback(button_callback);  // Assign callback function
    window.show(argc, argv);  // Show window
    return Fl::run();  // Run event loop
}