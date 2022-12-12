cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_BUILD_RPATH "$ORIGIN/lib;$ORIGIN/../lib;$ORIGIN")
set(CMAKE_INSTALL_RPATH "$ORIGIN/lib;$ORIGIN/../lib;$ORIGIN")

cmake_policy(SET CMP0100 NEW) # For *.hh, MOC

project(BreakfastBookkeeper LANGUAGES CXX DESCRIPTION "Breakfast Bookkeeper")

find_package(Qt5
  COMPONENTS
    Widgets
    Core
    Gui
  REQUIRED
)

include(cmake_helper/organize_source.cmake)
add_executable(${PROJECT_NAME} ${project_source_files})
add_executable(gccore::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

include(cmake_helper/versioning.cmake)
GCCORE_BreakfastBookkeeper_ConfigureVersion(${PROJECT_NAME})

find_program(ccache_binary_path ccache REQUIRED)
set_target_properties(${PROJECT_NAME}
  PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED on
    CXX_EXTENSIONS off
    CXX_COMPILER_LAUNCHER ${ccache_binary_path}
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION}
    AUTOMOC on
    AUTOUIC on
    AUTORCC on
)
target_compile_definitions(${PROJECT_NAME}
  PUBLIC
    ${PROJECT_NAME}_VERSION="${PROJECT_VERSION}"
)
target_link_libraries(${PROJECT_NAME}
  PRIVATE
    Qt5::Widgets
    Qt5::Core
    Qt5::Gui
)
target_include_directories(${PROJECT_NAME}
  PRIVATE
    $<BUILD_INTERFACE:${private_header_dir}>
)

