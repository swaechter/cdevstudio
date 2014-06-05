project(pluginprojectexplorer)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(PLUGINPROJECTEXPLORER_SRCS
  PluginProjectExplorer.cpp
  ProjectExplorer.cpp
)

set(PLUGINPROJECTEXPLORER_HDRS
  PluginProjectExplorerExport.h
  PluginProjectExplorer.h
  ProjectExplorer.h
)

add_definitions(-DPLUGINPROJECTEXPLORER_MAKE_LIBRARY)

add_library(pluginprojectexplorer SHARED ${PLUGINPROJECTEXPLORER_SRCS})
set_target_properties(pluginprojectexplorer PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(pluginprojectexplorer cdevstudioplatform)

install(TARGETS pluginprojectexplorer RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${PLUGINPROJECTEXPLORER_HDRS} DESTINATION include/pluginprojectexplorer)
