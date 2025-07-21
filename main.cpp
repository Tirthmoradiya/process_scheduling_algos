/**
 * @file main.cpp
 * @brief Main entry point for CPU scheduling algorithms simulator
 * @author Tirth Moradiya
 * @date 2024
 * 
 * This is the main program that provides an interactive interface
 * for testing various CPU scheduling algorithms. It allows users
 * to input process details and visualize the scheduling results.
 */

#include "Process.h"
#include "SchedulingAlgorithms.h"
#include "Utils.h"
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

/**
 * @brief Main function - Entry point of the program
 * @return 0 on successful execution
 * 
 * This function provides an interactive menu-driven interface
 * for the CPU scheduling algorithms simulator. It:
 * 1. Displays available scheduling algorithms
 * 2. Takes user input for algorithm choice and process details
 * 3. Creates Process objects with the input data
 * 4. Executes the selected scheduling algorithm
 * 5. Displays results including Gantt chart and metrics
 */
int main() {
    // Display welcome message and available algorithms
    cout << endl << "Welcome to operating systems scheduling algorithms (Enhanced OOP Version)" << endl << endl;
    cout << "1. " << scheduling_algo(1) << endl;
    cout << "2. " << scheduling_algo(2) << endl;
    cout << "3. " << scheduling_algo(3) << endl;
    cout << "4. " << scheduling_algo(4) << endl;
    cout << "5. " << scheduling_algo(5) << endl;
    cout << "0. " << scheduling_algo(0) << endl;

    // Get user's algorithm choice
    int choice;
    cout << "Enter your choice of scheduler: ";
    cin >> choice;
    cout << endl << "You have chosen " << scheduling_algo(choice) << endl;

    // Validate choice and exit if invalid
    if (choice > 5 || choice < 1) {
        cout << "Thanks for not choosing any algorithm. Exiting..." << endl;
        return 0;
    }

    // Get number of processes
    int n;
    Process p[100];  // Array to store process objects

    cout << setprecision(2) << fixed;  // Set output formatting

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << endl;

    // Input process details
    for (int i = 0; i < n; i++) {
        int arrival_time, burst_time;
        int priority = 0;  // Default priority for non-priority algorithms
        
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> arrival_time;
        cout << "Enter burst time of process " << i + 1 << ":   ";
        cin >> burst_time;

        // Get priority only for Priority Scheduling
        if (choice == 5) {
            cout << "Enter priority of the process " << i + 1 << ": ";
            cin >> priority;
        }
        cout << endl;

        // Create Process object with input data
        p[i] = Process(i, arrival_time, burst_time, 0, 0, 0, 0, priority);
    }

    // Execute the selected scheduling algorithm
    switch (choice) {
    case 0: {
        exit(0);
        break;
    }
    case 1: {
        // First Come First Serve
        FCFS fcfs(n, p);
        break;
    }
    case 2: {
        // Shortest Job First
        SJF sjf(n, p);
        break;
    }
    case 3: {
        // Shortest Remaining Time First
        SRTF srtf(n, p);
        break;
    }
    case 4: {
        // Round Robin
        RR rr(n, p);
        break;
    }
    case 5: {
        // Priority Scheduling
        PRS prs(n, p);
        break;
    }
    default: {
        cout << "Invalid choice" << endl;
        break;
    }
    }

    return 0;
}