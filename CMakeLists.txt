cmake_minimum_required(VERSION 3.22)
project(APA2)

set(CMAKE_CXX_STANDARD 20)

add_executable(APA2 main.cpp quick_sort.h merge_sort.h heap_sort.h cocktail_sort.h counting_sort.h)
