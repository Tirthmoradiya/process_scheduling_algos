
#include "SchedulingBase.h"
#include <algorithm>
#include <vector>
using namespace std;

// Static member definition
vector<Display::ExecutionBlock> Display::execution_timeline;

// SchedulingUnits implementation
SchedulingUnits::SchedulingUnits() {
    avg_turnaround_time = 0;
    avg_waiting_time = 0;
}

SchedulingUnits::SchedulingUnits(const SchedulingUnits& other) {
    avg_turnaround_time = other.avg_turnaround_time;
    avg_waiting_time = other.avg_waiting_time;
}

float SchedulingUnits::get_avg_turnaround_time() const { 
    return avg_turnaround_time; 
}

float SchedulingUnits::get_avg_waiting_time() const { 
    return avg_waiting_time; 
}

void SchedulingUnits::set_avg_turnaround_time(float avg_turnaround_time) {
    this->avg_turnaround_time = avg_turnaround_time;
}

void SchedulingUnits::set_avg_waiting_time(float avg_waiting_time) {
    this->avg_waiting_time = avg_waiting_time;
}

SchedulingUnits& SchedulingUnits::operator=(const SchedulingUnits& other) {
    if (this != &other) {
        avg_turnaround_time = other.avg_turnaround_time;
        avg_waiting_time = other.avg_waiting_time;
    }
    return *this;
}

bool SchedulingUnits::operator==(const SchedulingUnits& other) const {
    return (avg_turnaround_time == other.avg_turnaround_time && 
            avg_waiting_time == other.avg_waiting_time);
}

bool SchedulingUnits::operator<(const SchedulingUnits& other) const {
    return (avg_turnaround_time + avg_waiting_time) < 
           (other.avg_turnaround_time + other.avg_waiting_time);
}

ostream& operator<<(ostream& os, const SchedulingUnits& su) {
    os << "Avg TT: " << su.avg_turnaround_time << ", Avg WT: " << su.avg_waiting_time;
    return os;
}

void SchedulingUnits::display_scheduling_units() {
    cout << "\n=== PROCESS STATISTICS ===" << endl;
    cout << "Average Turnaround Time = " << get_avg_turnaround_time() << endl;
    cout << "Average Waiting Time = " << get_avg_waiting_time() << endl;
    cout << "=========================" << endl;
}

// Display implementation
Display::Display(int n, Process *p) : n(n), p(p) {}

void Display::display_solution() {
    cout << "\n";
    cout << "+------------+---------------+-------------+-------------+-----------------+-----------------+---------------+\n";
    cout << "| Process ID | Arrival Time  | Burst Time  | Start Time  | Completion Time | Turnaround Time | Waiting Time  |\n";
    cout << "+------------+---------------+-------------+-------------+-----------------+-----------------+---------------+\n";

    for (int i = 0; i < n; i++) {
        cout << "|     P" << setw(5) << left << p[i].get_pid() 
             << "|" << setw(14) << right << p[i].get_arrival_time() << " "
             << "|" << setw(12) << right << p[i].get_burst_time() << " "
             << "|" << setw(12) << right << p[i].get_start_time() << " "
             << "|" << setw(16) << right << p[i].get_completion_time() << " "
             << "|" << setw(16) << right << p[i].get_turnaround_time() << " "
             << "|" << setw(14) << right << p[i].get_waiting_time() << " |\n";
    }
    cout << "+------------+---------------+-------------+-------------+-----------------+-----------------+---------------+\n";
}

void Display::display_gantt_chart() {
    cout << "\n=== Gantt Chart (Visual Timeline) ===" << endl;
    
    if (execution_timeline.empty()) {
        cout << "No execution timeline recorded." << endl;
        return;
    }
    
    // Sort execution blocks by start time
    sort(execution_timeline.begin(), execution_timeline.end(), 
         [](const ExecutionBlock& a, const ExecutionBlock& b) {
             return a.start_time < b.start_time;
         });
    
    // Find time range
    int min_time = execution_timeline[0].start_time;
    int max_time = execution_timeline[0].end_time;
    
    for (const auto& block : execution_timeline) {
        min_time = min(min_time, block.start_time);
        max_time = max(max_time, block.end_time);
    }
    
    // Display timeline
    cout << "Timeline: ";
    for (const auto& block : execution_timeline) {
        cout << "P" << block.process_id << "(" << block.start_time 
             << "-" << block.end_time << ") ";
    }
    cout << endl << endl;
    
    // Create visual representation
    cout << "Visual Gantt Chart:" << endl;
    cout << "Time: ";
    for (int t = min_time; t <= max_time; t++) {
        cout << setw(3) << t;
    }
    cout << endl;
    
    cout << "      ";
    for (int t = min_time; t < max_time; t++) {
        // Find which process is running at time t
        int running_process = -1;
        for (const auto& block : execution_timeline) {
            if (t >= block.start_time && t < block.end_time) {
                running_process = block.process_id;
                break;
            }
        }
        
        if (running_process != -1) {
            cout << " P" << running_process;
        } else {
            cout << " --";
        }
    }
    cout << endl;
    
    // Display execution blocks for each process
    for (int i = 0; i < n; i++) {
        cout << "P" << p[i].get_pid() << ":   ";
        
        for (int t = min_time; t < max_time; t++) {
            bool is_running = false;
            for (const auto& block : execution_timeline) {
                if (block.process_id == p[i].get_pid() && 
                    t >= block.start_time && t < block.end_time) {
                    is_running = true;
                    break;
                }
            }
            
            if (is_running) {
                cout << " ██";
            } else {
                cout << "   ";
            }
        }
        cout << endl;
    }
    
    // Print execution summary
    cout << "\nExecution Summary:" << endl;
    for (const auto& block : execution_timeline) {
        cout << "P" << block.process_id << " runs from " << block.start_time 
             << " to " << block.end_time << " (duration: " 
             << (block.end_time - block.start_time) << ")" << endl;
    }
}

void Display::add_execution_block(int process_id, int start_time, int end_time) {
    execution_timeline.push_back(ExecutionBlock(process_id, start_time, end_time));
}

void Display::clear_execution_timeline() {
    execution_timeline.clear();
}
