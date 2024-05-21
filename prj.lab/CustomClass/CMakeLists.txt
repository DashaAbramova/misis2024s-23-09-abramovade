add_library(CustomContainer CustomContainer.cpp CustomContainer.hpp IContainerBase.hpp)
set_property(TARGET CustomContainer PROPERTY CXX_STANDARD 20)
target_include_directories(CustomContainer PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS CustomContainer)
