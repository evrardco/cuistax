cmake_minimum_required(VERSION 3.10)
project(SDLTest)

enable_language(CXX)
set(CMAKE_CXX_COMPILER "g++")


find_package(PkgConfig REQUIRED)
pkg_search_module(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB SOURCES
    src/base/*.hxx
    src/base/*.cxx
    src/entities/*.hxx
    src/entities/*.cxx
    src/entities/physics/*.hxx
    src/entities/physics/*.cxx
    src/utils/*.hxx
    src/utils/*.cxx
    src/constants.hxx
    src/*.cxx
    src/*.hxx
)


add_executable(main src/main.cxx ${SOURCES})

target_link_libraries(main ${SDL2_LIBRARIES})
