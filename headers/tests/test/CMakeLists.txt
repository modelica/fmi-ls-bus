list(APPEND test_modules RunTests.cpp ${PROJECT_NAME}_can.cpp ${PROJECT_NAME}_can2.cpp)

add_executable(${PROJECT_NAME}.test)
target_sources(${PROJECT_NAME}.test PRIVATE ${APPEND})

target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME}_can ${PROJECT_NAME}_can2 gtest pthread)

target_compile_definitions(${PROJECT_NAME}.test 
  PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}/test")

install(TARGETS ${PROJECT_NAME}.test
        DESTINATION "${tool_dest}")

add_definitions(-w)