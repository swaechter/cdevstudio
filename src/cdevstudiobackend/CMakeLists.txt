cmake_minimum_required(VERSION 2.8.11)
project(cdevstudiobackend)

find_package(Qt5Core REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_AUTOMOC ON)

set(CDEVSTUDIOBACKEND_SRC
  CDevStudioBackend.cpp
)

set(CDEVSTUDIOBACKEND_HDR
  CDevStudioBackendExport.h
  CDevStudioBackend.h
)

add_definitions(-DCDEVSTUDIOBACKEND_EXPORT)

add_library(cdevstudiobackend SHARED ${CDEVSTUDIOBACKEND_SRC} ${CDEVSTUDIOBACKEND_HDR})
target_link_libraries(cdevstudiobackend Qt5::Core)

set_target_properties(cdevstudiobackend PROPERTIES VERSION 0.0.1 SOVERSION 0)

install(TARGETS cdevstudiobackend RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES CDevStudioBackend.h CDevStudioBackendExport.h DESTINATION include)
