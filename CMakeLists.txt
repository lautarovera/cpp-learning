cmake_minimum_required(VERSION 3.20)
project(cpp_learning)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Warnings estrictas — importantes para aprender bien
add_compile_options(-Wall -Wextra -Wpedantic -Wconversion)

# Scratch pad
# add_executable(scratch scratch/main.cpp)

# Lecciones
add_subdirectory(lessons/01_value_semantics)
add_subdirectory(lessons/02_raii)
add_subdirectory(lessons/03_move_semantics)
add_subdirectory(lessons/04_smart_pointers)
add_subdirectory(lessons/05_classes)