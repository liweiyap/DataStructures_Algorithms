include_directories("${PROJECT_SOURCE_DIR}/headers")

add_executable(stack-test stack-test.cpp)
target_link_libraries(stack-test stack)

add_executable(queue-test queue-test.cpp)
target_link_libraries(queue-test queue)

add_executable(bfs-test bfs-test.cpp)
target_link_libraries(bfs-test queue)
target_link_libraries(bfs-test std-input-parser)
target_link_libraries(bfs-test graph)
target_link_libraries(bfs-test breadth-first-search)

# add_executable(bst-test bst-test.cpp)

add_executable(bst-test2 bst-test2.cpp)