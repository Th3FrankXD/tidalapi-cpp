cmake_minimum_required(VERSION 3.7)

project(tidalapi-cpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE "Debug")

# Link libraries
link_directories(deps/libs)
# Include headers
include_directories(deps/include headers include/tidalapi-cpp)
# Add source files
file(GLOB_RECURSE SOURCES src/*.cpp)
add_subdirectory(deps/libs/pybind11)
add_library(tidalapi-cpp SHARED ${SOURCES})
target_link_libraries(tidalapi-cpp PUBLIC pybind11::embed)