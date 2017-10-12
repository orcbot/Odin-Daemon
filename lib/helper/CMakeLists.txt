cmake_minimum_required(VERSION 2.6)

#exportLibrary
add_library(config config.cpp)
add_library(daemonize daemonize.cpp)

install (TARGETS config DESTINATION lib)
