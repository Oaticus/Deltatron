add_library("json")

target_link_libraries(json
  PRIVATE
    "buildinfo")

target_include_directories(json
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public"
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/private")

target_sources(json
  PRIVATE
    "include/private/dt/json/stream/create_stream/lexer/state.hh"
    "src/json/stream/create_stream/lexer/state.cc"

    "include/private/dt/json/stream/create_stream/lexer.hh"
    "src/json/stream/create_stream/lexer.cc"

    "include/private/dt/json/stream/parse_stream/parser/state.hh"
    "src/json/stream/parse_stream/parser/state.cc"

    "include/private/dt/json/stream/parse_stream/parser.hh"
    "src/json/stream/parse_stream/parser.cc"

    "include/private/dt/json/to_string.hh"
    "src/json/to_string.cc"
    "src/json/fast_to_string.cc"

    "include/private/dt/json/stream.hh"
    "src/json/stream/create_stream.cc"
    "src/json/stream/parse_stream.cc"

    "include/private/dt/json/token.hh"
    "src/json/token.cc"

    "include/public/dt/json/container.hh"
    "src/json/container.cc"

    "include/private/dt/json/container_imp.hh"
    "src/json/container_imp.cc"

    "include/public/dt/json/error.hh"
    "src/json/error.cc"

    "include/private/dt/json_imp.hh"
    "include/public/dt/json.hh"
    "src/json.cc")
