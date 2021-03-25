#pragma once

#include <Windows.h>

namespace dt {

class win32_window_handle_position final {
  int const _x_coordinate;
  int const _y_coordinate;
  int const _width;
  int const _height;

public:
  constexpr win32_window_handle_position() noexcept
  : _x_coordinate(CW_USEDEFAULT),
    _y_coordinate(CW_USEDEFAULT),
    _width(CW_USEDEFAULT),
    _height(CW_USEDEFAULT) {}

  constexpr int const& x_coordinate() const noexcept { return _x_coordinate; }
  constexpr int const& y_coordinate() const noexcept { return _y_coordinate; }
  constexpr int const& width()        const noexcept { return _width;        }
  constexpr int const& height()       const noexcept { return _height;       }
};

}
