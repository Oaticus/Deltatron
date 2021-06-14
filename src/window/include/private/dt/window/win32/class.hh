#pragma once

#include <Windows.h>

#include <string>

namespace dt {

class win32_window_class final {
  std::wstring const _window_class_name;
  WNDCLASSEXW  const _window_class;

public:
  win32_window_class(HINSTANCE const& program_instance);

  ~win32_window_class() noexcept;

  constexpr WNDCLASSEXW const& window_class() const noexcept { return _window_class; }

  constexpr std::wstring const& window_class_name() const noexcept { return _window_class_name; }

private:
  WNDCLASSEXW _create_window_class(HINSTANCE const& program_instance) const noexcept;
};

}
