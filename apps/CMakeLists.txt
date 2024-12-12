message(STATUS "Compiling applications")
file(
    GLOB app_dirs LIST_DIRECTORIES true RELATIVE "${PROJECT_SOURCE_DIR}/apps" 
    "*"
)
list(REMOVE_ITEM app_dirs "CMakeLists.txt")
foreach(f ${app_dirs})
    add_subdirectory("${f}")
endforeach(f)
