#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Box.H>
#include <string>

// Function Declarations
void show_boot_animation(const std::string& animationLabel);
void show_main_window(Fl_Widget* w, void*);
void show_login_window();

extern Fl_Window* main_window; // Declaring global main window

#endif