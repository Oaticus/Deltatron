#pragma once

#include <compare>
#include <type_traits>
#include <iosfwd>

namespace dt {

template <typename T, typename = std::enable_if<std::is_trivial_v<T>, T>>
class basic_y_value final {
public:
  using value_type      = T;
  using pointer         = T*;
  using const_pointer   = T const*;
  using reference       = T&;
  using const_reference = T const&;

private:
  value_type _x;

public:
  constexpr basic_y_value() noexcept
  : _x{} {}

  constexpr explicit basic_y_value(value_type const& v) noexcept
  : _x(v) {}

  constexpr explicit basic_y_value(value_type const&& v) noexcept
  : _x(v) {}

  constexpr basic_y_value(basic_y_value const& t) noexcept
  : _x(t._x) {}

  constexpr basic_y_value(basic_y_value const&& t) noexcept
  : _x(t._x) {}

  constexpr ~basic_y_value() noexcept {}

  constexpr auto value() const noexcept -> value_type const& { return _x; }

  constexpr auto operator<=>(value_type    const& v) const noexcept -> std::strong_ordering { return _x <=> v;    }
  constexpr auto operator<=>(basic_y_value const& t) const noexcept -> std::strong_ordering { return _x <=> t._x; }

  constexpr auto operator= (value_type const& v) noexcept -> basic_y_value& { _x =  v; return *this; }
  constexpr auto operator+=(value_type const& v) noexcept -> basic_y_value& { _x += v; return *this; }
  constexpr auto operator-=(value_type const& v) noexcept -> basic_y_value& { _x -= v; return *this; }
  constexpr auto operator*=(value_type const& v) noexcept -> basic_y_value& { _x *= v; return *this; }
  constexpr auto operator/=(value_type const& v) noexcept -> basic_y_value& { _x /= v; return *this; }

  constexpr auto operator= (basic_y_value const& t) noexcept -> basic_y_value& { _x =  t._x; return *this; }
  constexpr auto operator+=(basic_y_value const& t) noexcept -> basic_y_value& { _x += t._x; return *this; }
  constexpr auto operator-=(basic_y_value const& t) noexcept -> basic_y_value& { _x -= t._x; return *this; }
  constexpr auto operator*=(basic_y_value const& t) noexcept -> basic_y_value& { _x *= t._x; return *this; }
  constexpr auto operator/=(basic_y_value const& t) noexcept -> basic_y_value& { _x /= t._x; return *this; }

  constexpr auto operator++() noexcept -> basic_y_value& { ++_x; return *this; }
  constexpr auto operator--() noexcept -> basic_y_value& { --_x; return *this; }

  constexpr auto operator++(int) noexcept -> basic_y_value { auto const old = *this; operator++(); return old; }
  constexpr auto operator--(int) noexcept -> basic_y_value { auto const old = *this; operator--(); return old; }
};

template <typename T>
constexpr auto operator+(basic_y_value<T> const& lhs, basic_y_value<T> const& rhs) noexcept -> basic_y_value<T>
{ return lhs.value() + rhs.value(); }

template <typename T>
constexpr auto operator-(basic_y_value<T> const& lhs, basic_y_value<T> const& rhs) noexcept -> basic_y_value<T>
{ return lhs.value() - rhs.value(); }

template <typename T>
constexpr auto operator*(basic_y_value<T> const& lhs, basic_y_value<T> const& rhs) noexcept -> basic_y_value<T>
{ return lhs.value() * rhs.value(); }

template <typename T>
constexpr auto operator/(basic_y_value<T> const& lhs, basic_y_value<T> const& rhs) noexcept -> basic_y_value<T>
{ return lhs.value() / rhs.value(); }

template<typename T>
constexpr auto operator+(basic_y_value<T> const& t, typename basic_y_value<T>::value_type const& v) noexcept -> basic_y_value<T>
{ return t.value() + v; }

template<typename T>
constexpr auto operator-(basic_y_value<T> const& t, typename basic_y_value<T>::value_type const& v) noexcept -> basic_y_value<T>
{ return t.value() - v; }

template<typename T>
constexpr auto operator*(basic_y_value<T> const& t, typename basic_y_value<T>::value_type const& v) noexcept -> basic_y_value<T>
{ return t.value() * v; }

template<typename T>
constexpr auto operator/(basic_y_value<T> const& t, typename basic_y_value<T>::value_type const& v) noexcept -> basic_y_value<T>
{ return t.value() / v; }

template <typename T>
constexpr auto operator<<(std::ostream& os, basic_y_value<T> const& t) noexcept -> std::ostream&
{ return os << t.value(); }

using y_value = basic_y_value<float>;

}
