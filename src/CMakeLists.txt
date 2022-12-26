set(BINARY ${CMAKE_PROJECT_NAME})

file(GLOB SOURCES LIST_DIRECTORIES false "*.hpp" "*.cpp")

add_executable(${BINARY} ${SOURCES})

target_link_libraries(${BINARY} PRIVATE gtest)

add_test(NAME ${BINARY} COMMAND ${BINARY})
