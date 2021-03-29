#pragma once

#include <Windows.h>

namespace dt {

class win32_program_instance final {
  HINSTANCE const _program_instance;

public:
  win32_program_instance();

  ~win32_program_instance() noexcept;

  constexpr HINSTANCE const& program_instance() const noexcept { return _program_instance; }

private:
  HINSTANCE _get_program_instance() const;
};

}
