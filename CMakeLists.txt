cmake_minimum_required(VERSION 2.8)

project(emogen)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(ASSETDIR "${emogen_SOURCE_DIR}/assets" )
set(HEADERDIR "${emogen_SOURCE_DIR}/include" )
set(SRCDIR "${emogen_SOURCE_DIR}/src" )

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}" )

add_subdirectory(src)


