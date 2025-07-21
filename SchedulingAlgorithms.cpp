
#include "SchedulingAlgorithms.h"
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdlib>
using namespace std;

// FCFS Implementation
FCFS::FCFS(int n, Process *p) : Display(n, p), n(n), p(p) {
    solve();
    display_solution();
    display_scheduling_units();
    display_gantt_chart();
}

void FCFS::solve() {
    Display::clear_execution_timeline();
    
    int total_turnaround_time = 0;
    int total_waiting_time = 0;

    sort(p, p + n, Process::compareArrival);

    for (int i = 0; i < n; i++) {
        int maxStartTime = max(p[i - 1].get_completion_time(), p[i].get_arrival_time());
        int start_time = (i == 0) ? p[i].get_arrival_time() : maxStartTime;

        p[i].set_start_time(start_time);
        p[i].set_completion_time(p[i].get_start_time() + p[i].get_burst_time());
        p[i].set_turnaround_time(p[i].get_completion_time() - p[i].get_arrival_time());
        p[i].set_waiting_time(p[i].get_turnaround_time() - p[i].get_burst_time());

        // Record execution block
        Display::add_execution_block(p[i].get_pid(), p[i].get_start_time(), p[i].get_completion_time());

        total_turnaround_time += p[i].get_turnaround_time();
        total_waiting_time += p[i].get_waiting_time();
    }

    set_avg_turnaround_time((float)total_turnaround_time / n);
    set_avg_waiting_time((float)total_waiting_time / n);

    sort(p, p + n, Process::compareID);
}

void FCFS::display_gantt_chart() {
    Display::display_gantt_chart();
}

// SJF Implementation
SJF::SJF(int n, Process *p) : Display(n, p), n(n), p(p) {
    solve();
    display_solution();
    display_scheduling_units();
    display_gantt_chart();
}

void SJF::solve() {
    Display::clear_execution_timeline();
    
    int total_turnaround_time = 0;
    int total_waiting_time = 0;

    int is_completed[100];
    memset(is_completed, 0, sizeof(is_completed));

    int current_time = 0;
    int completed = 0;

    while (completed != n) {
        int idx = -1;
        int mn = 10000000;
        for (int i = 0; i < n; i++) {
            if (p[i].get_arrival_time() <= current_time && is_completed[i] == 0) {
                if (p[i].get_burst_time() < mn) {
                    mn = p[i].get_burst_time();
                    idx = i;
                }
                if (p[i].get_burst_time() == mn) {
                    if (p[i].get_arrival_time() < p[idx].get_arrival_time()) {
                        mn = p[i].get_burst_time();
                        idx = i;
                    }
                }
            }
        }
        if (idx != -1) {
            p[idx].set_start_time(current_time);
            p[idx].set_completion_time(p[idx].get_start_time() + p[idx].get_burst_time());
            p[idx].set_turnaround_time(p[idx].get_completion_time() - p[idx].get_arrival_time());
            p[idx].set_waiting_time(p[idx].get_turnaround_time() - p[idx].get_burst_time());

            // Record execution block
            Display::add_execution_block(p[idx].get_pid(), p[idx].get_start_time(), p[idx].get_completion_time());

            total_turnaround_time += p[idx].get_turnaround_time();
            total_waiting_time += p[idx].get_waiting_time();

            is_completed[idx] = 1;
            completed++;
            current_time = p[idx].get_completion_time();
        } else {
            current_time++;
        }
    }

    set_avg_turnaround_time((float)total_turnaround_time / n);
    set_avg_waiting_time((float)total_waiting_time / n);
}

void SJF::display_gantt_chart() {
    Display::display_gantt_chart();
}

// SRTF Implementation
SRTF::SRTF(int n, Process *p) : Display(n, p), n(n), p(p) {
    solve();
    display_solution();
    display_scheduling_units();
    display_gantt_chart();
}

void SRTF::solve() {
    Display::clear_execution_timeline();
    
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int burst_remaining[100];

    int is_completed[100];
    memset(is_completed, 0, sizeof(is_completed));

    for (int i = 0; i < n; i++) {
        burst_remaining[i] = p[i].get_burst_time();
    }

    int current_time = 0;
    int completed = 0;
    int last_process = -1;
    int execution_start = 0;

    while (completed != n) {
        int idx = -1;
        int mn = 10000000;
        for (int i = 0; i < n; i++) {
            if (p[i].get_arrival_time() <= current_time && is_completed[i] == 0) {
                if (burst_remaining[i] < mn) {
                    mn = burst_remaining[i];
                    idx = i;
                }
                if (burst_remaining[i] == mn) {
                    if (p[i].get_arrival_time() < p[idx].get_arrival_time()) {
                        mn = burst_remaining[i];
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            // Check if we're switching processes
            if (last_process != -1 && last_process != idx) {
                // Record the previous process's execution block
                Display::add_execution_block(p[last_process].get_pid(), execution_start, current_time);
            }
            
            if (last_process != idx) {
                execution_start = current_time;
                last_process = idx;
            }

            if (burst_remaining[idx] == p[idx].get_burst_time()) {
                p[idx].set_start_time(current_time);
            }
            
            burst_remaining[idx] -= 1;
            current_time++;

            if (burst_remaining[idx] == 0) {
                // Record the final execution block for this process
                Display::add_execution_block(p[idx].get_pid(), execution_start, current_time);
                
                p[idx].set_completion_time(current_time);
                p[idx].set_turnaround_time(p[idx].get_completion_time() - p[idx].get_arrival_time());
                p[idx].set_waiting_time(p[idx].get_turnaround_time() - p[idx].get_burst_time());

                total_turnaround_time += p[idx].get_turnaround_time();
                total_waiting_time += p[idx].get_waiting_time();

                is_completed[idx] = 1;
                completed++;
                last_process = -1;
            }
        } else {
            current_time++;
        }
    }

    set_avg_turnaround_time((float)total_turnaround_time / n);
    set_avg_waiting_time((float)total_waiting_time / n);
}

void SRTF::display_gantt_chart() {
    Display::display_gantt_chart();
}

// RR Implementation
RR::RR(int n, Process *p) : Display(n, p), n(n), p(p) {
    solve();
    display_solution();
    display_scheduling_units();
    display_gantt_chart();
}

void RR::solve() {
    Display::clear_execution_timeline();
    
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int burst_remaining[100];
    int idx;

    int tq;
    cout << "Enter time quantum: ";
    cin >> tq;

    for (int i = 0; i < n; i++) {
        burst_remaining[i] = p[i].get_burst_time();
    }

    sort(p, p + n, Process::compareArrival);

    queue<int> q;
    int current_time = 0;
    q.push(0);
    int completed = 0;
    int mark[100];
    memset(mark, 0, sizeof(mark));
    mark[0] = 1;

    while (completed != n) {
        idx = q.front();
        q.pop();

        if (burst_remaining[idx] == p[idx].get_burst_time()) {
            p[idx].set_start_time(max(current_time, p[idx].get_arrival_time()));
            current_time = p[idx].get_start_time();
        }

        int execution_start = current_time;
        int execution_time;

        if (burst_remaining[idx] - tq > 0) {
            execution_time = tq;
            burst_remaining[idx] -= tq;
            current_time += tq;
        } else {
            execution_time = burst_remaining[idx];
            current_time += burst_remaining[idx];
            burst_remaining[idx] = 0;
            completed++;

            p[idx].set_completion_time(current_time);
            p[idx].set_turnaround_time(p[idx].get_completion_time() - p[idx].get_arrival_time());
            p[idx].set_waiting_time(p[idx].get_turnaround_time() - p[idx].get_burst_time());

            total_turnaround_time += p[idx].get_turnaround_time();
            total_waiting_time += p[idx].get_waiting_time();
        }

        // Record execution block
        Display::add_execution_block(p[idx].get_pid(), execution_start, current_time);

        for (int i = 1; i < n; i++) {
            if (burst_remaining[i] > 0 && p[i].get_arrival_time() <= current_time && mark[i] == 0) {
                q.push(i);
                mark[i] = 1;
            }
        }
        if (burst_remaining[idx] > 0) {
            q.push(idx);
        }

        if (q.empty()) {
            for (int i = 1; i < n; i++) {
                if (burst_remaining[i] > 0) {
                    q.push(i);
                    mark[i] = 1;
                    break;
                }
            }
        }
    }

    set_avg_turnaround_time((float)total_turnaround_time / n);
    set_avg_waiting_time((float)total_waiting_time / n);

    sort(p, p + n, Process::compareID);
}

void RR::display_gantt_chart() {
    Display::display_gantt_chart();
}

// PRS Implementation
PRS::PRS(int n, Process *p) : Display(n, p), n(n), p(p) {
    solve();
    display_solution();
    display_scheduling_units();
    display_gantt_chart();
}

void PRS::solve() {
    Display::clear_execution_timeline();
    
    int choice;
    bool preemptive;
    cout << "Choose Priority Scheduling Algorithm: " << endl;
    cout << "1. Preemptive" << endl;
    cout << "2. Non-Preemptive" << endl;
    cout << "0. Exit" << endl;
    cin >> choice;

    switch (choice) {
    case 1:
        preemptive = true;
        break;
    case 2:
        preemptive = false;
        break;
    case 0:
        exit(0);
        break;
    default:
        cout << "Invalid Choice" << endl;
        break;
    }

    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int is_completed[100];
    memset(is_completed, 0, sizeof(is_completed));

    int burst_remaining[100];
    for (int i = 0; i < n; i++) {
        burst_remaining[i] = p[i].get_burst_time();
    }

    int current_time = 0;
    int completed = 0;
    int last_process = -1;
    int execution_start = 0;

    while (completed != n) {
        int idx = -1;
        int mx = -1;
        for (int i = 0; i < n; i++) {
            if (p[i].get_arrival_time() <= current_time && is_completed[i] == 0) {
                if (p[i].get_priority() > mx) {
                    mx = p[i].get_priority();
                    idx = i;
                }
                if (p[i].get_priority() == mx) {
                    if (p[i].get_arrival_time() < p[idx].get_arrival_time()) {
                        mx = p[i].get_priority();
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1) {
            if (preemptive == true) {
                // Check if we're switching processes
                if (last_process != -1 && last_process != idx) {
                    // Record the previous process's execution block
                    Display::add_execution_block(p[last_process].get_pid(), execution_start, current_time);
                }
                
                if (last_process != idx) {
                    execution_start = current_time;
                    last_process = idx;
                }

                if (burst_remaining[idx] == p[idx].get_burst_time()) {
                    p[idx].set_start_time(current_time);
                }
                
                burst_remaining[idx] -= 1;
                current_time++;

                if (burst_remaining[idx] == 0) {
                    // Record the final execution block for this process
                    Display::add_execution_block(p[idx].get_pid(), execution_start, current_time);
                    
                    p[idx].set_completion_time(current_time);
                    p[idx].set_turnaround_time(p[idx].get_completion_time() - p[idx].get_arrival_time());
                    p[idx].set_waiting_time(p[idx].get_turnaround_time() - p[idx].get_burst_time());

                    total_turnaround_time += p[idx].get_turnaround_time();
                    total_waiting_time += p[idx].get_waiting_time();

                    is_completed[idx] = 1;
                    completed++;
                    last_process = -1;
                }
            } else {
                p[idx].set_start_time(current_time);
                p[idx].set_completion_time(p[idx].get_start_time() + p[idx].get_burst_time());
                p[idx].set_turnaround_time(p[idx].get_completion_time() - p[idx].get_arrival_time());
                p[idx].set_waiting_time(p[idx].get_turnaround_time() - p[idx].get_burst_time());

                // Record execution block for non-preemptive
                Display::add_execution_block(p[idx].get_pid(), current_time, p[idx].get_completion_time());

                total_turnaround_time += p[idx].get_turnaround_time();
                total_waiting_time += p[idx].get_waiting_time();

                is_completed[idx] = 1;
                completed++;
                current_time = p[idx].get_completion_time();
            }
        } else {
            current_time++;
        }
    }
    set_avg_turnaround_time((float)total_turnaround_time / n);
    set_avg_waiting_time((float)total_waiting_time / n);
}

void PRS::display_gantt_chart() {
    Display::display_gantt_chart();
}
