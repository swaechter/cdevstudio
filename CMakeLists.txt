cmake_minimum_required(VERSION 2.8.11)
project(cdevstudio)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules/")

add_subdirectory(src)
add_subdirectory(doc)
