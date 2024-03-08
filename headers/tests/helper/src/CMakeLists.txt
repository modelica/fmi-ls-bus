set(test_modules can can2)

set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/helper/hdr")

foreach(module IN LISTS test_modules)
  set("${module}Header" ${header_path}/${PROJECT_NAME}_helper_${module}.h)
  message(Mit Quotes="${module}Header")
  message(Ohne Quotes=${module}Header)
  set("${module}Src" ${PROJECT_NAME}_helper_${module}.cpp)

  add_library(${PROJECT_NAME}_${module} SHARED
    ${${module}Header}
    ${${module}Src})
  target_include_directories(${PROJECT_NAME}_${module}
    PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
    ${${PROJECT_NAME}_SOURCE_DIR}/helper/hdr)
    target_link_libraries(${PROJECT_NAME}_${module}
    pthread)

  install(TARGETS ${PROJECT_NAME}_${module}
		LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
  install(FILES "${module}Header" DESTINATION "${include_dest}")
endforeach()

add_definitions(-w)
