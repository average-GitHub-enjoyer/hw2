set(BINARY ${CMAKE_PROJECT_NAME})
set(LIBRARY ${CMAKE_PROJECT_NAME}_lib)

file(GLOB SOURCES LIST_DIRECTORIES false "*.hpp" "*.cpp")

add_subdirectory(${LIBRARY})

add_executable(${BINARY} ${SOURCES})
target_link_libraries(${BINARY} PRIVATE ${LIBRARY})
