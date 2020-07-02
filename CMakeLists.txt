cmake_minimum_required(VERSION 3.10)
project(read_write_test)

set(CMAKE_CXX_STANDARD 14)

add_executable(server server.cpp)

add_executable(client client.cpp)
