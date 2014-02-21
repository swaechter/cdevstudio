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
)

set(CDEVSTUDIO_HDR
  CDevStudio.h
  DialogCreateProject.h
  DialogSettings.h
)

set(CDEVSTUDIO_UI_IN
  DialogCreateProject.ui
  DialogSettings.ui
)

qt5_wrap_ui(CDEVSTUDIO_UI_OUT ${CDEVSTUDIO_UI_IN})

add_executable(cdevstudio ${CDEVSTUDIO_SRC} ${CDEVSTUDIO_HDR} ${CDEVSTUDIO_UI_OUT})
target_link_libraries(cdevstudio cdevstudioplatform Qt5::Widgets)

install(TARGETS cdevstudio RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
