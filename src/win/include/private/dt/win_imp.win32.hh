#pragma once

#include <dt/win/win32/window_class.hh>

#include <dt/win/config.hh>
#include <dt/win/error.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>

#include <Windows.h>

namespace dt {

class win_imp final {
  win_config               _window_config;
  HINSTANCE          const _program_instance;
  win32_window_class const _window_class;
  std::wstring       const _window_name;
  HWND                     _window_handle;

public:
  win_imp(cmd const& c, fs const& f)
  : _window_config(c, f),
    _program_instance(_get_program_instance()),
    _window_class(_program_instance),
    _window_name((wchar_t const*)"Deltatron"),
    _window_handle(nullptr)
  {
    if (!c.arg_passed(flag::display_console))
      ShowWindow(GetConsoleWindow(), SW_HIDE);
  }

  ~win_imp() noexcept {}

  void run() {
    RegisterClassExW(&_window_class.window_class());

    _window_handle = _create_window();

    ShowWindow(_window_handle, SW_SHOWNORMAL);

    for (MSG message{}; GetMessage(&message, nullptr, 0, 0); DispatchMessage(&message))
      TranslateMessage(&message);
  }

private:
  HWND _create_window() const {
    auto window_handle = HWND{};

    window_handle = CreateWindowExW(0, _window_class.window_class_name().c_str(), _window_name.c_str(), WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, _window_config.window_width(), _window_config.window_height(), nullptr, nullptr,
    _program_instance, nullptr);

    if (window_handle == nullptr)
      throw win_error("CreateWindowExW() failed with error code " + std::to_string(GetLastError()));

    return window_handle;
  }

  HINSTANCE _get_program_instance() const {
    auto program_instance = HINSTANCE{};

    if (BOOL result = GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_PIN, nullptr, &program_instance); result == FALSE)
      throw win_error("GetModuleHandleExW() failed with error code " + std::to_string(GetLastError()));

    return program_instance;
  }
};

}
