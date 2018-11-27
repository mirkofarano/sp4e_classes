cmake_minimum_required(VERSION 2.6)
project(HW2)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif ()

add_subdirectory(src) # directory you want to add or contains executable files
