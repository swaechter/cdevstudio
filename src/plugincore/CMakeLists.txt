project(plugincore)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(PLUGINCORE_SRCS
  PluginCore.cpp
  Window.cpp
  Backend.cpp
)

set(PLUGINCORE_HDRS
  PluginCoreExport.h
  PluginCore.h
  Window.h
  Backend.h
)

add_definitions(-DPLUGINCORE_MAKE_LIBRARY)

add_library(${PROJECT_NAME} SHARED ${PLUGINCORE_SRCS})
set_target_properties(plugincore PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(plugincore cdevstudioplatform)

install(TARGETS plugincore RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${PLUGINCORE_HDRS} DESTINATION include/plugincore)
