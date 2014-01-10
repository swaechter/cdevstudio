cmake_minimum_required(VERSION 2.8.11)
project(cdevstudioplatform)

find_package(C++Utils REQUIRED)
find_package(Qt5Core REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/..)

set(CMAKE_AUTOMOC ON)

set(CDEVSTUDIOPLATFORM_SRC
  CDevStudioPlatform.cpp
  CDevStudioProject.cpp
)

set(CDEVSTUDIOPLATFORM_HDR
  CDevStudioPlatformExport.h
  CDevStudioPlatform.h
  CDevStudioProject.h
)

add_definitions(-DCDEVSTUDIOPLATFORM_EXPORT)

add_library(cdevstudioplatform SHARED ${CDEVSTUDIOPLATFORM_SRC} ${CDEVSTUDIOPLATFORM_HDR})
target_link_libraries(cdevstudioplatform cdevstudiobackend Qt5::Core)

set_target_properties(cdevstudioplatform PROPERTIES VERSION 0.0.2 SOVERSION 0)

install(TARGETS cdevstudioplatform RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES CDevStudioPlatform.h CDevStudioPlatformExport.h CDevStudioProject.h DESTINATION include)
