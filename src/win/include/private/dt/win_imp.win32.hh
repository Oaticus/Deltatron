#pragma once

#include <dt/win/win32/program_instance.hh>
#include <dt/win/win32/window_class.hh>
#include <dt/win/win32/window_handle.hh>

#include <dt/win/config.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>

#include <Windows.h>

namespace dt {

class win_imp final {
  win_config                   _config;
  win32_program_instance const _program_instance;
  win32_window_class     const _window_class;

public:
  win_imp(cmd const& c, fs const& f)
  : _config(c, f),
    _program_instance(),
    _window_class(_program_instance.program_instance())
  {
    if (!c.arg_passed(flag::display_console))
      ShowWindow(GetConsoleWindow(), SW_HIDE);
  }

  ~win_imp() noexcept {}

  void run() const noexcept {
    RegisterClassExW(&_window_class.window_class());

    auto const window_handle = win32_window_handle(_config, _window_class.window_class_name(), _program_instance.program_instance());

    ShowWindow(window_handle.window_handle(), SW_SHOWNORMAL);

    for (MSG message{}; GetMessage(&message, nullptr, 0, 0); DispatchMessage(&message))
      TranslateMessage(&message);

    ShowWindow(window_handle.window_handle(), SW_HIDE);
  }
};

}
