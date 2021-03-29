#include <dt/win/win32/program_instance.hh>
#include <dt/win/error.hh>

#include <Windows.h>

dt::win32_program_instance::win32_program_instance()
: _program_instance() {}

dt::win32_program_instance::~win32_program_instance() noexcept {}

HINSTANCE dt::win32_program_instance::_get_program_instance() const {
  auto program_instance = HINSTANCE{};

  if (BOOL const result = GetModuleHandleExW(GET_MODULE_HANDLE_EX_FLAG_PIN, nullptr, &program_instance); result == FALSE)
    throw win_error("GetModuleHandleExW() failed with error code " + std::to_string(GetLastError()));

  return program_instance;
}
