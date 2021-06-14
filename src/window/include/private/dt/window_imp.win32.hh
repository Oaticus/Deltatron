#pragma once

#include <dt/window/win32/class.hh>
#include <dt/window/win32/sys.hh>   // win32_last_err_id

#include <dt/window/config.hh>
#include <dt/window/error.hh>

#include <dt/command.hh>
#include <dt/filesystem.hh>

#include <string> // std::string_literals

#include <Windows.h>

namespace dt {

class window_imp final {
  window_config      const _window_config;
  HINSTANCE          const _program_instance;
  win32_window_class const _window_class;
  std::wstring       const _window_name;
  HWND                     _window_handle;

public:
  window_imp(command const& cmd, filesystem const& fs)
  : _window_config(cmd, fs),
    _program_instance(_get_program_instance()),
    _window_class(_program_instance),
    _window_name(reinterpret_cast<wchar_t const*>("Deltatron")),
    _window_handle(nullptr)
  {
    if (!cmd.arg_passed(flag::display_console))
      ShowWindow(GetConsoleWindow(), SW_HIDE);
  }

  constexpr HWND const& window_handle() const noexcept { return _window_handle; }

  void run() {
    RegisterClassExW(&_window_class.window_class());

    _window_handle = _create_window();

    ShowWindow(_window_handle, SW_SHOWNORMAL);

    for (MSG message{}; GetMessage(&message, nullptr, 0, 0); DispatchMessage(&message))
      TranslateMessage(&message);
  }

private:
  HWND _create_window() const {
    using namespace ::std::string_literals;

    auto window_handle = CreateWindowExW(0, _window_class.window_class_name().c_str(), _window_name.c_str(),
      WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, _window_config.window_width(), _window_config.window_height(),
      nullptr, nullptr, _program_instance, nullptr);

    if (window_handle == nullptr)
      throw window_error("CreateWindowExW() failed with error code "s + win32_last_err_id());

    return window_handle;
  }

  HINSTANCE _get_program_instance() const {
    using namespace ::std::string_literals;

    auto program_instance = HINSTANCE{};

    if (BOOL const result = GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_PIN, nullptr, &program_instance); result == FALSE)
      throw window_error("GetModuleHandleExW() failed with error code "s + win32_last_err_id());

    return program_instance;
  }
};

}
