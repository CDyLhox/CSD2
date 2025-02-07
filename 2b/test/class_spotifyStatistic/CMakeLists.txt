cmake_minimum_required(VERSION 3.20)
project(catalogue LANGUAGES CXX)

add_executable(catalogue main.cpp catalogue.cpp)
target_compile_features(catalogue PRIVATE cxx_std_20)