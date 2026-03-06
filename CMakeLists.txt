cmake_minimum_required(VERSION 3.10)
project(OptimiseurImbrication VERSION 1.0)  # ← Changé

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")

set(SOURCES
    src/main.cpp
    src/Rectangle.cpp
    src/NestingOptimizer.cpp
)

add_executable(OptimiseurImbrication ${SOURCES})  # ← Changé

target_include_directories(OptimiseurImbrication PRIVATE src)