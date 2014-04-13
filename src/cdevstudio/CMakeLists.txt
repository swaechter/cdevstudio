cmake_minimum_required(VERSION 2.8.11)
project(cdevstudio)

find_package(C++Utils REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5LinguistTools REQUIRED)

add_subdirectory(data)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(CDEVSTUDIO_SRC
  main.cpp
  CDevStudio.cpp
  DialogCreateProject.cpp
  DialogSettings.cpp
  DialogPlugins.cpp
  DialogHelp.cpp
  DialogAbout.cpp
)

set(CDEVSTUDIO_HDR
  CDevStudio.h
  DialogCreateProject.h
  DialogSettings.h
  DialogPlugins.h
  DialogHelp.h
  DialogAbout.h
)

set(CDEVSTUDIO_UI_IN
  DialogCreateProject.ui
  DialogSettings.ui
  DialogPlugins.ui
  DialogHelp.ui
  DialogAbout.ui
)

set(CDEVSTUDIO_RESOURCE_IN
  Resource.qrc
)

qt5_wrap_ui(CDEVSTUDIO_UI_OUT ${CDEVSTUDIO_UI_IN})

qt5_add_resources(CDEVSTUDIO_RESOURCE_OUT ${CDEVSTUDIO_RESOURCE_IN})

add_executable(cdevstudio ${CDEVSTUDIO_SRC} ${CDEVSTUDIO_HDR} ${CDEVSTUDIO_UI_OUT} ${CDEVSTUDIO_RESOURCE_OUT})
target_link_libraries(cdevstudio cdevstudioplatform Qt5::Widgets)

install(TARGETS cdevstudio RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
