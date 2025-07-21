
#ifndef SCHEDULINGBASE_H
#define SCHEDULINGBASE_H

#include "Process.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

class SchedulingAlgorithm {
public:
    SchedulingAlgorithm() {}
    virtual ~SchedulingAlgorithm() {}
    virtual void solve() = 0;
};

class SchedulingUnits {
private:
    float avg_turnaround_time;
    float avg_waiting_time;

public:
    // Constructor
    SchedulingUnits();
    SchedulingUnits(const SchedulingUnits& other);
    virtual ~SchedulingUnits() {}

    // Getters
    float get_avg_turnaround_time() const;
    float get_avg_waiting_time() const;

    // Setters
    void set_avg_turnaround_time(float avg_turnaround_time);
    void set_avg_waiting_time(float avg_waiting_time);

    // Operators
    SchedulingUnits& operator=(const SchedulingUnits& other);
    bool operator==(const SchedulingUnits& other) const;
    bool operator<(const SchedulingUnits& other) const;
    friend ostream& operator<<(ostream& os, const SchedulingUnits& su);

    // Display method
    void display_scheduling_units();
};

class Display {
protected:
    int n;
    Process *p;
    
    // Structure to track execution timeline
    struct ExecutionBlock {
        int process_id;
        int start_time;
        int end_time;
        ExecutionBlock(int pid, int start, int end) : process_id(pid), start_time(start), end_time(end) {}
    };
    
    static vector<ExecutionBlock> execution_timeline;

public:
    Display(int n, Process *p);
    void display_solution();
    void display_gantt_chart();
    static void add_execution_block(int process_id, int start_time, int end_time);
    static void clear_execution_timeline();
};

#endif
