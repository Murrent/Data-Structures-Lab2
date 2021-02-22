cmake_minimum_required(VERSION 3.17)
project(Lab2SM_Clion C)

set(CMAKE_C_STANDARD 99)

add_executable(Lab2SM_Clion src/main.c src/list/list.h src/list/list.c)

add_executable(load_test src/load_files/test_load_file.c src/load_files/load_file.h src/load_files/load_file.c)