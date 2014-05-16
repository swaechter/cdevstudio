project(pluginhelp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(PLUGINHELP_SRCS
  PluginHelp.cpp
  DialogHelp.cpp
  DialogAbout.cpp
)

set(PLUGINHELP_HDRS
  PluginHelpExport.h
  PluginHelp.h
  DialogHelp.h
  DialogAbout.h
)

add_definitions(-DPLUGINHELP_MAKE_LIBRARY)

add_library(pluginhelp SHARED ${PLUGINHELP_SRCS})
set_target_properties(pluginhelp PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(pluginhelp plugincore cdevstudioplatform)

install(TARGETS pluginhelp RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${PLUGINHELP_HDRS} DESTINATION include/pluginhelp)
