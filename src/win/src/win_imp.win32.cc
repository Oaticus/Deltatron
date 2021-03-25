#include <dt/win_imp.win32.hh>

#include <dt/win/error.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>

dt::win_imp::win_imp(cmd const&, fs const&)
: _instance(_get_instance_handle()),
  _window_class(_instance),
  _window_handle(_window_class.name(), _instance) {}

dt::win_imp::~win_imp() noexcept {}

void dt::win_imp::show() const noexcept {
  static bool first_activation(true);
  ShowWindow(_window_handle.handle(), first_activation ? first_activation = false, SW_SHOWNORMAL : SW_SHOW);
}

void dt::win_imp::hide() const noexcept { ShowWindow(_window_handle.handle(), SW_HIDE); }

void dt::win_imp::loop() const noexcept {
  for (MSG message{}; GetMessage(&message, nullptr, 0, 0); DispatchMessage(&message))
    TranslateMessage(&message);
}

HINSTANCE dt::win_imp::_get_instance_handle() const {
  auto instance = HINSTANCE{};

  if (auto const result = GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_PIN, nullptr, &instance); result == FALSE)
    throw dt::win_error("win32: GetModuleHandle() failed with error code " + std::to_string(GetLastError()));

  return instance;
}
