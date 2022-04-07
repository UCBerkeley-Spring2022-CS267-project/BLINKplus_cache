enable_testing()

# Tests need to be added as executables first
add_executable(env_test env_test.cu)

# I'm using C++17 in the test
target_compile_features(env_test PRIVATE cxx_std_11)

# Should be linked to the main library, as well as the Catch2 testing library
target_link_libraries(env_test PRIVATE nccl)
