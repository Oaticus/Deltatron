add_library("render")

target_link_libraries(render
  PRIVATE
    buildinfo
    cmd
    fs
    gpu)

target_include_directories(render
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public"
  PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/include/private")


target_sources(render
  PRIVATE
  "include/private/dt/render_imp.hh"
  "include/public/dt/render.hh"
  "src/render.cc")
