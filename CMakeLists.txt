cmake_minimum_required(VERSION 3.5)

project(tasks)


find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(${PROJECT_NAME} main_0#.cpp)


set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)
