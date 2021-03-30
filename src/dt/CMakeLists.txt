add_executable("deltatron")

target_link_libraries(deltatron
  PRIVATE
    buildinfo
    cmd
    fs
    render
    win)

target_include_directories(deltatron
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_sources(deltatron
  PRIVATE
    "include/dt/deltatron.hh"
    "src/deltatron.cc"

    "src/deltatron_main.cc")
