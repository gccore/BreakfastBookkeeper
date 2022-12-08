cmake_policy(SET CMP0100 NEW) # For *.hh, MOC

set(header_dir ${PROJECT_SOURCE_DIR}/include)
set(source_dir ${PROJECT_SOURCE_DIR}/source)

set(private_header_dir ${header_dir}/private)
set(private_ui_header_dir ${private_header_dir}/breakfast_bookkeeper/ui)
set(private_ui_source_dir ${source_dir}/ui)

file(GLOB source_files
  ${source_dir}/*.cc
  ${private_ui_source_dir}/*.cc
)
file(GLOB private_header_files
  ${private_header_dir}/breakfast_bookkeeper/*.hh
  ${private_ui_header_dir}/*.hh
)
file(GLOB cmake_helper_files
  ${PROJECT_SOURCE_DIR}/cmake_helper/*.cmake
)

source_group("sources"
  FILES
    ${source_files}
)
source_group("headers"
  FILES
    ${private_header_files}
)
source_group("cmake helpers"
  FILES
    ${cmake_helper_files}
)

set(project_source_files
  ${source_files}
  ${private_header_files}
  ${cmake_helper_files}
)
