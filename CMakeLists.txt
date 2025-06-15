cmake_minimum_required(VERSION 3.31)
project(MellissasStrings)

set(CMAKE_CXX_STANDARD 20)

# Test-Executable für Main
add_executable(MellissasStrings main.cpp
        String.cpp
        String.hpp)

# Test-Executable für GoogleTest

add_executable(MellissasStringsTests
        String.cpp
        String.hpp
        CarosTests.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg

target_link_libraries(MellissasStrings gtest_main)
target_link_libraries(MellissasStringsTests gtest_main)
add_test(NAME example_test COMMAND example)