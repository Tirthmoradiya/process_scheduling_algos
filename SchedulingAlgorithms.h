/**
 * @file SchedulingAlgorithms.h
 * @brief Concrete implementations of CPU scheduling algorithms
 * @author Tirth Moradiya
 * @date 2024
 * 
 * This header file defines the concrete classes that implement
 * various CPU scheduling algorithms. Each class inherits from
 * the base classes and provides specific scheduling logic.
 */

#ifndef SCHEDULINGALGORITHMS_H
#define SCHEDULINGALGORITHMS_H

#include "SchedulingBase.h"
#include "Process.h"

/**
 * @class FCFS
 * @brief First Come First Serve scheduling algorithm
 * 
 * This is a non-preemptive scheduling algorithm where processes
 * are executed in the order they arrive. It's simple but may not
 * be optimal for all scenarios.
 * 
 * Characteristics:
 * - Non-preemptive
 * - Simple implementation
 * - Fair to all processes
 * - May lead to convoy effect
 */
class FCFS : public SchedulingAlgorithm, SchedulingUnits, public Display {
private:
    int n;          ///< Number of processes
    Process *p;     ///< Array of processes

public:
    /**
     * @brief Constructor
     * @param n Number of processes
     * @param p Array of processes
     */
    FCFS(int n, Process *p);
    
    /**
     * @brief Solve FCFS scheduling problem
     * 
     * Implements the First Come First Serve algorithm:
     * 1. Sort processes by arrival time
     * 2. Execute processes in order
     * 3. Calculate all metrics
     */
    void solve() override;
    
    /**
     * @brief Display Gantt chart for FCFS
     * 
     * Shows the execution timeline of processes
     * in the order they were executed.
     */
    void display_gantt_chart();
};

/**
 * @class SJF
 * @brief Shortest Job First scheduling algorithm
 * 
 * This is a non-preemptive scheduling algorithm that selects
 * the process with the shortest burst time among ready processes.
 * 
 * Characteristics:
 * - Non-preemptive
 * - Minimizes average waiting time
 * - May cause starvation
 * - Requires knowledge of burst times
 */
class SJF : public SchedulingAlgorithm, SchedulingUnits, public Display {
private:
    int n;          ///< Number of processes
    Process *p;     ///< Array of processes

public:
    /**
     * @brief Constructor
     * @param n Number of processes
     * @param p Array of processes
     */
    SJF(int n, Process *p);
    
    /**
     * @brief Solve SJF scheduling problem
     * 
     * Implements the Shortest Job First algorithm:
     * 1. Sort processes by arrival time
     * 2. At each time, select shortest burst time among ready processes
     * 3. Calculate all metrics
     */
    void solve() override;
    
    /**
     * @brief Display Gantt chart for SJF
     * 
     * Shows the execution timeline of processes
     * in the order they were executed.
     */
    void display_gantt_chart();
};

/**
 * @class SRTF
 * @brief Shortest Remaining Time First scheduling algorithm
 * 
 * This is the preemptive version of SJF. It selects the process
 * with the shortest remaining time and can preempt running processes.
 * 
 * Characteristics:
 * - Preemptive
 * - Optimal for minimizing average waiting time
 * - May cause starvation
 * - More complex implementation
 */
class SRTF : public SchedulingAlgorithm, SchedulingUnits, public Display {
private:
    int n;          ///< Number of processes
    Process *p;     ///< Array of processes

public:
    /**
     * @brief Constructor
     * @param n Number of processes
     * @param p Array of processes
     */
    SRTF(int n, Process *p);
    
    /**
     * @brief Solve SRTF scheduling problem
     * 
     * Implements the Shortest Remaining Time First algorithm:
     * 1. At each time unit, select process with shortest remaining time
     * 2. Preempt current process if necessary
     * 3. Calculate all metrics
     */
    void solve() override;
    
    /**
     * @brief Display Gantt chart for SRTF
     * 
     * Shows the execution timeline of processes
     * including preemptions.
     */
    void display_gantt_chart();
};

/**
 * @class RR
 * @brief Round Robin scheduling algorithm
 * 
 * This is a preemptive scheduling algorithm where each process
 * gets a fixed time quantum. Processes are executed in a circular
 * queue fashion.
 * 
 * Characteristics:
 * - Preemptive
 * - Fair to all processes
 * - No starvation
 * - Performance depends on time quantum
 */
class RR : public SchedulingAlgorithm, SchedulingUnits, public Display {
private:
    int n;          ///< Number of processes
    Process *p;     ///< Array of processes

public:
    /**
     * @brief Constructor
     * @param n Number of processes
     * @param p Array of processes
     */
    RR(int n, Process *p);
    
    /**
     * @brief Solve Round Robin scheduling problem
     * 
     * Implements the Round Robin algorithm:
     * 1. Maintain a ready queue
     * 2. Execute each process for time quantum
     * 3. Move to next process in queue
     * 4. Calculate all metrics
     */
    void solve() override;
    
    /**
     * @brief Display Gantt chart for Round Robin
     * 
     * Shows the execution timeline of processes
     * with time quantum boundaries.
     */
    void display_gantt_chart();
};

/**
 * @class PRS
 * @brief Priority Scheduling algorithm
 * 
 * This is a scheduling algorithm where processes are executed
 * based on their priority values. Higher priority processes
 * are executed first.
 * 
 * Characteristics:
 * - Can be preemptive or non-preemptive
   - Priority-based selection
   - May cause starvation
   - Useful for real-time systems
 */
class PRS : public SchedulingAlgorithm, SchedulingUnits, public Display {
private:
    int n;          ///< Number of processes
    Process *p;     ///< Array of processes

public:
    /**
     * @brief Constructor
     * @param n Number of processes
     * @param p Array of processes
     */
    PRS(int n, Process *p);
    
    /**
     * @brief Solve Priority Scheduling problem
     * 
     * Implements the Priority Scheduling algorithm:
     * 1. Sort processes by priority (higher priority first)
     * 2. Execute processes in priority order
     * 3. Calculate all metrics
     */
    void solve() override;
    
    /**
     * @brief Display Gantt chart for Priority Scheduling
     * 
     * Shows the execution timeline of processes
     * in priority order.
     */
    void display_gantt_chart();
};

#endif
