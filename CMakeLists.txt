cmake_minimum_required(VERSION 3.28)
project(Advanced)

set(CMAKE_CXX_STANDARD 17)

add_executable(Advanced main.cpp
        StacksAndQueues/Stack&Queues.cpp
        StacksAndQueues/Stack&Queues.h
        MapAndSet/Maps&Sets.h
        MapAndSet/Maps&Sets.cpp)
