#include <dt/win/win32/window_class.hh>

#include <string>

#include <Windows.h>

dt::win32_window_class::win32_window_class(HINSTANCE const instance) noexcept
: _window_class_name((wchar_t const*)"Deltatron Window Class"),
  _window_class(_create_window_class(instance))
{
  RegisterClassExW(&_window_class);
}

dt::win32_window_class::~win32_window_class() noexcept {}

wchar_t const* dt::win32_window_class::name() const noexcept { return _window_class_name.c_str(); }

WNDCLASSEXW dt::win32_window_class::_create_window_class(HINSTANCE const instance) const noexcept {
  WNDCLASSEXW window_window_class{};

  window_window_class.cbSize        = sizeof(window_window_class);
  window_window_class.lpfnWndProc   = _dt_win32_callback;
  window_window_class.hInstance     = instance;
  window_window_class.lpszClassName = _window_class_name.c_str();

  return window_window_class;
}
