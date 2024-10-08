cmake_minimum_required(VERSION 3.5.0)
project(lab3 VERSION ${PROJECT_VESRION} LANGUAGES C CXX)

add_executable(lab3 main.cpp)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

