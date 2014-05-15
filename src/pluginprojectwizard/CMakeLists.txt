project(pluginprojectwizard)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(PLUGINPROJECTWIZARD_SRCS
  PluginProjectWizard.cpp
)

set(PLUGINPROJECTWIZARD_HDRS
  PluginProjectWizardExport.h
  PluginProjectWizard.h
)

add_definitions(-DPLUGINPROJECTWIZARD_MAKE_LIBRARY)

add_library(pluginprojectwizard SHARED ${PLUGINPROJECTWIZARD_SRCS})
set_target_properties(pluginprojectwizard PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(pluginprojectwizard plugincore pluginprojects cdevstudioplatform)

install(TARGETS pluginprojectwizard RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${PLUGINPROJECTWIZARD_HDRS} DESTINATION include/pluginprojectwizard)
