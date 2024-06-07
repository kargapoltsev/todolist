cmake_minimum_required(VERSION 3.18)
project(todolist)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)

enable_testing()

add_subdirectory(App)
