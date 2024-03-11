cmake_minimum_required (VERSION 3.10.2)
project (fmi_3_ls_bus_header_test)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")


set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "helper/hdr")

add_subdirectory(helper/src)
add_subdirectory(test)
