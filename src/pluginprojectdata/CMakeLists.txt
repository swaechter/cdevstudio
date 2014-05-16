project(pluginprojectdata)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(PLUGINPROJECTDATA_SRCS
  PluginProjectData.cpp
)

set(PLUGINPROJECTDATA_HDRS
  PluginProjectDataExport.h
  PluginProjectData.h
)

set(PLUGINPROJECTDATA_RESOURCE_IN
  Resource.qrc
)

add_definitions(-DPLUGINPROJECTDATA_MAKE_LIBRARY)

qt5_add_resources(PLUGINPROJECTDATA_RESOURCE_OUT ${PLUGINPROJECTDATA_RESOURCE_IN})

add_library(pluginprojectdata SHARED ${PLUGINPROJECTDATA_SRCS} ${PLUGINPROJECTDATA_RESOURCE_OUT})
set_target_properties(pluginprojectdata PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(pluginprojectdata plugincore pluginprojects cdevstudioplatform)

install(TARGETS pluginprojectdata RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${PLUGINPROJECTDATA_HDRS} DESTINATION include/pluginprojectdata)
