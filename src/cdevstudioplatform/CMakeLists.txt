cmake_minimum_required(VERSION 2.8.11)
project(cdevstudioplatform)

find_package(C++Utils REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(CDEVSTUDIOPLATFORM_SRCS
  Platform.cpp
  IPlatform.cpp
  WindowManager.cpp
  Window.cpp
  PluginManager.cpp
  ProjectManager.cpp
  ProjectTemplate.cpp
  Project.cpp
  Backend.cpp
)

set(CDEVSTUDIOPLATFORM_HDRS
  PlatformExport.h
  Platform.h
  WindowManager.h
  Window.h
  PluginManager.h
  ProjectManager.h
  ProjectTemplate.h
  Project.h
  Backend.h
  interfaces/IPlugin.h
  interfaces/IPlatform.h
)

add_definitions(-DCDEVSTUDIOPLATFORM_MAKE_LIBRARY)

add_library(cdevstudioplatform SHARED ${CDEVSTUDIOPLATFORM_SRCS} ${CDEVSTUDIOPLATFORM_HDRS})
set_target_properties(cdevstudioplatform PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(cdevstudioplatform Qt5::Widgets)

install(TARGETS cdevstudioplatform RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${CDEVSTUDIOPLATFORM_HDRS} DESTINATION include/cdevstudioplatform)
