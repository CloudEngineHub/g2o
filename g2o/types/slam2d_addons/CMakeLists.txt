add_library(types_slam2d_addons ${G2O_LIB_TYPE}
  line_2d.h
  types_slam2d_addons.cpp types_slam2d_addons.h
  vertex_segment2d.cpp         vertex_segment2d.h
  edge_se2_segment2d.cpp       edge_se2_segment2d.h
  edge_se2_segment2d_line.cpp       edge_se2_segment2d_line.h
  edge_se2_segment2d_pointLine.cpp       edge_se2_segment2d_pointLine.h
  vertex_line2d.cpp            vertex_line2d.h
  edge_se2_line2d.cpp          edge_se2_line2d.h
  edge_line2d_pointxy.cpp          edge_line2d_pointxy.h
  edge_line2d.cpp          edge_line2d.h
  g2o_types_slam2d_addons_api.h
)

set_target_properties(types_slam2d_addons PROPERTIES OUTPUT_NAME ${LIB_PREFIX}types_slam2d_addons)
set_target_properties(types_slam2d_addons PROPERTIES
  VERSION ${G2O_LIB_VERSION}
  SOVERSION ${G2O_LIB_SOVERSION})
if (APPLE)
  set_target_properties(types_slam2d_addons PROPERTIES INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")
endif()
target_compile_features(types_slam2d_addons PUBLIC cxx_std_17)
target_link_libraries(types_slam2d_addons types_slam2d core)
if(G2O_HAVE_OPENGL)
  target_link_libraries(types_slam2d_addons opengl_helper)
endif()

target_include_directories(types_slam2d_addons PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/g2o/types/slam2d_addons>)

install(TARGETS types_slam2d_addons
  EXPORT ${G2O_TARGETS_EXPORT_NAME}
  RUNTIME DESTINATION ${RUNTIME_DESTINATION}
  LIBRARY DESTINATION ${LIBRARY_DESTINATION}
  ARCHIVE DESTINATION ${ARCHIVE_DESTINATION}
  INCLUDES DESTINATION ${INCLUDES_DESTINATION}
)

# Create alias target for easier usage when included as subdirectory
add_library(g2o::types_slam2d_addons ALIAS types_slam2d_addons)

file(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
install(FILES ${headers} DESTINATION ${INCLUDES_INSTALL_DIR}/types/slam2d_addons)
