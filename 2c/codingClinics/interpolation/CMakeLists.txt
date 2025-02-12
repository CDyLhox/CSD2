cmake_minimum_required(VERSION 3.20)
project(myname LANGUAGES CXX)

add_executable(myname main.cpp interpoll.cpp)
target_compile_features(myname PRIVATE cxx_std_20)
