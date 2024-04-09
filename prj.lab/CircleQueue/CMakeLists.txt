add_library(CircleQueue CircleQueue.cpp CircleQueue.hpp)
set_property(TARGET CircleQueue PROPERTY CXX_STANDARD 20)
target_include_directories(CircleQueue PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
  $<INSTALL_INTERFACE:include>
)
install(TARGETS CircleQueue)