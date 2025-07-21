/**
 * @file SchedulingBase.h
 * @brief Base classes for CPU scheduling algorithms
 * @author Tirth Moradiya
 * @date 2024
 * 
 * This header file defines the base classes and interfaces used by
 * all CPU scheduling algorithms. It provides the foundation for
 * implementing various scheduling strategies with common functionality.
 */

#ifndef SCHEDULINGBASE_H
#define SCHEDULINGBASE_H

#include "Process.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

/**
 * @class SchedulingAlgorithm
 * @brief Abstract base class for all scheduling algorithms
 * 
 * This is the main interface that all scheduling algorithms must implement.
 * It defines the common interface for solving scheduling problems and
 * displaying results.
 */
class SchedulingAlgorithm {
public:
    /**
     * @brief Default constructor
     */
    SchedulingAlgorithm() {}
    
    /**
     * @brief Virtual destructor
     */
    virtual ~SchedulingAlgorithm() {}
    
    /**
     * @brief Pure virtual function to solve scheduling problem
     * 
     * This method must be implemented by all derived classes to
     * execute the specific scheduling algorithm and calculate
     * all necessary metrics.
     */
    virtual void solve() = 0;
};

/**
 * @class SchedulingUnits
 * @brief Manages scheduling metrics and calculations
 * 
 * This class handles the calculation and storage of average
 * turnaround time and waiting time for a set of processes.
 * It provides methods to calculate and display these metrics.
 */
class SchedulingUnits {
private:
    float avg_turnaround_time;  ///< Average turnaround time for all processes
    float avg_waiting_time;     ///< Average waiting time for all processes

public:
    /**
     * @brief Default constructor
     * Initializes average times to zero
     */
    SchedulingUnits();
    
    /**
     * @brief Copy constructor
     * @param other SchedulingUnits object to copy from
     */
    SchedulingUnits(const SchedulingUnits& other);
    
    /**
     * @brief Virtual destructor
     */
    virtual ~SchedulingUnits() {}

    // ========== GETTER METHODS ==========
    
    /**
     * @brief Get average turnaround time
     * @return Average turnaround time
     */
    float get_avg_turnaround_time() const;
    
    /**
     * @brief Get average waiting time
     * @return Average waiting time
     */
    float get_avg_waiting_time() const;

    // ========== SETTER METHODS ==========
    
    /**
     * @brief Set average turnaround time
     * @param avg_turnaround_time New average turnaround time
     */
    void set_avg_turnaround_time(float avg_turnaround_time);
    
    /**
     * @brief Set average waiting time
     * @param avg_waiting_time New average waiting time
     */
    void set_avg_waiting_time(float avg_waiting_time);

    // ========== OPERATOR OVERLOADING ==========
    
    /**
     * @brief Assignment operator
     * @param other SchedulingUnits to assign from
     * @return Reference to this object
     */
    SchedulingUnits& operator=(const SchedulingUnits& other);
    
    /**
     * @brief Equality operator
     * @param other SchedulingUnits to compare with
     * @return true if objects are equal
     */
    bool operator==(const SchedulingUnits& other) const;
    
    /**
     * @brief Less than operator (compares by average turnaround time)
     * @param other SchedulingUnits to compare with
     * @return true if this has lower average turnaround time
     */
    bool operator<(const SchedulingUnits& other) const;
    
    /**
     * @brief Stream insertion operator
     * @param os Output stream
     * @param su SchedulingUnits to output
     * @return Output stream
     */
    friend ostream& operator<<(ostream& os, const SchedulingUnits& su);

    // ========== DISPLAY METHODS ==========
    
    /**
     * @brief Display scheduling metrics
     * 
     * Prints the average turnaround time and waiting time
     * in a formatted manner.
     */
    void display_scheduling_units();
};

/**
 * @class Display
 * @brief Handles visualization and display of scheduling results
 * 
 * This class provides functionality to display scheduling results
 * including Gantt charts and process execution timelines.
 * It maintains a static timeline of process execution blocks.
 */
class Display {
protected:
    int n;                      ///< Number of processes
    Process *p;                 ///< Array of processes
    
    /**
     * @struct ExecutionBlock
     * @brief Represents a time block when a process is executing
     * 
     * This structure tracks when a process starts and ends execution
     * for creating Gantt charts and execution timelines.
     */
    struct ExecutionBlock {
        int process_id;         ///< ID of the executing process
        int start_time;         ///< Start time of execution
        int end_time;           ///< End time of execution
        
        /**
         * @brief Constructor for ExecutionBlock
         * @param pid Process ID
         * @param start Start time
         * @param end End time
         */
        ExecutionBlock(int pid, int start, int end) : process_id(pid), start_time(start), end_time(end) {}
    };
    
    static vector<ExecutionBlock> execution_timeline;  ///< Static timeline of all execution blocks

public:
    /**
     * @brief Constructor
     * @param n Number of processes
     * @param p Array of processes
     */
    Display(int n, Process *p);
    
    /**
     * @brief Display complete scheduling solution
     * 
     * Shows all process details, metrics, and Gantt chart
     */
    void display_solution();
    
    /**
     * @brief Display Gantt chart
     * 
     * Creates a visual representation of process execution
     * over time using the execution timeline.
     */
    void display_gantt_chart();
    
    /**
     * @brief Add execution block to timeline
     * @param process_id ID of the executing process
     * @param start_time Start time of execution
     * @param end_time End time of execution
     */
    static void add_execution_block(int process_id, int start_time, int end_time);
    
    /**
     * @brief Clear execution timeline
     * 
     * Resets the static execution timeline for new scheduling runs
     */
    static void clear_execution_timeline();
};

#endif
