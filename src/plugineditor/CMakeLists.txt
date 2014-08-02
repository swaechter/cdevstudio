project(plugineditor)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(PLUGINEDITOR_SRCS
  PluginEditor.cpp
  PluginPage.cpp
)

add_definitions(-DPLUGINEDITOR_MAKE_LIBRARY)

add_library(plugineditor SHARED ${PLUGINEDITOR_SRCS})
set_target_properties(plugineditor PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(plugineditor cdevstudioplatform)

install(TARGETS plugineditor RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
