#include "Process.h"
#include "SchedulingAlgorithms.h"
#include "Utils.h"
#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
    cout << endl << "Welcome to operating systems scheduling algorithms (Enhanced OOP Version)" << endl << endl;
    cout << "1. " << scheduling_algo(1) << endl;
    cout << "2. " << scheduling_algo(2) << endl;
    cout << "3. " << scheduling_algo(3) << endl;
    cout << "4. " << scheduling_algo(4) << endl;
    cout << "5. " << scheduling_algo(5) << endl;
    cout << "0. " << scheduling_algo(0) << endl;

    int choice;
    cout << "Enter your choice of scheduler: ";
    cin >> choice;
    cout << endl << "You have chosen " << scheduling_algo(choice) << endl;

    if (choice > 5 || choice < 1) {
        cout << "Thanks for not choosing any algorithm. Exiting..." << endl;
        return 0;
    }

    int n;
    Process p[100];

    cout << setprecision(2) << fixed;

    cout << "Enter the number of processes: ";
    cin >> n;
    cout << endl;

    for (int i = 0; i < n; i++) {
        int arrival_time, burst_time;
        int priority = 0;
        cout << "Enter arrival time of process " << i + 1 << ": ";
        cin >> arrival_time;
        cout << "Enter burst time of process " << i + 1 << ":   ";
        cin >> burst_time;

        if (choice == 5) {
            cout << "Enter priority of the process " << i + 1 << ": ";
            cin >> priority;
        }
        cout << endl;

        p[i] = Process(i, arrival_time, burst_time, 0, 0, 0, 0, priority);
    }

    switch (choice) {
    case 0: {
        exit(0);
        break;
    }
    case 1: {
        FCFS fcfs(n, p);
        break;
    }
    case 2: {
        SJF sjf(n, p);
        break;
    }
    case 3: {
        SRTF srtf(n, p);
        break;
    }
    case 4: {
        RR rr(n, p);
        break;
    }
    case 5: {
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