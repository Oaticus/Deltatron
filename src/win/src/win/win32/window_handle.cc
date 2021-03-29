#include <dt/win/win32/window_handle.hh>
#include <dt/win/error.hh>

#include <Windows.h>

dt::win32_window_handle::win32_window_handle(
  win_config   const& window_config,
  std::wstring const& window_class_name,
  HINSTANCE    const& program_instance)
: _window_name((wchar_t const*)"Deltatron"),
  _window_handle(_create_window_handle(window_config, window_class_name, program_instance)) {}

dt::win32_window_handle::~win32_window_handle() noexcept {}

HWND dt::win32_window_handle::_create_window_handle(
  win_config   const& window_config,
  std::wstring const& window_class_name,
  HINSTANCE    const& program_instance) const
{
  auto window_handle = HWND{};

  window_handle = CreateWindowExW(0, window_class_name.c_str(), _window_name.c_str(), WS_OVERLAPPEDWINDOW,
    CW_USEDEFAULT, CW_USEDEFAULT, window_config.window_width(), window_config.window_height(), nullptr, nullptr,
    program_instance, nullptr);

  if (window_handle == nullptr)
    throw win_error("CreateWindowExW() failed with error code " + std::to_string(GetLastError()));

  return window_handle;
}
