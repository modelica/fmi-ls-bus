cmake_minimum_required(VERSION 3.10.2)
project(fmi_3_ls_bus_header_test)

if("${MODULE_LIST}" STREQUAL "all" OR "${MODULE_LIST}" STREQUAL "")
  list(REMOVE_ITEM MODULE_LIST all)
  list(APPEND MODULE_LIST can)
endif()

set(CMAKE_CXX_STANDARD 17)

enable_testing()
find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME})
target_link_libraries(${PROJECT_NAME} GTest::gtest GTest::gtest_main)
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

target_include_directories(${PROJECT_NAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/helper/hdr
  ${CMAKE_CURRENT_SOURCE_DIR}/../fmi-standard/headers
  ${CMAKE_CURRENT_SOURCE_DIR}/../headers)

foreach(module IN LISTS MODULE_LIST)
  # Add helper and test code for module
  target_sources(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/helper/src/fmi_3_ls_bus_header_test_helper_${module}.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/test/fmi_3_ls_bus_header_tests_${module}.cpp)
endforeach()

gtest_discover_tests(${PROJECT_NAME})
