#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Progress.H>
#include <string>
#include <iostream>

using namespace std;

// Boot Progress Bar
Fl_Progress* progress;
float progress_value = 0.0f;

// Timer function to update progress
void update_progress(void*) {
    progress_value += 0.1f;
    if (progress_value > 1.0f) progress_value = 1.0f;
    progress->value(progress_value);
    progress->redraw();
    
    if (progress_value < 1.0f) {
        Fl::repeat_timeout(0.1, update_progress);
    }
}

// **Encapsulated Boot Animation Function**
void show_boot_animation(const string& animationLabel) {
    Fl_Window boot_window(400, 200, "Booting...");
    
    // Create Progress Bar
    progress = new Fl_Progress(50, 80, 300, 30);
    progress->minimum(0.0f);
    progress->maximum(1.0f);
    progress->value(0.0f);
    progress->label(animationLabel.c_str());
    
    boot_window.show();
    
    // Start Progress Animation
    Fl::add_timeout(0.1, update_progress);

    // Run FLTK event loop until booting is done
    while (progress_value < 1.0f) {
        Fl::wait();  // Keeps UI responsive during boot
    }
    
    boot_window.hide();  // Hide boot screen when done
}

int main() {
    
    show_boot_animation("Booting System");  // Call boot function

    // Start the main app after boot animation
    Fl_Window main_window(400, 300, "Main Application");
    main_window.show();
    
    return Fl::run();
}