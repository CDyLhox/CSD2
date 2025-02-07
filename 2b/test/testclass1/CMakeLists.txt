cmake_minimum_required(VERSION 3.20)                #version number (duh)
project(CMakeTestProject LANGUAGES CXX)             #de naam van het project 

#set(CMAKE_CXX_STANDARD 14)                         # misschien de versie van cpp
                                                    #set geeft de versie van cpp aan globally 

add_executable(bookcase.cdl main.cpp bookcase.cpp book.cpp)         #de eerste naam is de uitput name en dan daarna alle file lists 
target_compile_features(bookcase.cdl PRIVATE cxx_std_20)