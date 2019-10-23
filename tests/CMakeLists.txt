include_directories("${PROJECT_SOURCE_DIR}/headers")

add_executable(stack-test stack-test.cpp)
target_compile_features(stack-test PRIVATE cxx_lambdas)    # use C++11
target_link_libraries(stack-test stack)