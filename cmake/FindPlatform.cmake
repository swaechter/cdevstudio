# Several variables that are set depending on the platform

# Set the label for an executable
if(WIN32)
  set(PLATFORM WIN32)
elseif(APPLE)
  set(PLATFORM MACOSX_BUNDLE)
else() # Linux/Unix or 
  set(PLATFORM "")
endif()
