
#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
using namespace std;

class Process {
private:
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int priority;
    static int process_count;

public:
    // Constructors and Destructor
    Process();
    Process(const Process& other);
    Process(int pid, int arrival_time, int burst_time, int start_time, 
            int completion_time, int turnaround_time, int waiting_time, int priority);
    ~Process();

    // Getters
    int get_pid();
    int get_arrival_time();
    int get_burst_time();
    int get_start_time();
    int get_completion_time();
    int get_turnaround_time() const;
    int get_waiting_time() const;
    int get_priority();

    // Setters
    void set_pid(int pid);
    void set_arrival_time(int arrival_time);
    void set_burst_time(int burst_time);
    void set_start_time(int start_time);
    void set_completion_time(int completion_time);
    void set_turnaround_time(int turnaround_time);
    void set_waiting_time(int waiting_time);
    void set_priority(int priority);

    // Operator overloading
    Process& operator=(const Process& other);
    bool operator==(const Process& other) const;
    bool operator<(const Process& other) const;
    bool operator>(const Process& other) const;
    Process operator+(const Process& other) const;

    // Friend functions
    friend ostream& operator<<(ostream& os, const Process& p);
    friend void displayProcessDetails(const Process& p);

    // Static methods
    static int getProcessCount();
    static void resetProcessCount();
    static bool compareArrival(Process p1, Process p2);
    static bool comparestart(Process p1, Process p2);
    static bool compareID(Process p1, Process p2);
};

// Friend function declarations
ostream& operator<<(ostream& os, const Process& p);
void displayProcessDetails(const Process& p);

#endif
