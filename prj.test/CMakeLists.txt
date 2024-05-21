add_executable(test_complex test_complex.cpp)
target_link_libraries(test_complex complex)

add_executable(test_rational test_rational.cpp )
target_link_libraries(test_rational rational)

add_executable(test_dynarr test_dynarr.cpp )
target_link_libraries(test_dynarr dynarr)

add_executable(test_stackarr test_stackarr.cpp)
target_link_libraries(test_stackarr stackarr)

add_executable(test_newdelete test_newdelete.cpp)
target_link_libraries(test_newdelete newdelete)

add_executable(test_stacklst test_stacklst.cpp)
target_link_libraries(test_stacklst stacklst)

add_executable(test_CircleQueue test_CircleQueue.cpp)
target_link_libraries(test_CircleQueue CircleQueue)

add_executable(test_IStackArr test_IStackArr.cpp)
target_link_libraries(test_IStackArr IStackArr)

add_executable(test_IStackLst test_IStackLst.cpp)
target_link_libraries(test_IStackLst IStackLst)

add_executable(test_BinaryTree test_BinaryTree.cpp)
target_link_libraries(test_BinaryTree BinaryTree)

add_executable(test_CustomContainer test_CustomContainer.cpp)
target_link_libraries(test_CustomContainer CustomContainer)


