/**
 * @file Utils.h
 * @brief Utility functions for scheduling algorithms
 * @author Tirth Moradiya
 * @date 2024
 * 
 * This header file contains utility functions that are used
 * across different scheduling algorithms for common operations
 * like getting algorithm names and other helper functions.
 */

#ifndef UTILS_H
#define UTILS_H

#include <string>

/**
 * @brief Get the name of a scheduling algorithm
 * @param choice Algorithm choice (1-5)
 * @return String representation of the algorithm name
 * 
 * This function maps numeric choices to algorithm names:
 * - 1: First Come First Serve (FCFS)
 * - 2: Shortest Job First (SJF)
 * - 3: Shortest Remaining Time First (SRTF)
 * - 4: Round Robin (RR)
 * - 5: Priority Scheduling (PRS)
 * - 0: Exit
 */
std::string scheduling_algo(int choice);

#endif
