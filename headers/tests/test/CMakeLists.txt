add_executable(${PROJECT_NAME}.test
  RunTests.cpp
  ${PROJECT_NAME}s_can.cpp
  ${PROJECT_NAME}s_can2.cpp)
target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME}_can ${PROJECT_NAME}_can2 gtest pthread)
target_compile_definitions(${PROJECT_NAME}.test 
  PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}/test")

install(TARGETS ${PROJECT_NAME}.test
        DESTINATION "${tool_dest}")

add_definitions(-w)