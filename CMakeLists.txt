cmake_minimum_required (VERSION 2.6)

project (freelist)

include_directories(src base)

add_executable(freelist 
	src/main.cpp 
	src/base/freelist.cpp)
