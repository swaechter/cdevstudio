cmake_minimum_required(VERSION 2.8.11)
project(cdevstudioplatform)

find_package(C++Utils REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(CDEVSTUDIOPLATFORM_SRC
  CDevStudioPlatform.cpp
  CDevStudioPlatformPlugin.cpp
  CDevStudioWindowManager.cpp
  CDevStudioWindow.cpp
  CDevStudioPluginManager.cpp
  CDevStudioProjectManager.cpp
  CDevStudioProjectTemplate.cpp
  CDevStudioProject.cpp
  CDevStudioBackend.cpp
)

set(CDEVSTUDIOPLATFORM_HDR
  CDevStudioPlatformExport.h
  CDevStudioPlatform.h
  CDevStudioPlatformPlugin.h
  CDevStudioWindowManager.h
  CDevStudioWindow.h
  CDevStudioPluginManager.h
  CDevStudioProjectManager.h
  CDevStudioProjectTemplate.h
  CDevStudioProject.h
  CDevStudioBackend.h
  ICDevStudioPlugin.h
)

add_definitions(-DCDEVSTUDIOPLATFORM_EXPORT)

add_library(cdevstudioplatform SHARED ${CDEVSTUDIOPLATFORM_SRC} ${CDEVSTUDIOPLATFORM_HDR})
set_target_properties(cdevstudioplatform PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(cdevstudioplatform Qt5::Widgets)

install(TARGETS cdevstudioplatform RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${CDEVSTUDIOPLATFORM_HDR} DESTINATION include/cdevstudioplatform)
