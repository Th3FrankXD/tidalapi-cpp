cmake_minimum_required(VERSION 3.7)

project(tidalapi-cpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")
# Link static libraries
link_directories(deps/libs)
# Include all headers
include_directories(deps/include headers)
# Add source files
file(GLOB_RECURSE SOURCES "src/*.cpp")
add_library(tidalapi-cpp STATIC ${SOURCES})