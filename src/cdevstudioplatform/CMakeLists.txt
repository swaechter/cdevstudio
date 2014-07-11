project(cdevstudioplatform)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_AUTOMOC ON)

set(CDEVSTUDIOPLATFORM_SRCS
  Platform.cpp
  IPlatform.cpp
  PluginManager.cpp
  PluginContainer.cpp
  IPlugin.cpp
  ProjectManager.cpp
  Project.cpp
  WindowManager.cpp
  Window.cpp
  Backend.cpp
)

set(CDEVSTUDIOPLATFORM_HDRS
  PlatformExport.h
  Platform.h
  IPlatform.h
  PluginManager.h
  PluginContainer.h
  IPlugin.h
  ProjectManager.h
  Project.h
  WindowManager.h
  Window.h
  Backend.h
)

add_definitions(-DCDEVSTUDIOPLATFORM_MAKE_LIBRARY)

add_library(cdevstudioplatform SHARED ${CDEVSTUDIOPLATFORM_SRCS})
set_target_properties(cdevstudioplatform PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(cdevstudioplatform Qt5::Widgets)

install(TARGETS cdevstudioplatform RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${CDEVSTUDIOPLATFORM_HDRS} DESTINATION include/cdevstudioplatform)
