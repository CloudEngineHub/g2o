add_library(types_slam3d_addons ${G2O_LIB_TYPE}
  vertex_se3_euler.cpp
  vertex_se3_euler.h
  edge_se3_euler.cpp
  edge_se3_euler.h
  vertex_plane.cpp
  vertex_plane.h
  edge_se3_plane_calib.cpp
  edge_se3_plane_calib.h
  line3d.cpp line3d.h
  vertex_line3d.cpp vertex_line3d.h
  edge_se3_line.cpp edge_se3_line.h
  edge_plane.cpp edge_plane.h
  edge_se3_calib.cpp edge_se3_calib.h
  types_slam3d_addons.cpp
  types_slam3d_addons.h
)


set_target_properties(types_slam3d_addons PROPERTIES OUTPUT_NAME ${LIB_PREFIX}types_slam3d_addons)
set_target_properties(types_slam3d_addons PROPERTIES
  VERSION ${G2O_LIB_VERSION}
  SOVERSION ${G2O_LIB_SOVERSION})
if (APPLE)
  set_target_properties(types_slam3d_addons PROPERTIES INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")
endif()
target_compile_features(types_slam3d_addons PUBLIC cxx_std_17)
target_link_libraries(types_slam3d_addons types_slam3d core)
if(G2O_HAVE_OPENGL)
  target_link_libraries(types_slam3d_addons opengl_helper)
endif()

target_include_directories(types_slam3d_addons PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/g2o/types/slam3d_addons>)

install(TARGETS types_slam3d_addons
  EXPORT ${G2O_TARGETS_EXPORT_NAME}
  RUNTIME DESTINATION ${RUNTIME_DESTINATION}
  LIBRARY DESTINATION ${LIBRARY_DESTINATION}
  ARCHIVE DESTINATION ${ARCHIVE_DESTINATION}
  INCLUDES DESTINATION ${INCLUDES_DESTINATION}
)

# Create alias target for easier usage when included as subdirectory
add_library(g2o::types_slam3d_addons ALIAS types_slam3d_addons)

file(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
install(FILES ${headers} DESTINATION ${INCLUDES_INSTALL_DIR}/types/slam3d_addons)
