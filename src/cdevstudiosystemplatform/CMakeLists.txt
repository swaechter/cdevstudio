cmake_minimum_required(VERSION 2.8.9)
project(cdevstudiosystemplatform)

find_package(C++Utils REQUIRED)
find_package(Qt5Core REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

set(CMAKE_AUTOMOC ON)

set(CDEVSTUDIOSYSTEMPLATFORM_SRC
  CDevStudioSystemPlatform.cpp
)

set(CDEVSTUDIOSYSTEMPLATFORM_HDR
  CDevStudioSystemPlatformExport.h
  CDevStudioSystemPlatform.h
)

add_definitions(-DCDEVSTUDIOSYSTEMPLATFORM_EXPORT)

add_library(cdevstudiosystemplatform SHARED ${CDEVSTUDIOSYSTEMPLATFORM_SRC} ${CDEVSTUDIOSYSTEMPLATFORM_HDR})
set_target_properties(cdevstudiosystemplatform PROPERTIES VERSION ${VERSION_NUMBER} SOVERSION ${VERSION_SONUMBER})
target_link_libraries(cdevstudiosystemplatform cdevstudiobackend)

qt5_use_modules(cdevstudiosystemplatform Core)

install(TARGETS cdevstudiosystemplatform RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES CDevStudioSystemPlatform.h CDevStudioSystemPlatformExport.h DESTINATION include)
