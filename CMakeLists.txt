# CMakeList.txt : projet CMake pour CMakeProject2, incluez la source et définissez
cmake_minimum_required (VERSION 3.8)

project (CPproject)

set(CMAKE_C_STANDARD 11)
set(CMAKE_COMPILER_IS_GNUCC TRUE)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})

file (GLOB_RECURSE SOURCES "src/*.c" "src/*.h")

add_executable (CPproject ${SOURCES})
target_link_libraries(CPproject ${CURSES_LIBRARIES})
target_link_libraries(CPproject m)
