configure_file("cmake_info.hh" "${CMAKE_CURRENT_BINARY_DIR}/include/dt/cmake_info.hh")

add_library("cmakeinfo" INTERFACE)

target_include_directories(cmakeinfo
  INTERFACE
    "${CMAKE_CURRENT_BINARY_DIR}/include")
