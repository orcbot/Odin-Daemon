cmake_minimum_required(VERSION 2.6)

set (CMAKE_CXX_STANDARD 11)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#include variable
include_directories ("${PROJECT_SOURCE_DIR}/lib/variables")
add_subdirectory (lib/variables)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/variables/variable)

#include varList
include_directories ("${PROJECT_SOURCE_DIR}/lib/varList")
add_subdirectory (lib/varList)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/varList/varlist)

#include config
include_directories ("${PROJECT_SOURCE_DIR}/lib/helper")
add_subdirectory (lib/helper)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/helper/config)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/helper/daemonize)


#include add
include_directories ("${PROJECT_SOURCE_DIR}/lib/calculations")
add_subdirectory (lib/calculations)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/calculations/add)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/calculations/sub)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/calculations/dot)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/calculations/mult)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/calculations/mul)

#include flags
# SET(GCC_COVERAGE_COMPILE_FLAGS "-Wwrite-strings")
# add_definitions(${GCC_COVERAGE_COMPILE_FLAGS}
set (CMAKE_CXX_FLAGS "-Wno-write-strings")

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests.out tests/main.cpp ${EXTRA_LIBS})
target_link_libraries(runTests.out ${GTEST_LIBRARIES} pthread)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(Odin.out main.cpp ${EXTRA_LIBS})
