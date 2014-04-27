cmake_minimum_required(VERSION 2.8.11)
project(pluginprojectexplorer)

find_package(C++Utils REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(PLUGINPROJECTEXPLORER_SRCS
  PluginProjectExplorer.cpp
)

set(PLUGINPROJECTEXPLORER_HDRS
  PluginProjectExplorerExport.h
  PluginProjectExplorer.h
)

add_definitions(-DPLUGINPROJECTEXPLORER_EXPORT)

add_library(pluginprojectexplorer SHARED ${PLUGINPROJECTEXPLORER_SRCS} ${PLUGINPROJECTEXPLORER_HDRS})
set_target_properties(pluginprojectexplorer PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(pluginprojectexplorer cdevstudioplatform Qt5::Widgets)

install(TARGETS pluginprojectexplorer RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
