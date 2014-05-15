cmake_minimum_required(VERSION 2.8.11)
project(cdevstudio-workspace)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/")

find_package(C++Utils REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(VERSION_NUMBER 0.0.7)
set(VERSION_SONUMBER 0)

add_subdirectory(src)
add_subdirectory(doc)
