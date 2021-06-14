add_library("command")

target_link_libraries(command
  PRIVATE
    "buildinfo"
    "cmakeinfo")

target_include_directories(command
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/private"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources(command
  PRIVATE
    "include/public/dt/command/termflag_passed.hh"
    "src/command/termflag_passed.cc"

    "include/private/dt/command/flagdb.hh"
    "include/private/dt/command/env.hh"
    "include/private/dt/command/args.hh"
    "include/private/dt/command_imp.hh"
    "include/public/dt/command/flag.hh"
    "include/public/dt/command.hh"
    "src/command.cc")
