set(TEST_BINARY ${CMAKE_PROJECT_NAME}_test)

file(GLOB_RECURSE TEST_SOURCES LIST_DIRECTORIES false "*.hpp" "*.cpp")

add_executable(${TEST_BINARY} ${TEST_SOURCES})

target_link_libraries(${TEST_BINARY} PRIVATE gtest ${CMAKE_PROJECT_NAME}_lib)

add_test(NAME ${TEST_BINARY} COMMAND ${TEST_BINARY})
