cmake_minimum_required(VERSION 2.8.11)
project(cdevstudiocodeedit)

find_package(C++Utils REQUIRED)
find_package(Qt5Utils REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(CMAKE_AUTOMOC ON)

set(CDEVSTUDIOCODEEDIT_SRC
  CDevStudioCodeEdit.cpp
)

set(CDEVSTUDIOCODEEDIT_HDR
  CDevStudioCodeEditExport.h
  CDevStudioCodeEdit.h
)

add_definitions(-DCDEVSTUDIOCODEEDIT_EXPORT)

add_library(cdevstudiocodeedit SHARED ${CDEVSTUDIOCODEEDIT_SRC} ${CDEVSTUDIOCODEEDIT_HDR})
target_link_libraries(cdevstudiocodeedit Qt5::Widgets)

set_target_properties(cdevstudiocodeedit PROPERTIES VERSION 0.0.4 SOVERSION 0)

install(TARGETS cdevstudiocodeedit RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES CDevStudioCodeEdit.h CDevStudioCodeEditExport.h DESTINATION include)
