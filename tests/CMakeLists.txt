include_directories("${PROJECT_SOURCE_DIR}/headers")

add_executable(stack-test stack-test.cpp)
target_link_libraries(stack-test stack)