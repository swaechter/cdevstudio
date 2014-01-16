cmake_minimum_required(VERSION 2.8.11)
project(cdevstudioprojectplatform)

find_package(C++Utils REQUIRED)
find_package(Qt5Utils REQUIRED)
find_package(Qt5Core REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(CDEVSTUDIOPROJECTPLATFORM_SRC
  CDevStudioProjectPlatform.cpp
  CDevStudioProject.cpp
)

set(CDEVSTUDIOPROJECTPLATFORM_HDR
  CDevStudioProjectPlatformExport.h
  CDevStudioProjectPlatform.h
  CDevStudioProject.h
)

add_definitions(-DCDEVSTUDIOPROJECTPLATFORM_EXPORT)

add_library(cdevstudioprojectplatform SHARED ${CDEVSTUDIOPROJECTPLATFORM_SRC} ${CDEVSTUDIOPROJECTPLATFORM_HDR})
target_link_libraries(cdevstudioprojectplatform cdevstudiobackend Qt5::Core)

set_target_properties(cdevstudioprojectplatform PROPERTIES VERSION 0.0.6 SOVERSION 0)

install(TARGETS cdevstudioprojectplatform RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES CDevStudioProjectPlatform.h CDevStudioProjectPlatformExport.h CDevStudioProject.h DESTINATION include)
