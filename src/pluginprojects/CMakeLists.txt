cmake_minimum_required(VERSION 2.8.11)
project(pluginprojects)

find_package(C++Utils REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(PLUGINPROJECTS_SRCS
  PluginProjects.cpp
)

set(PLUGINPROJECTS_HDRS
  PluginProjectsExport.h
  PluginProjects.h
)

set(PLUGINPROJECTS_RESOURCE_IN
  Resource.qrc
)

add_definitions(-DPLUGINPROJECTS_EXPORT)

qt5_add_resources(PLUGINPROJECTS_RESOURCE_OUT ${PLUGINPROJECTS_RESOURCE_IN})

add_library(pluginprojects SHARED ${PLUGINPROJECTS_SRCS} ${PLUGINPROJECTS_HDRS} ${PLUGINPROJECTS_RESOURCE_OUT})
set_target_properties(pluginprojects PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(pluginprojects cdevstudioplatform Qt5::Widgets)

install(TARGETS pluginprojects RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
