cmake_minimum_required(VERSION 4.1)
project(clegmed-app VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        clegmed
        URL https://github.com/jexxa-projects/CLegMed/archive/refs/tags/v0.1.2.tar.gz
)
FetchContent_MakeAvailable(clegmed)

# Anwendung definieren
add_executable(clegmed-app src/main.cpp)
target_link_libraries(clegmed-app PRIVATE clegmed::core)

# Voll-statisches Linken für das schlanke Docker Scratch-Image
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_link_options(clegmed-app PRIVATE -static)
endif()

## Testing
enable_testing()

# Include GoogleTest via FetchContent
include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        v1.17.0 # Secure, reproducible release tag for production
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)


# Create Test-Executable
add_executable(clegmed_template_tests tests/main_test.cpp)
gtest_discover_tests(clegmed_template_tests)
target_link_libraries(clegmed_template_tests
        PRIVATE
        gtest_main
        clegmed::core::base
        clegmed::plugins
        clegmed::utils
)