# Process Scheduling Algorithms

This is a C++ implementation of various CPU scheduling algorithms commonly studied in Operating Systems. The project is built using Object-Oriented Programming principles to provide a clean and extensible implementation of scheduling algorithms.

## Implemented Algorithms

1. **First Come First Serve (FCFS)**
   - Non-preemptive scheduling algorithm
   - Processes are executed in the order they arrive

2. **Shortest Job First (SJF)**
   - Non-preemptive scheduling algorithm
   - Selects the process with shortest burst time

3. **Shortest Remaining Time First (SRTF)**
   - Preemptive version of SJF
   - Processes are scheduled based on shortest remaining time

4. **Round Robin (RR)**
   - Preemptive scheduling algorithm
   - Each process gets a fixed time quantum
   - Processes are executed in circular queue fashion

5. **Priority Scheduling (PRS)**
   - Priority-based scheduling
   - Processes are executed based on priority values

## Features

- Object-Oriented Design with inheritance and polymorphism
- Gantt chart visualization for process execution
- Calculation of important scheduling metrics:
  - Waiting Time
  - Turnaround Time
  - Response Time
  - Average metrics for all processes

## Building the Project

### Using CMake (Recommended)
```bash
# Create a build directory
mkdir build && cd build

# Generate build files
cmake ..

# Build the project
cmake --build .

# Run the program
./scheduler
```

### Using G++ Directly
```bash
g++ *.cpp -o scheduler
./scheduler
```

## Input Format
- Choose the scheduling algorithm (1-5)
- Enter the number of processes
- For each process, enter:
  - Arrival Time
  - Burst Time
  - Priority (only for Priority Scheduling)

## Project Structure

- `main.cpp` - Entry point and user interface
- `Process.h/cpp` - Process class definition and implementation
- `SchedulingBase.h/cpp` - Base classes and interfaces
- `SchedulingAlgorithms.h/cpp` - Implementation of scheduling algorithms
- `Utils.h/cpp` - Utility functions
- `CMakeLists.txt` - CMake build configuration
- `.gitignore` - Specifies which files Git should ignore

## Example Usage

```bash
Welcome to operating systems scheduling algorithms (Enhanced OOP Version)

1. First Come First Serve
2. Shortest Job First
3. Shortest Remaining Time First
4. Round Robin
5. Priority Scheduling
0. Exit

Enter your choice of scheduler: 1
Enter the number of processes: 3

Enter arrival time of process 1: 0
Enter burst time of process 1: 5

Enter arrival time of process 2: 1
Enter burst time of process 2: 3

Enter arrival time of process 3: 2
Enter burst time of process 3: 4
```

## Requirements

- C++11 or higher
- CMake 3.10 or higher (for CMake build)
- G++ or any C++ compiler

## Contributing

Feel free to contribute to this project by:
1. Implementing new scheduling algorithms
2. Adding more features
3. Improving the visualization
4. Fixing bugs or optimizing code

## License

This project is open source and available under the MIT License. 