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
    "src/json/lexical_analysis/raw_printout.cc"

    "src/json/semantic_analysis/parse_stream.cc"

    "include/public/dt/json/error.hh"
    "src/json/error.cc"

    "include/public/dt/json/container.hh"
    "src/json/container.cc"

    "include/private/dt/json/semantic_analysis/container_imp.hh"
    "src/json/semantic_analysis/container_imp.cc"

    "include/private/dt/json/semantic_analysis.hh"
    "include/private/dt/json/lexical_analysis/token.hh"
    "include/private/dt/json/lexical_analysis.hh"
    "include/private/dt/json_imp.hh"
    "include/public/dt/json.hh"
    "src/json.cc")
