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
  ProjectExplorerView.cpp
  ObjectExplorerView.cpp
  Utils.cpp
  DialogCreateProject.cpp
  DialogFindText.cpp
  DialogReplaceText.cpp
  DialogProjectSettings.cpp
  DialogSettings.cpp
  DialogHelp.cpp
  DialogAbout.cpp
)

set(CDEVSTUDIO_HDR
  CDevStudio.h
  ProjectExplorerView.h
  ObjectExplorerView.h
  Utils.h
  DialogCreateProject.h
  DialogFindText.h
  DialogReplaceText.h
  DialogProjectSettings.h
  DialogSettings.h
  DialogHelp.h
  DialogAbout.h
)

set(CDEVSTUDIO_UI_IN
  CDevStudio.ui
  DialogCreateProject.ui
  DialogFindText.ui
  DialogReplaceText.ui
  DialogProjectSettings.ui
  DialogSettings.ui
  DialogHelp.ui
  DialogAbout.ui
)

set(CDEVSTUDIO_TRANSLATION_IN
  data/translation/translation_en.ts
  data/translation/translation_de.ts
)

set(CDEVSTUDIO_RESOURCE_IN
  Resource.qrc
)

qt5_wrap_ui(CDEVSTUDIO_UI_OUT ${CDEVSTUDIO_UI_IN})

qt5_create_translation(CDEVSTUDIO_TRANSLATION_OUT ${CDEVSTUDIO_SRC} ${CDEVSTUDIO_HDR} ${CDEVSTUDIO_UI_IN} ${CDEVSTUDIO_TRANSLATION_IN})

qt5_add_resources(CDEVSTUDIO_RESOURCE_OUT ${CDEVSTUDIO_RESOURCE_IN})

add_executable(cdevstudio ${CDEVSTUDIO_SRC} ${CDEVSTUDIO_HDR} ${CDEVSTUDIO_UI_OUT} ${CDEVSTUDIO_TRANSLATION_OUT} ${CDEVSTUDIO_RESOURCE_OUT})
target_link_libraries(cdevstudio cdevstudiocodeedit cdevstudioplatform Qt5::Widgets)

install(TARGETS cdevstudio RUNTIME DESTINATION bin LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/translation_en.qm ${CMAKE_CURRENT_BINARY_DIR}/translation_de.qm DESTINATION share/cdevstudio)
