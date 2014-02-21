cmake_minimum_required(VERSION 2.8.11)
project(cdevstudioplatform)

find_package(C++Utils REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(CDEVSTUDIOPLATFORM_SRC
  CDevStudioPlatform.cpp
  CDevStudioWindow.cpp
  CDevStudioMenuBar.cpp
  CDevStudioStatusBar.cpp
  CDevStudioMenu.cpp
  CDevStudioAction.cpp
  CDevStudioProject.cpp
  CDevStudioBackend.cpp
)

set(CDEVSTUDIOPLATFORM_HDR
  CDevStudioPlatformExport.h
  CDevStudioPlatform.h
  CDevStudioWindow.h
  CDevStudioMenuBar.h
  CDevStudioStatusBar.h
  CDevStudioMenu.h
  CDevStudioAction.h
  CDevStudioProject.h
  CDevStudioBackend.h
  ICDevStudioPlugin.h
)

add_definitions(-DCDEVSTUDIOPLATFORM_EXPORT)

add_library(cdevstudioplatform SHARED ${CDEVSTUDIOPLATFORM_SRC} ${CDEVSTUDIOPLATFORM_HDR})
set_target_properties(cdevstudioplatform PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(cdevstudioplatform Qt5::Widgets)

install(TARGETS cdevstudioplatform RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES CDevStudioPlatformExport.h CDevStudioPlatform.h CDevStudioProject.h CDevStudioWindow.h CDevStudioMenuBar.h CDevStudioStatusBar.h CDevStudioMenu.h CDevStudioAction.h CDevStudioBackend.h DESTINATION include/cdevstudioplatform)
install(FILES ICDevStudioPlugin.h DESTINATION include/cdevstudioplatform)
