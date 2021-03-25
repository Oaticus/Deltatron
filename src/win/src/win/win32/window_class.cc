#include <dt/win/win32/window_class.hh>

#include <string>

#include <Windows.h>

dt::win32_window_class::win32_window_class(HINSTANCE const instance) noexcept
: _name((wchar_t const*)"Deltatron Window Class"),
  _class(_create_class(instance))
{
  RegisterClassExW(&_class);
}

dt::win32_window_class::~win32_window_class() noexcept {}

wchar_t const* dt::win32_window_class::name() const noexcept { return _name.c_str(); }

WNDCLASSEXW dt::win32_window_class::_create_class(HINSTANCE const instance) const noexcept {
  WNDCLASSEXW window_class{};

  window_class.cbSize        = sizeof(window_class);
  window_class.lpfnWndProc   = _dt_win32_callback;
  window_class.hInstance     = instance;
  window_class.lpszClassName = _name.c_str();

  return window_class;
}
