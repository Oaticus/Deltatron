add_library("json")

target_link_libraries(json
  PRIVATE
    buildinfo)

target_include_directories(json
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public"
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/private")

target_sources(json
  PRIVATE
    "include/private/dt/json/stream.hh"
    "src/json/stream/parse_stream.cc"
    "src/json/stream/create_stream.cc"
    "src/json/stream/to_string.cc"
    "src/json/stream/json_stream.cc"

    "include/public/dt/json/error.hh"
    "src/json/error.cc"

    "include/public/dt/json/container.hh"
    "src/json/container/container.cc"

    "include/private/dt/json/container_imp.hh"
    "src/json/container/container_imp.cc"

    "include/private/dt/json/comment.hh"
    "src/json/comment.cc"

    "include/private/dt/json/token.hh"
    "src/json/token.cc"

    "include/private/dt/json_imp.hh"
    "include/public/dt/json.hh"
    "src/json.cc")
