#pragma once

#include <Windows.h>

namespace dt {

class win32_window_handle_properties final {
  DWORD  const _styles;
  DWORD  const _extended_styles;
  HWND   const _parent;
  HMENU  const _menu;
  LPVOID const _app_data;

public:
  constexpr win32_window_handle_properties() noexcept
  : _styles(WS_OVERLAPPEDWINDOW),
    _extended_styles(0),
    _parent(nullptr),
    _menu(nullptr),
    _app_data(nullptr) {}

  constexpr auto const& style()          const noexcept { return _styles;          }
  constexpr auto const& extended_style() const noexcept { return _extended_styles; }
  constexpr auto const& parent()         const noexcept { return _parent;          }
  constexpr auto const& menu()           const noexcept { return _menu;            }
  constexpr auto const& app_data()       const noexcept { return _app_data;        }
};

}
