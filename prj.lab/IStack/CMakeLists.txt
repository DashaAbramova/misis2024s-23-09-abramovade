add_library(IStackArr IStackArr.cpp IStackArr.hpp IStackBase.hpp)
set_property(TARGET IStackArr PROPERTY CXX_STANDARD 20)
target_include_directories(IStackArr PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS IStackArr)

add_library(IStackLst IStackLst.cpp IStackLst.hpp IStackBase.hpp)
set_property(TARGET IStackLst PROPERTY CXX_STANDARD 20)
target_include_directories(IStackLst PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS IStackLst)