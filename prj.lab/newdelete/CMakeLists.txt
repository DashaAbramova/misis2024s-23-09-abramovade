add_library(newdelete newdelete.cpp newdelete.hpp)
set_property(TARGET newdelete PROPERTY CXX_STANDARD 20)
target_include_directories(newdelete PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS newdelete)