add_executable("deltatron")

target_link_libraries(deltatron
  PRIVATE
    "buildinfo"
    "command"
    "filesystem"
    "window"
    "render"
    "json")

target_include_directories(deltatron
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_sources(deltatron
  PRIVATE
    "include/dt/deltatron.hh"
    "src/deltatron.cc"

    "src/deltatron_main.cc")
