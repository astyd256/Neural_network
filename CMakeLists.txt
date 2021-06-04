cmake_minimum_required(VERSION 3.19)
project(Neural_network)

set(CMAKE_CXX_STANDARD 14)

add_executable(Neural_network
        main.cpp
        Neuron.h
        Neuron.cpp
       )