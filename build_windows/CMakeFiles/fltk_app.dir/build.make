# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System\build_windows"

# Include any dependencies generated for this target.
include CMakeFiles/fltk_app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/fltk_app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/fltk_app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fltk_app.dir/flags.make

CMakeFiles/fltk_app.dir/codegen:
.PHONY : CMakeFiles/fltk_app.dir/codegen

CMakeFiles/fltk_app.dir/main.cpp.obj: CMakeFiles/fltk_app.dir/flags.make
CMakeFiles/fltk_app.dir/main.cpp.obj: CMakeFiles/fltk_app.dir/includes_CXX.rsp
CMakeFiles/fltk_app.dir/main.cpp.obj: C:/Users/angel/Documents/School/Spring\ 2025/Operating\ Systems/Project/Operating-System/main.cpp
CMakeFiles/fltk_app.dir/main.cpp.obj: CMakeFiles/fltk_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System\build_windows\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fltk_app.dir/main.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fltk_app.dir/main.cpp.obj -MF CMakeFiles\fltk_app.dir\main.cpp.obj.d -o CMakeFiles\fltk_app.dir\main.cpp.obj -c "C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System\main.cpp"

CMakeFiles/fltk_app.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/fltk_app.dir/main.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System\main.cpp" > CMakeFiles\fltk_app.dir\main.cpp.i

CMakeFiles/fltk_app.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/fltk_app.dir/main.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System\main.cpp" -o CMakeFiles\fltk_app.dir\main.cpp.s

CMakeFiles/fltk_app.dir/functions.cpp.obj: CMakeFiles/fltk_app.dir/flags.make
CMakeFiles/fltk_app.dir/functions.cpp.obj: CMakeFiles/fltk_app.dir/includes_CXX.rsp
CMakeFiles/fltk_app.dir/functions.cpp.obj: C:/Users/angel/Documents/School/Spring\ 2025/Operating\ Systems/Project/Operating-System/functions.cpp
CMakeFiles/fltk_app.dir/functions.cpp.obj: CMakeFiles/fltk_app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System\build_windows\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/fltk_app.dir/functions.cpp.obj"
	C:\ProgramData\mingw64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/fltk_app.dir/functions.cpp.obj -MF CMakeFiles\fltk_app.dir\functions.cpp.obj.d -o CMakeFiles\fltk_app.dir\functions.cpp.obj -c "C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System\functions.cpp"

CMakeFiles/fltk_app.dir/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/fltk_app.dir/functions.cpp.i"
	C:\ProgramData\mingw64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System\functions.cpp" > CMakeFiles\fltk_app.dir\functions.cpp.i

CMakeFiles/fltk_app.dir/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/fltk_app.dir/functions.cpp.s"
	C:\ProgramData\mingw64\mingw64\bin\c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System\functions.cpp" -o CMakeFiles\fltk_app.dir\functions.cpp.s

# Object files for target fltk_app
fltk_app_OBJECTS = \
"CMakeFiles/fltk_app.dir/main.cpp.obj" \
"CMakeFiles/fltk_app.dir/functions.cpp.obj"

# External object files for target fltk_app
fltk_app_EXTERNAL_OBJECTS =

fltk_app.exe: CMakeFiles/fltk_app.dir/main.cpp.obj
fltk_app.exe: CMakeFiles/fltk_app.dir/functions.cpp.obj
fltk_app.exe: CMakeFiles/fltk_app.dir/build.make
fltk_app.exe: C:/FLTK/fltk-1.4.1-source/fltk-1.4.1/build/lib/libfltk_images.a
fltk_app.exe: C:/FLTK/fltk-1.4.1-source/fltk-1.4.1/build/lib/libfltk_forms.a
fltk_app.exe: C:/FLTK/fltk-1.4.1-source/fltk-1.4.1/build/lib/libfltk_gl.a
fltk_app.exe: C:/FLTK/fltk-1.4.1-source/fltk-1.4.1/build/lib/libfltk.a
fltk_app.exe: C:/FLTK/fltk-1.4.1-source/fltk-1.4.1/build/lib/libfltk.a
fltk_app.exe: C:/FLTK/fltk-1.4.1-source/fltk-1.4.1/build/lib/libfltk_forms.a
fltk_app.exe: C:/FLTK/fltk-1.4.1-source/fltk-1.4.1/build/lib/libfltk_images.a
fltk_app.exe: C:/FLTK/fltk-1.4.1-source/fltk-1.4.1/build/lib/libfltk_gl.a
fltk_app.exe: C:/FLTK/fltk-1.4.1-source/fltk-1.4.1/build/lib/libfltk_png.a
fltk_app.exe: C:/FLTK/fltk-1.4.1-source/fltk-1.4.1/build/lib/libfltk_z.a
fltk_app.exe: C:/FLTK/fltk-1.4.1-source/fltk-1.4.1/build/lib/libfltk_jpeg.a
fltk_app.exe: C:/FLTK/fltk-1.4.1-source/fltk-1.4.1/build/lib/libfltk.a
fltk_app.exe: CMakeFiles/fltk_app.dir/linkLibs.rsp
fltk_app.exe: CMakeFiles/fltk_app.dir/objects1.rsp
fltk_app.exe: CMakeFiles/fltk_app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System\build_windows\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable fltk_app.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\fltk_app.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fltk_app.dir/build: fltk_app.exe
.PHONY : CMakeFiles/fltk_app.dir/build

CMakeFiles/fltk_app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\fltk_app.dir\cmake_clean.cmake
.PHONY : CMakeFiles/fltk_app.dir/clean

CMakeFiles/fltk_app.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System" "C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System" "C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System\build_windows" "C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System\build_windows" "C:\Users\angel\Documents\School\Spring 2025\Operating Systems\Project\Operating-System\build_windows\CMakeFiles\fltk_app.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/fltk_app.dir/depend

