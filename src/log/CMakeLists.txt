add_library("log")

target_link_libraries(log
  PRIVATE
    buildinfo
    cmd
    fs)

target_include_directories(log
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources(log
  PRIVATE
    "include/public/dt/log/level.hh"
    "include/public/dt/log.hh"
    "src/log.cc")
