cmake_minimum_required(VERSION 2.6)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#include variable
include_directories ("${PROJECT_SOURCE_DIR}/lib/variables/variable")
add_subdirectory (lib/variables)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/variables/variable)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests/main.cpp ${EXTRA_LIBS})
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
