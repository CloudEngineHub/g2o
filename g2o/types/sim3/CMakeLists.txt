add_library(types_sim3 ${G2O_LIB_TYPE}
  types_seven_dof_expmap.cpp
  types_seven_dof_expmap.h
)

set_target_properties(types_sim3 PROPERTIES OUTPUT_NAME ${LIB_PREFIX}types_sim3)
set_target_properties(types_sim3 PROPERTIES
  VERSION ${G2O_LIB_VERSION}
  SOVERSION ${G2O_LIB_SOVERSION})
if (APPLE)
  set_target_properties(types_sim3 PROPERTIES INSTALL_NAME_DIR "${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}")
endif()
target_compile_features(types_sim3 PUBLIC cxx_std_17)
target_link_libraries(types_sim3 PUBLIC types_sba)

target_include_directories(types_sim3 PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>
  $<INSTALL_INTERFACE:include/g2o/types/sim3>)

install(TARGETS types_sim3
  EXPORT ${G2O_TARGETS_EXPORT_NAME}
  RUNTIME DESTINATION ${RUNTIME_DESTINATION}
  LIBRARY DESTINATION ${LIBRARY_DESTINATION}
  ARCHIVE DESTINATION ${ARCHIVE_DESTINATION}
  INCLUDES DESTINATION ${INCLUDES_DESTINATION}
)

# Create alias target for easier usage when included as subdirectory
add_library(g2o::types_sim3 ALIAS types_sim3)

file(GLOB headers "${CMAKE_CURRENT_SOURCE_DIR}/*.h" "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")

install(FILES ${headers} DESTINATION ${INCLUDES_INSTALL_DIR}/types/sim3)
