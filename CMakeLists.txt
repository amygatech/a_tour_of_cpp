# CMakeList.txt : Top-level CMake project file for C++ project.
cmake_minimum_required (VERSION 3.13)
project(a_tour_of_cpp VERSION 1.0 LANGUAGES CXX)
cmake_policy(SET CMP0074 NEW)

# ------------------------------------------------------------------------------
# Chapters
# ------------------------------------------------------------------------------
add_subdirectory (01_basics)
add_subdirectory (02_user_defined_types)
add_subdirectory (03_modularity)
add_subdirectory (04_classes)
add_subdirectory (05_template)


