#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "AStarProject::AStarProject" for configuration "Debug"
set_property(TARGET AStarProject::AStarProject APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(AStarProject::AStarProject PROPERTIES
  IMPORTED_LINK_INTERFACE_LANGUAGES_DEBUG "CXX"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/lib/libAStarProject.a"
  )

list(APPEND _cmake_import_check_targets AStarProject::AStarProject )
list(APPEND _cmake_import_check_files_for_AStarProject::AStarProject "${_IMPORT_PREFIX}/lib/libAStarProject.a" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
