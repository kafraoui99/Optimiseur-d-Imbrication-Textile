cmake_minimum_required(VERSION 3.10)
project(TextileNestingOptimizer VERSION 1.0)

# C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

# Source files
set(SOURCES
    src/main.cpp
    src/Rectangle.cpp
    src/NestingOptimizer.cpp
)

# Executable
add_executable(TextileNestingOptimizer ${SOURCES})

# Include directories
target_include_directories(TextileNestingOptimizer PRIVATE src)