add_library("utility" INTERFACE)

target_link_libraries(utility
  INTERFACE
    "buildinfo")

target_include_directories(utility
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/interface")

target_sources(utility
  INTERFACE
  "${CMAKE_CURRENT_SOURCE_DIR}/include/interface/dt/utility/optional_reference.hh")
