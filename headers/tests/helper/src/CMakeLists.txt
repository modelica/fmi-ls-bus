set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/helper/hdr")
set(canHeader ${header_path}/${PROJECT_NAME}_helper_can.h)
set(canSrc ${PROJECT_NAME}_helper_can.cpp)
set(canHeader2 ${header_path}/${PROJECT_NAME}_helper_can2.h)
set(canSrc2 ${PROJECT_NAME}_helper_can2.cpp)


add_library(${PROJECT_NAME}_can SHARED
  ${canHeader}
  ${canSrc})
target_include_directories(${PROJECT_NAME}_can
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/helper/hdr)
target_link_libraries(${PROJECT_NAME}_can
  pthread)

  add_library(${PROJECT_NAME}_can2 SHARED
  ${canHeader2}
  ${canSrc2})
target_include_directories(${PROJECT_NAME}_can2
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/helper/hdr)
target_link_libraries(${PROJECT_NAME}_can2
  pthread)

install(TARGETS ${PROJECT_NAME}_can
		LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
install(FILES ${canHeader} DESTINATION "${include_dest}")

install(TARGETS ${PROJECT_NAME}_can2
		LIBRARY DESTINATION "${lib_dest}"
    ARCHIVE DESTINATION "${lib_dest}"
    COMPONENT library)
install(FILES ${canHeader2} DESTINATION "${include_dest}")

add_definitions(-w)