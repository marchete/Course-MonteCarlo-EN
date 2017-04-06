cmake_minimum_required(VERSION 2.8.9)
project (tests)
add_executable(tests tests.cpp circle.cpp rectangle.cpp irregular.cpp combo.cpp)

# Includes Catch in the project:
#add_subdirectory(catch)
include_directories(${CATCH_INCLUDE_DIR} ${COMMON_INCLUDES})
enable_testing(true)  # Enables unit-testing.

add_dependencies(tests catch)

add_test(circle ./tests [circle])
add_test(rectangle ./tests [rectangle])
add_test(irregular ./tests [irregular])
add_test(combo ./tests [combo])