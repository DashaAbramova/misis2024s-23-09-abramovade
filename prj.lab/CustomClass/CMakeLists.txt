add_library(CustomClass CustomContainer.cpp CustomContainer.hpp IContainerBase.hpp)
set_property(TARGET CustomClass PROPERTY CXX_STANDARD 20)
target_include_directories(CustomClass PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS CustomClass)
