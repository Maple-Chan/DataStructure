INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/src)
LINK_DIRECTORIES(${PROJECT_BINARY_DIR}/lib)

ADD_EXECUTABLE(testSearchTree testSearchTree.cc)
TARGET_LINK_LIBRARIES(testSearchTree treeDataStructure)

ADD_EXECUTABLE(testAvlTree testAvlTree.cc)
TARGET_LINK_LIBRARIES(testAvlTree treeDataStructure)