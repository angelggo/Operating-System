#include "functions.h"
#include <FL/Fl.H>
#include <FL/Fl_Progress.H>
#include <iostream>

// Global main window definition
Fl_Window* main_window;

// Boot Progress Bar
Fl_Progress* progress;
float progress_value = 0.0f;

// **Boot Animation Function**
void show_boot_animation(const std::string& animationLabel) {
    Fl_Window boot_window(400, 200, "Booting...");
    boot_window.color(FL_WHITE);

    // Create Progress Bar
    progress = new Fl_Progress(50, 80, 300, 30);
    progress->minimum(0.0f);
    progress->maximum(1.0f);
    progress->value(0.0f);
    progress->label(animationLabel.c_str());

    boot_window.show();

    while (progress_value < 1.0f) {
        progress_value += 0.1f;
        progress->value(progress_value);
        progress->redraw();
        Fl::wait(0.1);
    }

    boot_window.hide();
}

// **Show Main Window After Login**
void show_main_window(Fl_Widget* w, void*) {
    Fl_Window* login_window = (Fl_Window*)w->window();
    login_window->hide();
    Fl::check();

    main_window->show();
    Fl::check();
}

// **Login Window Function**
void show_login_window() {
    Fl_Window* login_window = new Fl_Window(400, 250, "Login");
    login_window->color(FL_WHITE);

    Fl_Input* username_input = new Fl_Input(150, 50, 200, 30, "Username:");
    Fl_Input* password_input = new Fl_Input(150, 100, 200, 30, "Password:");
    password_input->type(FL_SECRET_INPUT);

    Fl_Button* login_button = new Fl_Button(150, 170, 100, 30, "Login");
    login_button->callback(show_main_window);

    login_window->end();
    login_window->show();
}