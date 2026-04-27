cmake_minimum_required(VERSION 3.16)
project(gravity_simulation VERSION 0.1.0 LANGUAGES CXX)

include(FetchContent)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
set(BUILD_SHARED_LIBS OFF CACHE BOOL "" FORCE)
set(STDEXEC_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(STDEXEC_BUILD_TESTS OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
)

FetchContent_Declare(
    stdexec
    GIT_REPOSITORY https://github.com/nvidia/stdexec.git
    GIT_TAG main
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(raylib stdexec)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(gravity_simulation
    src/main.cpp
    src/App.cpp
    src/Particles.cpp
    src/Planet.cpp
)

target_include_directories(gravity_simulation PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(gravity_simulation PRIVATE raylib)

if (TARGET STDEXEC::stdexec)
    target_link_libraries(gravity_simulation PRIVATE STDEXEC::stdexec)
elseif (TARGET stdexec)
    target_link_libraries(gravity_simulation PRIVATE stdexec)
elseif (DEFINED stdexec_SOURCE_DIR)
    target_include_directories(gravity_simulation PRIVATE ${stdexec_SOURCE_DIR}/include)
endif()

if (MSVC)
    target_compile_options(gravity_simulation PRIVATE /W4 /permissive-)
else()
    target_compile_options(gravity_simulation PRIVATE -Wall -Wextra -Wpedantic)
endif()
