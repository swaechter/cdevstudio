find_package(Qt5Core REQUIRED)

# Check for the required version of Qt
if(${Qt5Core_VERSION_MAJOR} EQUAL 5 AND ${Qt5Core_VERSION_MINOR} LESS 1)
  message(FATAL_ERROR "For building this project you need the Qt version 5.1.0 or higer")
endif()

# With this function the build system is able to integrate translations into a resource file
function(qt5_add_translation_resource RESOURCE_OUT RESOURCE_IN TRANSLATION_IN)
  
  # Get the filename of the resource file
  get_filename_component(QRC_NAME ${RESOURCE_IN} NAME_WE)
  
  # Set resource variables
  set(QRC_SOURCE_IN ${CMAKE_CURRENT_SOURCE_DIR}/${QRC_NAME}.qrc)
  set(QRC_BINARY_IN ${CMAKE_CURRENT_BINARY_DIR}/${QRC_NAME}.qrc)
  set(QRC_BINARY_OUT ${CMAKE_CURRENT_BINARY_DIR}/qrc_${QRC_NAME}.cpp)
  
  # Copy resource file
  add_custom_command(OUTPUT ${QRC_BINARY_IN} COMMAND ${CMAKE_COMMAND} -E copy ${QRC_SOURCE_IN} ${QRC_BINARY_IN} DEPENDS ${QRC_SOURCE_IN})
  
  # Generate resource file
  add_custom_command(OUTPUT ${QRC_BINARY_OUT} COMMAND rcc -o ${QRC_BINARY_OUT} ${QRC_BINARY_IN} DEPENDS ${QRC_BINARY_IN} ${TRANSLATION_IN})
  
  # Add scope for the usage of the target
  set(${RESOURCE_OUT} ${QRC_BINARY_OUT} PARENT_SCOPE)
  
endfunction()
