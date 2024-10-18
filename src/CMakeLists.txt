cmake_minimum_required(VERSION 3.5.0)


add_executable(labs3 main.cpp)

add_library(d Double.cpp)
add_library(s Single.cpp)
add_library(dy Dynamic.cpp)


target_link_libraries(labs3 d)
target_link_libraries(labs3 s)
target_link_libraries(labs3 dy)

set(CPACK_GENERATOR ZIP)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")