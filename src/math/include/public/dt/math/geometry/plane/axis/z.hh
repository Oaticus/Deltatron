#pragma once

#include <compare>     // operator<=>    , std::strong_ordering
#include <type_traits> // std::enable_if , std::is_trivial_v
#include <iosfwd>      // std::ostream&  , std::istream&

namespace dt {

template <typename T, typename = std::enable_if<std::is_trivial_v<T>>>
class basic_z_value final {
public:
  using value_type      = T;
  using pointer         = T*;
  using const_pointer   = T const*;
  using reference       = T&;
  using const_reference = T const&;

private:
  value_type _value;

public:
  constexpr basic_z_value() noexcept
  : _value{} {}

  constexpr basic_z_value(value_type const value) noexcept
  : _value(value) {}

  constexpr basic_z_value(basic_z_value const& type) noexcept
  : _value(type._value) {}

  constexpr basic_z_value(basic_z_value const&& type) noexcept
  : _value(type._value) {}

  constexpr ~basic_z_value() noexcept {}

  constexpr auto value() const noexcept -> value_type const& { return _value; }

  constexpr auto operator<=>(value_type    const& value) const noexcept -> std::strong_ordering { return _value <=> value;       }
  constexpr auto operator<=>(basic_z_value const& type ) const noexcept -> std::strong_ordering { return _value <=> type._value; }

  constexpr auto operator= (value_type const& value) noexcept -> basic_z_value& { _value =  value; return *this; }
  constexpr auto operator+=(value_type const& value) noexcept -> basic_z_value& { _value += value; return *this; }
  constexpr auto operator-=(value_type const& value) noexcept -> basic_z_value& { _value -= value; return *this; }
  constexpr auto operator*=(value_type const& value) noexcept -> basic_z_value& { _value *= value; return *this; }
  constexpr auto operator/=(value_type const& value) noexcept -> basic_z_value& { _value /= value; return *this; }

  constexpr auto operator= (basic_z_value const& type) noexcept -> basic_z_value& { _value =  type._value; return *this; }
  constexpr auto operator+=(basic_z_value const& type) noexcept -> basic_z_value& { _value += type._value; return *this; }
  constexpr auto operator-=(basic_z_value const& type) noexcept -> basic_z_value& { _value -= type._value; return *this; }
  constexpr auto operator*=(basic_z_value const& type) noexcept -> basic_z_value& { _value *= type._value; return *this; }
  constexpr auto operator/=(basic_z_value const& type) noexcept -> basic_z_value& { _value /= type._value; return *this; }

  constexpr auto operator++() noexcept -> basic_z_value& { ++_value; return *this; }
  constexpr auto operator--() noexcept -> basic_z_value& { --_value; return *this; }

  constexpr auto operator++(int) noexcept -> basic_z_value { auto const old = *this; operator++(); return old; }
  constexpr auto operator--(int) noexcept -> basic_z_value { auto const old = *this; operator--(); return old; }

  friend constexpr std::istream& operator>>(std::istream&, basic_z_value&) noexcept;
};

template <typename T>
constexpr auto operator+(basic_z_value<T> const& lhs, basic_z_value<T> const& rhs) noexcept -> basic_z_value<T>
{ return lhs.value() + rhs.value(); }

template <typename T>
constexpr auto operator-(basic_z_value<T> const& lhs, basic_z_value<T> const& rhs) noexcept -> basic_z_value<T>
{ return lhs.value() - rhs.value(); }

template <typename T>
constexpr auto operator*(basic_z_value<T> const& lhs, basic_z_value<T> const& rhs) noexcept -> basic_z_value<T>
{ return lhs.value() * rhs.value(); }

template <typename T>
constexpr auto operator/(basic_z_value<T> const& lhs, basic_z_value<T> const& rhs) noexcept -> basic_z_value<T>
{ return lhs.value() / rhs.value(); }

template<typename T>
constexpr auto operator+(basic_z_value<T> const& type, typename basic_z_value<T>::value_type const& value) noexcept -> basic_z_value<T>
{ return type.value() + value; }

template<typename T>
constexpr auto operator-(basic_z_value<T> const& type, typename basic_z_value<T>::value_type const& value) noexcept -> basic_z_value<T>
{ return type.value() - value; }

template<typename T>
constexpr auto operator*(basic_z_value<T> const& type, typename basic_z_value<T>::value_type const& value) noexcept -> basic_z_value<T>
{ return type.value() * value; }

template<typename T>
constexpr auto operator/(basic_z_value<T> const& type, typename basic_z_value<T>::value_type const& value) noexcept -> basic_z_value<T>
{ return type.value() / value; }

template <typename T>
constexpr auto operator<<(std::ostream& os, basic_z_value<T> const& type) noexcept -> std::ostream&
{ return os << type.value(); }

template <typename T>
constexpr auto operator>>(std::istream& is, basic_z_value<T>& type) noexcept -> std::istream& {
  auto new_value = T{};

  is >> new_value;
  type = new_value;

  return is;
}

using z_value = basic_z_value<float>;

}
