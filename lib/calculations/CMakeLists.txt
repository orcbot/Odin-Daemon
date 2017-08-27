cmake_minimum_required(VERSION 2.6)

#exportLibrary
add_library(add add.cpp)
install (TARGETS add DESTINATION lib)

add_library(dot dot.cpp)
install (TARGETS dot DESTINATION lib)

add_library(mul mul.cpp)
install (TARGETS mul DESTINATION lib)

add_library(sub sub.cpp)
install (TARGETS sub DESTINATION lib)

add_library(mult mult.cpp)
install (TARGETS mult DESTINATION lib)
