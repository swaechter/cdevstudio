cmake_minimum_required(VERSION 2.8.11)
project(pluginhelp)

find_package(C++Utils REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(PLUGINHELP_SRC
  PluginHelp.cpp
  DialogHelp.cpp
  DialogAbout.cpp
)

set(PLUGINHELP_HDR
  PluginHelpExport.h
  PluginHelp.h
  DialogHelp.h
  DialogAbout.h
)

set(PLUGINHELP_RESOURCE_IN
  Resource.qrc
)

add_definitions(-DPLUGINHELP_EXPORT)

qt5_add_resources(PLUGINHELP_RESOURCE_OUT ${PLUGINHELP_RESOURCE_IN})

add_library(pluginhelp SHARED ${PLUGINHELP_SRC} ${PLUGINHELP_HDR} ${PLUGINHELP_RESOURCE_OUT})
set_target_properties(pluginhelp PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(pluginhelp cdevstudioplatform Qt5::Widgets)

install(TARGETS pluginhelp RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
