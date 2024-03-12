set(test_modules ${MODULE_LIST})

add_executable(${PROJECT_NAME}.test RunTests.cpp)

foreach(module IN LISTS test_modules)
  target_sources(${PROJECT_NAME}.test PRIVATE ${PROJECT_NAME}s_${module}.cpp)
  target_link_libraries(${PROJECT_NAME}.test
    ${PROJECT_NAME}_${module} gtest pthread)
endforeach()

target_compile_definitions(${PROJECT_NAME}.test 
  PRIVATE TEST_DIR="${CMAKE_CURRENT_LIST_DIR}/test")

install(TARGETS ${PROJECT_NAME}.test
        DESTINATION "${tool_dest}")