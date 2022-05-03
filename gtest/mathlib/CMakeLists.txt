cmake_minimum_required(VERSION 3.5)  # CMake version check
project("math")               
set(CMAKE_CXX_STANDARD 11)         

message("CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}")
message("CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")
message("CMAKE_CURRENT_BINARY_DIR = ${CMAKE_CURRENT_BINARY_DIR}")

#set(${CMAKE_PROJECT_NAME}_SOURCE_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/math.cpp)
add_library(${CMAKE_PROJECT_NAME} SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/math.cpp)
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(OUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/out)
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION ${OUT_DIR}/dll)


enable_testing()
add_subdirectory(test)
