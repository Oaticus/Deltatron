add_library("window")

target_link_libraries(window
  PRIVATE
    "buildinfo"
    "filesystem"
    "command"
    "json")

target_include_directories(window
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/private"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources(window
  PRIVATE
    "include/public/dt/window.hh"

    "include/private/dt/window/config.hh"
    "src/window/config.cc"

    "include/public/dt/window/error.hh"
    "src/window/error.cc"

    $<$<PLATFORM_ID:Windows>:
      "include/private/dt/window/win32/sys.hh"
      "src/window/win32/sys.cc"

      "include/private/dt/window/win32/class.hh"
      "src/window/win32/class.cc"

      "include/private/dt/window/win32/proc.hh"
      "src/window/win32/proc.cc"

      "include/private/dt/window_imp.win32.hh"
      "src/window.win32.cc"
    >)
