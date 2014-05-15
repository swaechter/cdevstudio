project(pluginsettings)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(PLUGINSETTINGS_SRCS
  PluginSettings.cpp
)

set(PLUGINSETTINGS_HDRS
  PluginSettingsExport.h
  PluginSettings.h
)

add_definitions(-DPLUGINSETTINGS_MAKE_LIBRARY)

add_library(pluginsettings SHARED ${PLUGINSETTINGS_SRCS})
set_target_properties(pluginsettings PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(pluginsettings plugincore cdevstudioplatform)

install(TARGETS pluginsettings RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${PLUGINSETTINGS_HDRS} DESTINATION include/pluginsettings)
