add_executable(${PROJECT_NAME}.test RunTests.cpp)
set(test_modules can can2)
message(test_moduleshtt="${test_modules}")

foreach(module IN LISTS test_modules)
  target_sources(${PROJECT_NAME}.test PRIVATE ${PROJECT_NAME}s_${module}.cpp)
endforeach()

target_link_libraries(${PROJECT_NAME}.test
  ${PROJECT_NAME}_can ${PROJECT_NAME}_can2 gtest pthread)

target_compile_definitions(${PROJECT_NAME}.test 
  PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}/test")

install(TARGETS ${PROJECT_NAME}.test
        DESTINATION "${tool_dest}")

add_definitions(-w)