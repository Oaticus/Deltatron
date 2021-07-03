add_library("yaml")

target_link_libraries(yaml
  PRIVATE
    "buildinfo"
  PUBLIC
    "utility")

target_include_directories(yaml
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/private"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources(yaml
  PRIVATE
    "include/public/dt/yaml.hh"

    "include/public/dt/yaml/type_definitions.hh"
    "include/public/dt/yaml/node.hh"
    "src/yaml/node/map.cc"
    "src/yaml/node/sequence.cc"
    "src/yaml/node.cc")
