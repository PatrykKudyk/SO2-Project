cmake_minimum_required(VERSION 3.6)
project(Zadanie1)

set(CMAKE_C_STANDARD "${CMAKE_C_FLAGS} -Wall -Werror -lpdcurses")
set(CMAKE_CXX_FLAGS "-lncurses")
target_link_libraries(${PROJECT_NAME} ncurses)

set(SOURCE_FILES main.cpp)
set(CMAKE_CXX_STANDARD 17)
add_executable(ncurses ${SOURCE_FILES})