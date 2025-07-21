
#include "Utils.h"
#include <iostream>
using namespace std;

string scheduling_algo(int n) {
    switch (n) {
    case 1:
        return "FCFS (First Come First Serve)";
    case 2:
        return "SJF (Shortest Job First)";
    case 3:
        return "SRTF (Shortest Remaining Time First)";
    case 4:
        return "RR (Round Robin)";
    case 5:
        return "Priority (Priority Scheduling)";
    default:
        return "Exit";
    }
}


