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

add_library(div div.cpp)
install (TARGETS div DESTINATION lib)

add_library(abs abs.cpp)
install (TARGETS abs DESTINATION lib)

add_library(transpose transpose.cpp)
install (TARGETS transpose DESTINATION lib)

add_library(sin sin.cpp)
install (TARGETS sin DESTINATION lib)

add_library(cos cos.cpp)
install (TARGETS cos DESTINATION lib)

add_library(sqrt sqrt.cpp)
install (TARGETS sqrt DESTINATION lib)
