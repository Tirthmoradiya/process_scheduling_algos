/**
 * @file Process.h
 * @brief Process class definition for CPU scheduling algorithms
 * @author Tirth Moradiya
 * @date 2024
 * 
 * This header file defines the Process class which represents a process
 * in CPU scheduling algorithms. It includes all necessary attributes
 * and methods for process management and scheduling calculations.
 */

#ifndef PROCESS_H
#define PROCESS_H

#include <iostream>
using namespace std;

/**
 * @class Process
 * @brief Represents a process in CPU scheduling algorithms
 * 
 * The Process class encapsulates all the properties and behaviors
 * of a process that can be scheduled by various CPU scheduling algorithms.
 * It includes attributes like arrival time, burst time, priority, and
 * calculated metrics like turnaround time and waiting time.
 */
class Process {
private:
    int pid;                    ///< Process ID (unique identifier)
    int arrival_time;           ///< Time when process arrives in ready queue
    int burst_time;             ///< Total CPU time required by the process
    int start_time;             ///< Time when process starts execution
    int completion_time;        ///< Time when process completes execution
    int turnaround_time;        ///< Total time from arrival to completion
    int waiting_time;           ///< Total time spent waiting in ready queue
    int priority;               ///< Priority value for priority-based scheduling
    static int process_count;   ///< Static counter for generating unique PIDs

public:
    /**
     * @brief Default constructor
     * Initializes a process with default values
     */
    Process();
    
    /**
     * @brief Copy constructor
     * @param other Process object to copy from
     */
    Process(const Process& other);
    
    /**
     * @brief Parameterized constructor
     * @param pid Process ID
     * @param arrival_time Arrival time of the process
     * @param burst_time Burst time of the process
     * @param start_time Start time of the process
     * @param completion_time Completion time of the process
     * @param turnaround_time Turnaround time of the process
     * @param waiting_time Waiting time of the process
     * @param priority Priority of the process
     */
    Process(int pid, int arrival_time, int burst_time, int start_time, 
            int completion_time, int turnaround_time, int waiting_time, int priority);
    
    /**
     * @brief Destructor
     */
    ~Process();

    // ========== GETTER METHODS ==========
    
    /**
     * @brief Get process ID
     * @return Process ID
     */
    int get_pid();
    
    /**
     * @brief Get arrival time
     * @return Arrival time
     */
    int get_arrival_time();
    
    /**
     * @brief Get burst time
     * @return Burst time
     */
    int get_burst_time();
    
    /**
     * @brief Get start time
     * @return Start time
     */
    int get_start_time();
    
    /**
     * @brief Get completion time
     * @return Completion time
     */
    int get_completion_time();
    
    /**
     * @brief Get turnaround time
     * @return Turnaround time
     */
    int get_turnaround_time() const;
    
    /**
     * @brief Get waiting time
     * @return Waiting time
     */
    int get_waiting_time() const;
    
    /**
     * @brief Get priority
     * @return Priority value
     */
    int get_priority();

    // ========== SETTER METHODS ==========
    
    /**
     * @brief Set process ID
     * @param pid New process ID
     */
    void set_pid(int pid);
    
    /**
     * @brief Set arrival time
     * @param arrival_time New arrival time
     */
    void set_arrival_time(int arrival_time);
    
    /**
     * @brief Set burst time
     * @param burst_time New burst time
     */
    void set_burst_time(int burst_time);
    
    /**
     * @brief Set start time
     * @param start_time New start time
     */
    void set_start_time(int start_time);
    
    /**
     * @brief Set completion time
     * @param completion_time New completion time
     */
    void set_completion_time(int completion_time);
    
    /**
     * @brief Set turnaround time
     * @param turnaround_time New turnaround time
     */
    void set_turnaround_time(int turnaround_time);
    
    /**
     * @brief Set waiting time
     * @param waiting_time New waiting time
     */
    void set_waiting_time(int waiting_time);
    
    /**
     * @brief Set priority
     * @param priority New priority value
     */
    void set_priority(int priority);

    // ========== OPERATOR OVERLOADING ==========
    
    /**
     * @brief Assignment operator
     * @param other Process to assign from
     * @return Reference to this process
     */
    Process& operator=(const Process& other);
    
    /**
     * @brief Equality operator
     * @param other Process to compare with
     * @return true if processes are equal
     */
    bool operator==(const Process& other) const;
    
    /**
     * @brief Less than operator (compares by arrival time)
     * @param other Process to compare with
     * @return true if this process arrives before other
     */
    bool operator<(const Process& other) const;
    
    /**
     * @brief Greater than operator (compares by arrival time)
     * @param other Process to compare with
     * @return true if this process arrives after other
     */
    bool operator>(const Process& other) const;
    
    /**
     * @brief Addition operator (combines burst times)
     * @param other Process to add
     * @return New process with combined burst time
     */
    Process operator+(const Process& other) const;

    // ========== FRIEND FUNCTIONS ==========
    
    /**
     * @brief Stream insertion operator
     * @param os Output stream
     * @param p Process to output
     * @return Output stream
     */
    friend ostream& operator<<(ostream& os, const Process& p);
    
    /**
     * @brief Display process details
     * @param p Process to display
     */
    friend void displayProcessDetails(const Process& p);

    // ========== STATIC METHODS ==========
    
    /**
     * @brief Get total process count
     * @return Number of processes created
     */
    static int getProcessCount();
    
    /**
     * @brief Reset process counter
     */
    static void resetProcessCount();
    
    /**
     * @brief Compare processes by arrival time
     * @param p1 First process
     * @param p2 Second process
     * @return true if p1 arrives before p2
     */
    static bool compareArrival(Process p1, Process p2);
    
    /**
     * @brief Compare processes by start time
     * @param p1 First process
     * @param p2 Second process
     * @return true if p1 starts before p2
     */
    static bool comparestart(Process p1, Process p2);
    
    /**
     * @brief Compare processes by ID
     * @param p1 First process
     * @param p2 Second process
     * @return true if p1 has lower ID than p2
     */
    static bool compareID(Process p1, Process p2);
};

// ========== FRIEND FUNCTION DECLARATIONS ==========

/**
 * @brief Stream insertion operator for Process
 * @param os Output stream
 * @param p Process to output
 * @return Output stream
 */
ostream& operator<<(ostream& os, const Process& p);

/**
 * @brief Display detailed process information
 * @param p Process to display
 */
void displayProcessDetails(const Process& p);

#endif
