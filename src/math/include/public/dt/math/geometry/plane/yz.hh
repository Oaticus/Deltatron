#pragma once

#include <numeric>
#include <type_traits>

namespace dt {

template <typename T, typename = std::enable_if<std::is_trivial_v<T>, T>>
class yz_t final {
public:
  using value_type = T;

  struct initializer final {
    value_type y;
    value_type z;
  };

private:
  value_type _y;
  value_type _z;

public:
  constexpr yz_t() noexcept
  : _y{},
    _z{} {}

  constexpr yz_t(initializer const init) noexcept
  : _y(init.y),
    _z(init.z) {}

  constexpr yz_t(yz_t const t) noexcept
  : _y(t._y),
    _z(t._z) {}

  constexpr ~yz_t() noexcept {}

  constexpr auto y() const noexcept -> value_type const& { return _y; }
  constexpr auto z() const noexcept -> value_type const& { return _z; }

  constexpr auto operator==(yz_t const& t) const noexcept -> bool { return _y == t._y && _z == t._z;      }
  constexpr auto operator!=(yz_t const& t) const noexcept -> bool { return !operator==(t);                }

  constexpr auto operator< (yz_t const& t) const noexcept -> bool { return _y < t._y && _z < t._z;          }
  constexpr auto operator> (yz_t const& t) const noexcept -> bool { return !operator<(t) && !operator==(t); }
  constexpr auto operator<=(yz_t const& t) const noexcept -> bool { return operator<(t) || operator==(t);   }
  constexpr auto operator>=(yz_t const& t) const noexcept -> bool { return operator>(t) || operator==(t);   }

  constexpr auto y(value_type const& y) noexcept -> yz_t& { _y = y; return *this; }
  constexpr auto z(value_type const& z) noexcept -> yz_t& { _z = z; return *this; }

  constexpr auto operator=(yz_t const& t) noexcept -> yz_t&
  { if (*this != t) { _y = t._y; _z = t._z; } return *this; }

  constexpr auto midpoint() const noexcept -> value_type { return std::midpoint(_y, _z); }
};

}
