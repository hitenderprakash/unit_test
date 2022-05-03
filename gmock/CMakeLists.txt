cmake_minimum_required(VERSION 3.5)  # CMake version check
project("db_test")               
set(CMAKE_CXX_STANDARD 11)         
find_package(GTest REQUIRED)


message("CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}")
message("CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(${CMAKE_PROJECT_NAME}  ${CMAKE_CURRENT_SOURCE_DIR}/my_comp.cpp ${CMAKE_CURRENT_SOURCE_DIR}/test.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}  gtest gmock ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS ${CMAKE_PROJECT_NAME}  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/out)
