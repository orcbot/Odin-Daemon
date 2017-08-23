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

#include add
include_directories ("${PROJECT_SOURCE_DIR}/lib/calculations")
add_subdirectory (lib/calculations)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/calculations/add)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/calculations/sub)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/calculations/dot)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/calculations/mult)
set (EXTRA_LIBS ${EXTRA_LIBS} lib/calculations/mul)

# #include sub
# include_directories ("${PROJECT_SOURCE_DIR}/lib/calculations/sub")
# add_subdirectory (lib/calculations)
# set (EXTRA_LIBS ${EXTRA_LIBS} lib/calculations/sub)

# #include mul
# include_directories ("${PROJECT_SOURCE_DIR}/lib/calculations/mul")
# add_subdirectory (lib/calculations)
# set (EXTRA_LIBS ${EXTRA_LIBS} lib/calculations/mul)

# #include mult
# include_directories ("${PROJECT_SOURCE_DIR}/lib/calculations/mult")
# add_subdirectory (lib/calculations)
# set (EXTRA_LIBS ${EXTRA_LIBS} lib/calculations/mult)

# #include dot
# include_directories ("${PROJECT_SOURCE_DIR}/lib/calculations/dot")
# add_subdirectory (lib/calculations)
# set (EXTRA_LIBS ${EXTRA_LIBS} lib/calculations/dot)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests.out tests/main.cpp ${EXTRA_LIBS})
target_link_libraries(runTests.out ${GTEST_LIBRARIES} pthread)

# Link runTests with what we want to test and the GTest and pthread library
add_executable(Odin.out main.cpp ${EXTRA_LIBS})
