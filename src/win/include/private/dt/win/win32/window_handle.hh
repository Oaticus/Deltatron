#pragma once

#include <dt/win/win32/window_handle/position.hh>
#include <dt/win/win32/window_handle/properties.hh>

#include <dt/win/error.hh>

#include <string>

#include <Windows.h>

namespace dt {

class win32_window_handle final {
  win32_window_handle_position   const _window_position;
  win32_window_handle_properties const _window_properties;
  std::wstring                   const _window_title;
  HWND                           const _window_handle;

public:
  win32_window_handle(wchar_t const* window_class_name, HINSTANCE const instance);

  ~win32_window_handle() noexcept;

  constexpr HWND const& handle() const noexcept { return _window_handle; }

private:
  HWND _create_window_handle(HINSTANCE const instance, wchar_t const* window_class_name) const;

};

}
