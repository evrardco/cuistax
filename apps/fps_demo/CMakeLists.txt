message(STATUS "Adding fps_demo to the apps")
set(app_src "fps_demo.cxx")
add_executable(
    fps_demo ${app_src}
)
target_link_libraries(
    fps_demo
    cuistax ${SDL2_LIBRARIES}
)
target_include_directories(
    fps_demo AFTER
    PRIVATE "${PROJECT_SOURCE_DIR}/src"
)
add_dependencies(fps_demo cuistax)