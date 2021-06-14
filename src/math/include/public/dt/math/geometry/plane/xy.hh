#pragma once

#include <dt/math/geometry/plane/axis/x.hh>
#include <dt/math/geometry/plane/axis/y.hh>

#include <numeric>
#include <type_traits>

namespace dt {

template <typename T>
class xy_plane final {
public:
  using value_type = T;
  using x_type     = x_axis<value_type>;
  using y_type     = y_axis<value_type>;

  struct initializer final {
    x_type x;
    y_type y;
  };

private:
  x_type _x;
  y_type _y;

public:
  constexpr xy_plane() noexcept
  : _x{},
    _y{} {}

  constexpr xy_plane(initializer const init) noexcept
  : _x(init.x),
    _y(init.y) {}

  constexpr xy_plane(xy_plane const& xy) noexcept
  : _x(xy._x),
    _y(xy._y) {}

  constexpr ~xy_plane() noexcept {}

  constexpr auto x_component() const noexcept -> x_type const& { return _x; }
  constexpr auto y_component() const noexcept -> y_type const& { return _y; }

  constexpr auto operator==(xy_plane const& xy) const noexcept -> bool { return _x == xy._x && _y == xy._y; }
  constexpr auto operator!=(xy_plane const& xy) const noexcept -> bool { return !operator==(xy);            }

  constexpr auto operator< (xy_plane const& xy) const noexcept -> bool { return _x < xy._x && _y < xy._y;          }
  constexpr auto operator> (xy_plane const& xy) const noexcept -> bool { return !operator<(xy) && !operator==(xy); }
  constexpr auto operator<=(xy_plane const& xy) const noexcept -> bool { return operator<(xy) || operator==(xy);   }
  constexpr auto operator>=(xy_plane const& xy) const noexcept -> bool { return operator>(xy) || operator==(xy);   }

  constexpr auto x_component(x_type const& x) noexcept -> xy_plane& { _x = x; return *this; }
  constexpr auto y_component(y_type const& y) noexcept -> xy_plane& { _y = y; return *this; }

  constexpr auto operator=(xy_plane const& xy) noexcept -> xy_plane&
  { if (*this != xy) { _x = xy._x; _y = xy._y; } return *this; }

  constexpr auto midpoint() const noexcept -> value_type { return std::midpoint(_x.value(), _y.value()); }
};

}
