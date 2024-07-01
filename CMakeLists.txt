cmake_minimum_required(VERSION 3.28)
project(Leetcode)

set(CMAKE_CXX_STANDARD 17)

add_executable(Leetcode main.cpp)

add_executable(two_sum "Interview classic 150 questions/two_sum.cpp")
add_executable(add_two_numbers "Interview classic 150 questions/add_two_numbers.cpp")
add_executable(merge_sorted_array "Interview classic 150 questions/merge_sorted_array.cpp")
add_executable(remove_element "Interview classic 150 questions/remove_element.cpp")
add_executable(remove_duplicates_from_sorted_array "Interview classic 150 questions/remove_duplicates_from_sorted_array.cpp")