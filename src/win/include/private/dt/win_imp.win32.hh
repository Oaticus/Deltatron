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
  win32_window_handle    const _window_handle;

public:
  win_imp(cmd const& c, fs const& f)
  : _config(c, f),
    _program_instance(),
    _window_class(_program_instance.program_instance()),
    _window_handle(_config, _window_class.window_class_name(), _program_instance.program_instance())
  {
    ShowWindow(_window_handle.window_handle(), SW_SHOWNORMAL);
  }

  ~win_imp() noexcept { ShowWindow(_window_handle.window_handle(), SW_HIDE); }

  void begin_processing() const noexcept {
    for (MSG message{}; GetMessage(&message, nullptr, 0, 0); DispatchMessage(&message))
      TranslateMessage(&message);
  }
};

}
