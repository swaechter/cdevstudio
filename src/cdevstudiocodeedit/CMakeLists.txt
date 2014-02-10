cmake_minimum_required(VERSION 2.8.9)
project(cdevstudiocodeedit)

find_package(C++Utils REQUIRED)
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
set_target_properties(cdevstudiocodeedit PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})

qt5_use_modules(cdevstudiocodeedit Widgets)

install(TARGETS cdevstudiocodeedit RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES CDevStudioCodeEdit.h CDevStudioCodeEditExport.h DESTINATION include)
