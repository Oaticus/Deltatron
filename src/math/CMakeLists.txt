add_library("math" INTERFACE)

target_include_directories(math
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources(math
  INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public/dt/math/geometry/plane/axis/x.hh"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public/dt/math/geometry/plane/axis/y.hh"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public/dt/math/geometry/plane/axis/z.hh")
