cmake_minimum_required(VERSION 3.5.0)
project(aquarium
        VERSION 0.0.1
        DESCRIPTION "The project aquarium for OOP")

add_library(raylib SHARED IMPORTED)
if(CMAKE_SYSTEM_NAME MATCHES Linux)
    set_property(TARGET raylib PROPERTY IMPORTED_LOCATION /usr/lib/libraylib.so)
endif()
add_library(libaquarium STATIC include/aquarium/aquarium.hpp src/aquarium.cpp)

set(SOURCE src/main.cpp)
add_executable("${PROJECT_NAME}" "${SOURCE}")
target_link_libraries("${PROJECT_NAME}" PRIVATE raylib libaquarium)
