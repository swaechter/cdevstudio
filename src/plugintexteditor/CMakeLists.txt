project(plugintexteditor)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(PLUGINTEXTEDITOR_SRCS
  PluginTextEditor.cpp
  PluginPage.cpp
)

set(PLUGINTEXTEDITOR_HDRS
  PluginTextEditorExport.h
  PluginTextEditor.h
  PluginPage.h
)

add_definitions(-DPLUGINTEXTEDITOR_MAKE_LIBRARY)

add_library(plugintexteditor SHARED ${PLUGINTEXTEDITOR_SRCS})
set_target_properties(plugintexteditor PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(plugintexteditor cdevstudioplatform)

install(TARGETS plugintexteditor RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${PLUGINTEXTEDITOR_HDRS} DESTINATION include/plugintexteditor)
