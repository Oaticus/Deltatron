add_library("win")

target_link_libraries(win
  PRIVATE
    buildinfo
    fs
    cmd
    json)

target_include_directories(win
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/private"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources(win
  PRIVATE
    "include/public/dt/win.hh"

    "include/private/dt/win/config.hh"
    "src/win/config.cc"

    "include/public/dt/win/error.hh"
    "src/win/error.cc"

    $<$<PLATFORM_ID:Windows>:
      "include/private/dt/win/win32/window_class.hh"
      "src/win/win32/window_class.cc"

      "include/private/dt/win/win32/proc.hh"
      "src/win/win32/proc.cc"

      "include/private/dt/win_imp.win32.hh"
      "src/win.win32.cc"
    >)
