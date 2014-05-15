project(cdevstudio)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

add_subdirectory(data)

set(CMAKE_AUTOMOC ON)

set(CDEVSTUDIO_SRCS
  main.cpp
  CDevStudio.cpp
)

add_executable(cdevstudio ${CDEVSTUDIO_SRCS})

target_link_libraries(cdevstudio cdevstudioplatform)

install(TARGETS cdevstudio RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
