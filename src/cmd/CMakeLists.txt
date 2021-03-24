add_library("cmd")

target_link_libraries(cmd
  PRIVATE
    buildinfo
    cmakeinfo)

target_include_directories(cmd
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/private"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources(cmd
  PRIVATE
    "include/public/dt/cmd/termflag_passed.hh"
    "src/cmd/termflag_passed.cc"

    "include/private/dt/cmd/flagdb.hh"
    "include/private/dt/cmd/env.hh"
    "include/private/dt/cmd/args.hh"
    "include/private/dt/cmd_imp.hh"
    "include/public/dt/cmd/flag.hh"
    "include/public/dt/cmd.hh"
    "src/cmd.cc")
