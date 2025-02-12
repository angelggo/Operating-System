# Basic information about Team and Project (Deliverables Part 1)
    >Team members: 
        Angel Gabriel Gomez Ortega

    >Project Title: 
        OS Emulator

    >Project Scoap:
        Welcome to SimpleOS Simulator! This is a lightweight C++ program that emulates 
        some of the core functions of an operating system. It’s a great way to get hands-on 
        experience with OS concepts like process scheduling, memory management, and file 
        operations—without diving into complex real-world kernels.

    >Instructions for setting up and running the Initial Program:
    Note: At the moment due to time I coulnt figure out a way to make the original program a portable for mac, so if you are goign to run the program on mac you wont be able to see the graphic user interface but if you are on windows you can or you can also run the terminal based os since it should be compatible for both mac and windows.
    
        🔹MAC & Windows (Terminal based Operating system):
            1. Download the zip file and extract it.
            2. Navigate to towards the following folder : terminal_based_OS , which should be in the main repository folder.
            3. For mac you right click on the folder and select the option "New Terminal at Folder". If you dont see
            this option go to the services tab towards the bottom of when you rigth click on the folder and you should be able to see this option. For Windows click on the directory tab at the top of the file explorer  on the folder and type cmd. 
            4. Once the terminal screen opens with the folder directory, type the following to run the program "./main"

            Note: For mac it would pop up a security warning, so you can close but do not send the file to trash can, other than that you wont see an open button to fix this go to System Settings>Privacy & Security, and  then scroll towards the bottom, under the security tap you should see a message saying that the execution of main 
            was block due to an unknown developer, click on the button that says "open anywyas". After this try running 
            the program again and now you should see an option to still open the program.

        🔹Windows (Operating system with Graphical User interface)
            1. Downlaod the zip file and extract it.
            2. Navigate towards the "build_windows" folder
            3.Inside the "build_windows" folder you should see, fltk_app.exe file, double click on it an the program should open.
        




# Future features:
    🔹 Process Management – Support process creation, scheduling (First-Come, First-Served & Round Robin), and termination.
    🔹 Memory Management – Simulate a basic paging system with memory allocation and deallocation.
    🔹 File System Simulation – Perform simple file operations like reading, writing, and managing directories.
    🔹 Command-Line Interface (CLI) – Use basic shell-like commands to interact with the simulated OS.


# Technology Used(Subject to change):
    🔹 C++ (FLTK for GUI support)
    🔹 CMake for easy cross-platform builds
    🔹 MinGW/GCC for Windows, Clang/GCC for macOS/Linux
