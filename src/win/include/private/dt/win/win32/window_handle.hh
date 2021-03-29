#pragma once

#include <dt/win/win32/window_class.hh>
#include <dt/win/config.hh>

#include <string>

#include <Windows.h>

namespace dt {

class win32_window_handle final {
  std::wstring const _window_name;
  HWND         const _window_handle;

public:
  win32_window_handle(win_config const& window_config, std::wstring const& window_class_name, HINSTANCE const& program_instance);

  ~win32_window_handle() noexcept;

  constexpr HWND const& window_handle() const noexcept { return _window_handle; }

  constexpr std::wstring const& window_name() const noexcept { return _window_name; }

private:
  HWND _create_window_handle(win_config const&, std::wstring const&, HINSTANCE const&) const;
};

}
