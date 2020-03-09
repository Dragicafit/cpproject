# CMakeList.txt : projet CMake pour CMakeProject2, incluez la source et définissez
cmake_minimum_required (VERSION 3.8)

project ("CPproject")

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})

file (GLOB_RECURSE SOURCES "src/*.c" "src/*.h")

add_executable (CPproject ${SOURCES})
target_link_libraries(CPproject ${CURSES_LIBRARIES})
target_link_libraries(CPproject m)
