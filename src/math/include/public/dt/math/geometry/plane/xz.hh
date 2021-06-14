#pragma once

#include <numeric>
#include <type_traits>

namespace dt {

template <typename T, typename = std::enable_if<std::is_trivial_v<T>, T>>
class xz_t final {
public:
  using value_type = T;

  struct initializer final {
    value_type x;
    value_type z;
  };

private:
  value_type _x;
  value_type _z;

public:
  constexpr xz_t() noexcept
  : _x{},
    _z{} {}

  constexpr xz_t(initializer const init) noexcept
  : _x(init.x),
    _z(init.z) {}

  constexpr xz_t(xz_t const t) noexcept
  : _x(t._x),
    _z(t._z) {}

  constexpr ~xz_t() noexcept {}

  constexpr auto x() const noexcept -> value_type const& { return _x; }
  constexpr auto z() const noexcept -> value_type const& { return _z; }

  constexpr auto operator==(xz_t const& t) const noexcept -> bool { return _x == t._x && _z == t._z; }
  constexpr auto operator!=(xz_t const& t) const noexcept -> bool { return !operator==(t);           }

  constexpr auto operator< (xz_t const& t) const noexcept -> bool { return _x < t._x  && _z < t._z;         }
  constexpr auto operator> (xz_t const& t) const noexcept -> bool { return !operator<(t) && !operator==(t); }
  constexpr auto operator<=(xz_t const& t) const noexcept -> bool { return operator<(t) || operator==(t);   }
  constexpr auto operator>=(xz_t const& t) const noexcept -> bool { return operator>(t) || operator==(t);   }

  constexpr auto x(value_type const& x) noexcept -> xz_t& { _x = x; return *this; }
  constexpr auto z(value_type const& z) noexcept -> xz_t& { _z = z; return *this; }

  constexpr auto operator=(xz_t const& t) noexcept -> xz_t&
  { if (*this != t) { _x = t._x; _z = t._z; } return *this; }

  constexpr auto midpoint() const noexcept -> value_type { return std::midpoint(_x, _z); }
};

}
