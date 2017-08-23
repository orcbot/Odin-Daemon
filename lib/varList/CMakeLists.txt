cmake_minimum_required(VERSION 2.6)

#exportLibrary
add_library(varlist varlist.cpp)

install (TARGETS varlist DESTINATION lib)
