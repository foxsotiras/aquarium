cmake_minimum_required(VERSION 3.5.0)
project(project
        VERSION 0.0.1
        DESCRIPTION "The project aquarium for OOP")

if (MSVC)
    # warning level 4
    add_compile_options(/W4)
else()
    # additional warnings
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_library(raylib SHARED IMPORTED)
if(CMAKE_SYSTEM_NAME MATCHES Linux)
    set_property(TARGET raylib PROPERTY IMPORTED_LOCATION /usr/lib/libraylib.so)
endif()

add_library(aquarium STATIC include/aquarium/aquarium.hpp src/aquarium/aquarium.cpp)
target_include_directories(aquarium PRIVATE include/aquarium)
target_sources(aquarium PRIVATE 
    src/aquarium/fish.cpp
    src/aquarium/carp.cpp
    src/aquarium/pike.cpp
    src/aquarium/rock.cpp
)

set(SOURCE src/main.cpp)
add_executable("${PROJECT_NAME}" "${SOURCE}")
target_link_libraries("${PROJECT_NAME}" PRIVATE raylib aquarium)
file(INSTALL assets/ DESTINATION "${CMAKE_CURRENT_BINARY_DIR}/assets")
