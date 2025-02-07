cmake_minimum_required(VERSION 3.20)
project(instrumentclass LANGUAGES CXX)

add_executable(instrumentclass main.cpp stringInstrument.cpp instrument.cpp gitare.cpp)
target_compile_features(instrumentclass PRIVATE cxx_std_20)