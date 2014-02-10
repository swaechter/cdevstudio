cmake_minimum_required(VERSION 2.8.9)
project(cdevstudiobackend)

find_package(C++Utils REQUIRED)
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
set_target_properties(cdevstudiobackend PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})

qt5_use_modules(cdevstudiobackend Core)

install(TARGETS cdevstudiobackend RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES CDevStudioBackend.h CDevStudioBackendExport.h DESTINATION include)
