# CMakeList.txt : projet CMake pour CMakeProject2, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

project ("CPproject")

find_package(Curses REQUIRED)

include_directories(${CURSES_INCLUDE_DIR})

# Ajoutez une source à l'exécutable de ce projet.
add_executable (CPproject "main.c" "main.h")
target_link_libraries(CPproject ${CURSES_LIBRARIES})

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
