cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

set(PROJECT_MAJOR_VERSION 1)
set(PROJECT_MINOR_VERSION 0)
set(PROJECT_PATCH_VERSION 0)

set(CMAKE_MACOSX_RPATH 1)
set(CMAKE_BUILD_RPATH "$ORIGIN/lib;$ORIGIN/../lib;$ORIGIN")
set(CMAKE_INSTALL_RPATH "$ORIGIN/lib;$ORIGIN/../lib;$ORIGIN")

project(BreakfastBookkeeper
  LANGUAGES CXX
  DESCRIPTION "Breakfast Bookkeeper"
  VERSION
    ${PROJECT_MAJOR_VERSION}.${PROJECT_MINOR_VERSION}.${PROJECT_PATCH_VERSION}
)

find_package(Qt5
  COMPONENTS
    Widgets
    Core
  REQUIRED
)

include(cmake_helper/organize_source.cmake)
add_executable(${PROJECT_NAME} ${project_source_files})
add_executable(gccore::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

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
)
target_include_directories(${PROJECT_NAME}
  PRIVATE
    $<BUILD_INTERFACE:${private_header_dir}>
)

