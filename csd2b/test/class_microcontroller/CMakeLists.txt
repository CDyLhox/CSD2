cmake_minimum_required(VERSION 3.20)
project(class_microcontroller LANGUAGES CXX)

add_executable(AMICROCONTROLLER main.cpp microcontroller.cpp)
target_compile_features(AMICROCONTROLLER PRIVATE cxx_std_20)