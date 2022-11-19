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
    src/drawables/*.cxx
    srd/drawables/*.hxx 
    src/entities/*.hxx
    src/entities/*.cxx
    src/entities/physics/*.hxx
    src/entities/physics/*.cxx
    src/utils/*.hxx
    src/utils/*.cxx
    src/utils/graphics/*.hxx
    src/utils/graphics/*.cxx
    src/resource/*.hxx
    src/resource/*.cxx
    src/constants.hxx
    src/*.cxx
    src/*.hxx
)


add_executable(main src/main.cxx ${SOURCES})

target_link_libraries(main ${SDL2_LIBRARIES})
set(RESOURCE_DIR "resources")
configure_file(${RESOURCE_DIR}/graphics/fonts/zig_green_size16_cell18.bmp ${RESOURCE_DIR}/graphics/fonts/zig_green_size16_cell18.bmp COPYONLY)