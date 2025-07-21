
#include "Process.h"
#include <iostream>
#include <algorithm>
using namespace std;

// Static member definition
int Process::process_count = 0;

// Constructors and Destructor
Process::Process() {
    pid = 0;
    arrival_time = 0;
    burst_time = 0;
    start_time = 0;
    completion_time = 0;
    turnaround_time = 0;
    waiting_time = 0;
    priority = 0;
    process_count++;
}

Process::Process(const Process& other) {
    pid = other.pid;
    arrival_time = other.arrival_time;
    burst_time = other.burst_time;
    start_time = other.start_time;
    completion_time = other.completion_time;
    turnaround_time = other.turnaround_time;
    waiting_time = other.waiting_time;
    priority = other.priority;
    process_count++;
    cout << "Process " << pid << " copied using copy constructor" << endl;
}

Process::Process(int pid, int arrival_time, int burst_time, int start_time, 
                int completion_time, int turnaround_time, int waiting_time, int priority) {
    this->pid = pid;
    this->arrival_time = arrival_time;
    this->burst_time = burst_time;
    this->start_time = start_time;
    this->completion_time = completion_time;
    this->turnaround_time = turnaround_time;
    this->waiting_time = waiting_time;
    this->priority = priority;
    process_count++;
}

Process::~Process() {
    process_count--;
}

// Getters
int Process::get_pid() { return pid; }
int Process::get_arrival_time() { return arrival_time; }
int Process::get_burst_time() { return burst_time; }
int Process::get_start_time() { return start_time; }
int Process::get_completion_time() { return completion_time; }
int Process::get_turnaround_time() const { return turnaround_time; }
int Process::get_waiting_time() const { return waiting_time; }
int Process::get_priority() { return priority; }

// Setters
void Process::set_pid(int pid) { this->pid = pid; }
void Process::set_arrival_time(int arrival_time) { this->arrival_time = arrival_time; }
void Process::set_burst_time(int burst_time) { this->burst_time = burst_time; }
void Process::set_start_time(int start_time) { this->start_time = start_time; }
void Process::set_completion_time(int completion_time) { this->completion_time = completion_time; }
void Process::set_turnaround_time(int turnaround_time) { this->turnaround_time = turnaround_time; }
void Process::set_waiting_time(int waiting_time) { this->waiting_time = waiting_time; }
void Process::set_priority(int priority) { this->priority = priority; }

// Operator overloading
Process& Process::operator=(const Process& other) {
    if (this != &other) {
        pid = other.pid;
        arrival_time = other.arrival_time;
        burst_time = other.burst_time;
        start_time = other.start_time;
        completion_time = other.completion_time;
        turnaround_time = other.turnaround_time;
        waiting_time = other.waiting_time;
        priority = other.priority;
        cout << "Process " << pid << " assigned using assignment operator" << endl;
    }
    return *this;
}

bool Process::operator==(const Process& other) const {
    return pid == other.pid;
}

bool Process::operator<(const Process& other) const {
    return burst_time < other.burst_time;
}

bool Process::operator>(const Process& other) const {
    return burst_time > other.burst_time;
}

Process Process::operator+(const Process& other) const {
    Process combined;
    combined.pid = max(pid, other.pid) + 1;
    combined.arrival_time = min(arrival_time, other.arrival_time);
    combined.burst_time = burst_time + other.burst_time;
    combined.priority = max(priority, other.priority);
    return combined;
}

// Static methods
int Process::getProcessCount() { return process_count; }
void Process::resetProcessCount() { process_count = 0; }

bool Process::compareArrival(Process p1, Process p2) {
    return p1.get_arrival_time() < p2.get_arrival_time();
}

bool Process::comparestart(Process p1, Process p2) {
    return p1.get_start_time() < p2.get_start_time();
}

bool Process::compareID(Process p1, Process p2) {
    return p1.get_pid() < p2.get_pid();
}

// Friend function implementations
ostream& operator<<(ostream& os, const Process& p) {
    os << "Process P" << p.pid << " [AT: " << p.arrival_time 
       << ", BT: " << p.burst_time << ", Priority: " << p.priority << "]";
    return os;
}

void displayProcessDetails(const Process& p) {
    cout << "=== Process Details ===" << endl;
    cout << "PID: " << p.pid << endl;
    cout << "Arrival Time: " << p.arrival_time << endl;
    cout << "Burst Time: " << p.burst_time << endl;
    cout << "Priority: " << p.priority << endl;
    cout << "Start Time: " << p.start_time << endl;
    cout << "Completion Time: " << p.completion_time << endl;
    cout << "Turnaround Time: " << p.turnaround_time << endl;
    cout << "Waiting Time: " << p.waiting_time << endl;
    cout << "======================" << endl;
}
