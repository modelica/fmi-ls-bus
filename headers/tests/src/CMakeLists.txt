set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include/${PROJECT_NAME}")
set(canHeader ${header_path}/${PROJECT_NAME}_can.h)
set(canSrc ${PROJECT_NAME}_can.cpp)


add_library(${PROJECT_NAME} SHARED
  ${canHeader}
  ${src})
target_include_directories("${PROJECT_NAME}"
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME}
  pthread)



install(TARGETS "${PROJECT_NAME}"
		LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
install(FILES ${canHeader} DESTINATION "${include_dest}")
