cmake_minimum_required(VERSION 3.20)
project(class_realbook LANGUAGES CXX)

add_executable(realbook main.cpp realbook.cpp)
target_compile_features(realbook PRIVATE cxx_std_20)