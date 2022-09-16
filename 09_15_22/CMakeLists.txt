cmake_minimum_required(VERSION 2.6)

# set the project name
project(Test)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_library(student SHARED book.cpp)

 
# Link runTests with what we want to test and the GTest and pthread library

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}  -Wl,--wrap=main")


add_executable(runTest1 test.cpp)
target_link_libraries(runTest1 ${GTEST_LIBRARIES} student pthread)
