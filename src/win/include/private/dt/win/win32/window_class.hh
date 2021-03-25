#pragma once

#include <dt/win/win32/callback.hh>

#include <string>

#include <Windows.h>

namespace dt {

class win32_window_class final {
  std::wstring const _name;
  WNDCLASSEXW  const _class;

public:
  win32_window_class(HINSTANCE const instance) noexcept;

  ~win32_window_class() noexcept;

  wchar_t const* name() const noexcept;

private:
  WNDCLASSEXW _create_class(HINSTANCE const instance) const noexcept;
};

}
