cmake_minimum_required(VERSION 3.5)  # CMake version check
project("math_test")               
set(CMAKE_CXX_STANDARD 11)         
find_package(GTest REQUIRED)
message("CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}")
message("CMAKE_CURRENT_SOURCE_DIR = ${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(${CMAKE_PROJECT_NAME}_test  ${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}_test  gtest ${CMAKE_DL_LIBS} ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS ${CMAKE_PROJECT_NAME}_test  DESTINATION ${OUT_DIR}/test)
set_target_properties(math_test PROPERTIES
        BUILD_WITH_INSTALL_RPATH FALSE
        LINK_FLAGS "-Wl,-rpath,$ORIGIN/../dll")


add_test(NAME math_test COMMAND ${OUT_DIR}/test/math_test)