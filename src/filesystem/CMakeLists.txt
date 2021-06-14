add_library("filesystem")

target_link_libraries(filesystem
  PRIVATE
    "buildinfo"
    "command")

target_include_directories(filesystem
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/private"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources(filesystem
  PRIVATE
    "include/private/dt/filesystem_imp.hh"
    "src/filesystem_imp.cc"

    "include/public/dt/filesystem/error.hh"
    "src/filesystem/error.cc"

    "include/public/dt/filesystem/directory/file.hh"
    "src/filesystem/directory/file.cc"

    "include/public/dt/filesystem/directory.hh"
    "src/filesystem/directory.cc"

    "include/public/dt/filesystem.hh"
    "src/filesystem.cc")
