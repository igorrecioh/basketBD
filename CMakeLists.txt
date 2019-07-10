cmake_minimum_required(VERSION 3.14)
project(bd_borrar)

set(CMAKE_CXX_STANDARD 14)

add_executable(bd_borrar main.cpp)

target_link_libraries(bd_borrar LINK_PUBLIC sqlite3)