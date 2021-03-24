add_library("fs")

target_link_libraries(fs
  PRIVATE
    buildinfo
  PUBLIC
    cmd)

target_include_directories(fs
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/private"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources(fs
  PRIVATE
    "include/private/dt/fs_imp.hh"
    "src/fs_imp.cc"

    "include/public/dt/fs/error.hh"
    "src/fs/error.cc"

    "include/public/dt/fs/directory/file.hh"
    "src/fs/directory/file.cc"

    "include/public/dt/fs/directory.hh"
    "src/fs/directory.cc"

    "include/public/dt/fs.hh"
    "src/fs.cc")
