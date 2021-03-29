#include <dt/win/win32/window_class.hh>
#include <dt/win/win32/proc.hh>

dt::win32_window_class::win32_window_class(HINSTANCE const& program_instance)
: _window_class_name((wchar_t const*)"Win32 Deltatron Window Class"),
  _window_class(_create_window_class(program_instance))
{
  RegisterClassExW(&_window_class);
}

dt::win32_window_class::~win32_window_class() noexcept {}

WNDCLASSEXW dt::win32_window_class::_create_window_class(HINSTANCE const& program_instance) const noexcept {
  auto window_class = WNDCLASSEXW{};

  window_class.cbSize        = sizeof(window_class);
  window_class.lpfnWndProc   = _dt_win32_window_proc;
  window_class.hInstance     = program_instance;
  window_class.lpszClassName = _window_class_name.c_str();

  return window_class;
}
