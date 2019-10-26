include_directories("${PROJECT_SOURCE_DIR}/headers")

add_executable(stack-test stack-test.cpp)
target_link_libraries(stack-test stack)

add_executable(queue-test queue-test.cpp)
target_link_libraries(queue-test queue)

add_executable(bfs bfs.cpp)
target_link_libraries(bfs queue)
target_link_libraries(bfs std-input-parser)