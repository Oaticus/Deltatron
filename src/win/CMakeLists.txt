add_library("win")

target_link_libraries(win
  PRIVATE
    buildinfo
    cmd
    fs
    json)

target_include_directories(win
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/include/private"
  PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include/public")

target_sources(win
  PRIVATE
    "include/public/dt/win/error.hh"
    "src/win/error.cc"

    $<$<PLATFORM_ID:Windows>:
      "src/win/win32/callback.cc"
      "include/private/dt/win/win32/callback.hh"

      "include/private/dt/win/win32/window_handle/properties.hh"
      "include/private/dt/win/win32/window_handle/position.hh"
      "include/private/dt/win/win32/window_handle.hh"
      "src/win/win32/window_handle.cc"

      "include/private/dt/win/win32/window_class.hh"
      "src/win/win32/window_class.cc"

      "include/private/dt/win_imp.win32.hh"
      "src/win_imp.win32.cc"
    >

    "include/public/dt/win.hh"
    "src/win.cc")
