cmake_minimum_required(VERSION 3.24.4)
project(coding)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_INIT "-Wall -O3 -std=c++20 -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Wcast-align -Wcast-qual -Wnull-dereference -Woverloaded-virtual -Wformat=2 -Werror")

add_executable(main main.cpp)