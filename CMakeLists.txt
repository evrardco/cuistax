cmake_minimum_required(VERSION 3.10)
project(SDLTest)

enable_language(CXX)
set(CMAKE_CXX_COMPILER "g++")
if(log_enabled)
    add_definitions(-DCUISTAX_LOG)
    message("Enabled logs")
endif(log_enabled)
if(log_level)
    add_definitions("-DCUISTAX_LOG_LEVEL=${log_level}")
    message("Enabled logs with log_level=${log_level}")
endif(log_level)
find_package(PkgConfig REQUIRED)
pkg_search_module(SDL2 REQUIRED sdl2)
include_directories(${SDL2_INCLUDE_DIRS})

file(GLOB LIBCUISTAX_SOURCES
    src/base/*.hxx
    src/base/*.cxx
    src/drawables/*.cxx
    srd/drawables/*.hxx 
    src/entities/*.hxx
    src/entities/*.cxx
    src/entities/physics/*.hxx
    src/entities/physics/*.cxx
    src/entities/ui/*.hxx
    src/entities/ui/*.cxx
    src/utils/*.hxx
    src/utils/*.cxx
    src/utils/drawables/*.hxx
    src/utils/drawables/*.cxx
    src/resource/*.hxx
    src/resource/*.cxx
    src/constants.hxx
    src/*.cxx
    src/*.hxx
)
add_library(cuistax STATIC ${LIBCUISTAX_SOURCES})


add_executable(main src/main.cxx ${LIBCUISTAX_SOURCES})
set_property(TARGET main PROPERTY CXX_STANDARD 20)
target_link_libraries(main ${SDL2_LIBRARIES})
set(RESOURCE_DIR "resources")
configure_file(${RESOURCE_DIR}/graphics/fonts/zig_green_size16_cell18.bmp ${RESOURCE_DIR}/graphics/fonts/zig_green_size16_cell18.bmp COPYONLY)