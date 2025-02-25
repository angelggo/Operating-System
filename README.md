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
    
        🔹MAC & Windows (Terminal based Operating system):
            1. Download the zip file and extract it.
            2. Navigate to towards the following folder : terminal_based_OS , which should be in the main repository folder.
            3. For mac you right click on the folder and select the option "New Terminal at Folder". If you dont see
            this option go to the services tab towards the bottom of when you rigth click on the folder and you should be able to see this option. For Windows click on the directory tab at the top of the file explorer  on the folder and type cmd. 
            4. Once the terminal screen opens with the folder directory, type the following to run the program "./main"

            Note: For mac it would pop up a security warning, so you can close but do not send the file to trash can, other than that you wont see an open button, to fix this go to System Settings>Privacy & Security, and  then scroll towards the bottom, under the security tap you should see a message saying that the execution of main 
            was block due to an unknown developer, click on the button that says "open anywyas". After this try running 
            the program again and now you should see an option to open the program.


# Process Class and functionality (Deliverables Part #2)
    # Whats New?
        🔹 Process Management – Support process creation, Process running emulation, Process states and process management.
        🔹 Command-Line Interface (CLI) – Use basic shell-like commands to interact with the simulated OS.


    # How to run a process   
        Step 1 - Loging using any username or password conbination.
        Step 2 - Type "?" and press enter to display available commands.
        Step 3 - To show the list of available process type "p ls" and hit enter.
        Step 4 - To Run a process type  rp ProcessName , and hit enter.
        Step 5 - To show process info type pd ProcessName, and hit enter.

    # Description of the Attributes and methods:
        Public Methods-
            >Constructor : Initialez a process with a name, assigns a unique process ID (PID), and sets other attributes like burst time and memory requirments.

            >void displayInfo(); Prints all relevant details such as PID, burst time, priorityt, state momory usage, etc.

            >void run(): siulates the execution of the process, it will update the process state, decrement remaining_time and transition the process to "terminated" when finished.

            > updateState() : updates the state of the process (example: "Ready", "Running", "Terminated")

            >getName() : returns the name of the process

            >getPid() : returns the PID of  the process

            >getArrivaltime(): returns the time that the process was created.

        Private Methods: 
            > generatesUniquePid(): Generates a unique id by randomly creating an id number from 1 to 1000 and checks an 
            unorder set to be sure that the id is not part of that used Ids, if is not, then it uses that PID and stores that id 
            into the unorder set to avoid repeating this PID.

            > generateRandomValue( int min, int max): simplifies the generation of random numbers for future attribues vaues.


        Private Attributes: 
            > int pid: Unique process ID assigned at creation.
            > string name: Name of the process
            > long long arrival_time; The timestamp (in milliseconds) when the process was created.
            > int burst_time;  The CPU execution time required to complete the process.
            > int remaining_time;  Time left before the process is finished.
            > int waiting_time;  Time spent waiting in the queue.
            > int turnaround_time;  Total time from arrival to completion.
            > int priority; → Priority level (lower number = higher priority).
            > string state; → Current state of the process ("New", "Ready", "Running", "Blocked", "Terminated").
    
    



# Future features:
    🔹 Process Management – Support process creation, scheduling (First-Come, First-Served & Round Robin), and termination.
    🔹 Memory Management – Simulate a basic paging system with memory allocation and deallocation.
    🔹 File System Simulation – Perform simple file operations like reading, writing, and managing directories.
    🔹 Thread Handling.


