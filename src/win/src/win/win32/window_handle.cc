#include <dt/win/win32/window_handle.hh>

dt::win32_window_handle::win32_window_handle(wchar_t const* window_class_name, HINSTANCE const instance)
: _window_properties(),
  _window_title((wchar_t const*)"Deltatron"),
  _window_handle(_create_window_handle(instance, window_class_name)) {}

dt::win32_window_handle::~win32_window_handle() noexcept {}

HWND dt::win32_window_handle::_create_window_handle(HINSTANCE const instance, wchar_t const* window_class_name) const {
  auto window_handle = HWND{};

  window_handle = CreateWindowExW(
    _window_properties.extended_style(),
    window_class_name,
    _window_title.c_str(),
    _window_properties.style(),
    _window_properties.x_coordinate(),
    _window_properties.y_coordinate(),
    _window_properties.width(),
    _window_properties.height(),
    _window_properties.parent(),
    _window_properties.menu(),
    instance,
    _window_properties.app_data());

  if (window_handle == nullptr)
    throw win_error(std::string("win32: CreateWindowExW() failed with error code ") + std::to_string(GetLastError()));

  return window_handle;
}
