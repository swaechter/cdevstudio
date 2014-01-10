find_package(Qt5Core REQUIRED)

# Get current version
set(QT5_MAJOR ${Qt5Core_VERSION_MAJOR})
set(QT5_MINOR ${Qt5Core_VERSION_MINOR})
set(QT5_PATCH ${Qt5Core_VERSION_PATCH})

# Check for required version
if(QT5_MAJOR EQUAL 5 AND QT5_MINOR LESS 1)
	message(FATAL_ERROR "Your current Qt5 version is ${QT5_MAJOR}.${QT5_MINOR}.${QT5_PATCH}. But the required version is 5.1.0 or higher.")
endif()
