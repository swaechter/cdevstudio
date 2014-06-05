project(pluginprojects)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(PLUGINPROJECTS_SRCS
  PluginProjects.cpp
  ProjectTemplate.cpp
  DialogCreateProject.cpp
)

set(PLUGINPROJECTS_HDRS
  PluginProjectsExport.h
  PluginProjects.h
  ProjectTemplate.h
  DialogCreateProject.h
)

set(PLUGINPROJECTS_RESOURCE_IN
  Resource.qrc
)

qt5_add_resources(PLUGINPROJECTS_RESOURCE_OUT ${PLUGINPROJECTS_RESOURCE_IN})

add_definitions(-DPLUGINPROJECTS_MAKE_LIBRARY)

add_library(pluginprojects SHARED ${PLUGINPROJECTS_SRCS} ${PLUGINPROJECTS_RESOURCE_OUT})
set_target_properties(pluginprojects PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(pluginprojects cdevstudioplatform)

install(TARGETS pluginprojects RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${PLUGINPROJECTS_HDRS} DESTINATION include/pluginprojects)
