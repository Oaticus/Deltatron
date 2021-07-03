add_library("math" INTERFACE)

target_include_directories(math
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources(math
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public/dt/math/point.hh")
