project(cdevstudio)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/../)

add_subdirectory(data)

set(CMAKE_AUTOMOC ON)

set(CDEVSTUDIO_SRCS
  main.cpp
  CDevStudio.cpp
  DialogPlugins.cpp
  DialogHelp.cpp
  DialogAbout.cpp
)

set(CDEVSTUDIO_UI_IN
  DialogPlugins.ui
  DialogHelp.ui
  DialogAbout.ui
)

qt5_wrap_ui(CDEVSTUDIO_UI_OUT ${CDEVSTUDIO_UI_IN})

add_executable(cdevstudio ${CDEVSTUDIO_SRCS} ${CDEVSTUDIO_UI_OUT})

target_link_libraries(cdevstudio cdevstudioplatform)

install(TARGETS cdevstudio RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
