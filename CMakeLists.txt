cmake_minimum_required(VERSION 2.8.9)
project(cdevstudio)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/")

set(VERSION_NUMBER 0.0.6)
set(VERSION_SONUMBER 0)

add_subdirectory(src)
add_subdirectory(doc)
