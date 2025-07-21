
#ifndef SCHEDULINGALGORITHMS_H
#define SCHEDULINGALGORITHMS_H

#include "SchedulingBase.h"
#include "Process.h"

class FCFS : public SchedulingAlgorithm, SchedulingUnits, public Display {
    int n;
    Process *p;

public:
    FCFS(int n, Process *p);
    void solve() override;
    void display_gantt_chart();
};

class SJF : public SchedulingAlgorithm, SchedulingUnits, public Display {
    int n;
    Process *p;

public:
    SJF(int n, Process *p);
    void solve() override;
    void display_gantt_chart();
};

class SRTF : public SchedulingAlgorithm, SchedulingUnits, public Display {
    int n;
    Process *p;

public:
    SRTF(int n, Process *p);
    void solve() override;
    void display_gantt_chart();
};

class RR : public SchedulingAlgorithm, SchedulingUnits, public Display {
    int n;
    Process *p;

public:
    RR(int n, Process *p);
    void solve() override;
    void display_gantt_chart();
};

class PRS : public SchedulingAlgorithm, SchedulingUnits, public Display {
    int n;
    Process *p;

public:
    PRS(int n, Process *p);
    void solve() override;
    void display_gantt_chart();
};

#endif
