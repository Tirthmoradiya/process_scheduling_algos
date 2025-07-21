cmake_minimum_required(VERSION 3.10)
project(process_scheduling_algos VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(scheduler
    main.cpp
    Process.cpp
    SchedulingAlgorithms.cpp
    SchedulingBase.cpp
    Utils.cpp
)

# Include directories
target_include_directories(scheduler PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
) 