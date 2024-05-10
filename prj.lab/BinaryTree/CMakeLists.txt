add_library(BinaryTree BinaryTree.cpp BinaryTree.hpp)
set_property(TARGET BinaryTree PROPERTY CXX_STANDARD 20)
target_include_directories(BinaryTree PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/..>
        $<INSTALL_INTERFACE:include>
)
install(TARGETS BinaryTree)