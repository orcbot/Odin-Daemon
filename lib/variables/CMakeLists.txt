cmake_minimum_required(VERSION 2.6)

#exportLibrary
add_library(variable variable.cpp)

install (TARGETS variable DESTINATION lib)
