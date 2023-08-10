cmake_minimum_required(VERSION 3.24.4)
project(coding)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_INIT "-Wall -Wextra -pedantic -std=c++20 -O3 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector")

add_executable(main main.cpp)