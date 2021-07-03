#pragma once

#include <compare>
#include <type_traits>
#include <iosfwd>

namespace dt {

template <typename T>
requires std::is_arithmetic_v<T>
class basic_x_type final {
public:
  using value_type = T;

private:
  value_type _x;

public:
  constexpr basic_x_type() noexcept : _x{} {}

  constexpr basic_x_type(value_type const v) noexcept : _x(v) {}

  constexpr basic_x_type(basic_x_type const& x) noexcept : _x(x._x) {}

  constexpr basic_x_type(basic_x_type && x) noexcept : _x(x._x) {}

  constexpr ~basic_x_type() noexcept {}

  constexpr auto value() const noexcept -> value_type const& { return _x; }

  constexpr auto operator<=>(value_type   const& v) const noexcept -> std::strong_ordering { return _x <=> v;    }
  constexpr auto operator<=>(basic_x_type const& x) const noexcept -> std::strong_ordering { return _x <=> x._x; }

  constexpr auto operator+=(value_type const& v) noexcept -> basic_x_type& { _x += v; return *this; }
  constexpr auto operator-=(value_type const& v) noexcept -> basic_x_type& { _x -= v; return *this; }
  constexpr auto operator*=(value_type const& v) noexcept -> basic_x_type& { _x *= v; return *this; }
  constexpr auto operator/=(value_type const& v) noexcept -> basic_x_type& { _x /= v; return *this; }

  constexpr auto operator=(value_type const& v) noexcept -> basic_x_type& { _x  = v; return *this; }

  constexpr auto operator=(basic_x_type const& x) noexcept -> basic_x_type&
  { if (this != &x) _x = x._x; return *this; }

  constexpr auto operator+=(basic_x_type const& x) noexcept -> basic_x_type& { _x += x._x; return *this; }
  constexpr auto operator-=(basic_x_type const& x) noexcept -> basic_x_type& { _x -= x._x; return *this; }
  constexpr auto operator*=(basic_x_type const& x) noexcept -> basic_x_type& { _x *= x._x; return *this; }
  constexpr auto operator/=(basic_x_type const& x) noexcept -> basic_x_type& { _x /= x._x; return *this; }

  constexpr auto operator++() noexcept -> basic_x_type& { ++_x; return *this; }
  constexpr auto operator--() noexcept -> basic_x_type& { --_x; return *this; }

  constexpr auto operator++(int) noexcept -> basic_x_type { auto const old = *this; operator++(); return old; }
  constexpr auto operator--(int) noexcept -> basic_x_type { auto const old = *this; operator--(); return old; }

  friend constexpr auto operator>>(std::istream&, basic_x_type<T>&) noexcept -> std::istream&;
};

template <typename T>
constexpr auto operator+(basic_x_type<T> const& xlhs, basic_x_type<T> const& xrhs) noexcept -> basic_x_type<T>
{ return xlhs.value() + xrhs.value(); }

template <typename T>
constexpr auto operator-(basic_x_type<T> const& xlhs, basic_x_type<T> const& xrhs) noexcept -> basic_x_type<T>
{ return xlhs.value() - xrhs.value(); }

template <typename T>
constexpr auto operator*(basic_x_type<T> const& xlhs, basic_x_type<T> const& xrhs) noexcept -> basic_x_type<T>
{ return xlhs.value() * xrhs.value(); }

template <typename T>
constexpr auto operator/(basic_x_type<T> const& xlhs, basic_x_type<T> const& xrhs) noexcept -> basic_x_type<T>
{ return xlhs.value() / xrhs.value(); }

template<typename T>
constexpr auto operator+(basic_x_type<T> const& xlhs, typename basic_x_type<T>::value_type const& vrhs) noexcept -> basic_x_type<T>
{ return xlhs.value() + vrhs; }

template<typename T>
constexpr auto operator-(basic_x_type<T> const& xlhs, typename basic_x_type<T>::value_type const& vrhs) noexcept -> basic_x_type<T>
{ return xlhs.value() - vrhs; }

template<typename T>
constexpr auto operator*(basic_x_type<T> const& xlhs, typename basic_x_type<T>::value_type const& vrhs) noexcept -> basic_x_type<T>
{ return xlhs.value() * vrhs; }

template<typename T>
constexpr auto operator/(basic_x_type<T> const& xlhs, typename basic_x_type<T>::value_type const& vrhs) noexcept -> basic_x_type<T>
{ return xlhs.value() / vrhs; }

template <typename T>
constexpr auto operator>>(std::istream& is, basic_x_type<T>& x) noexcept -> std::istream&
{ return is >> x._x; }

template <typename T>
requires std::is_arithmetic_v<T>
class basic_y_type final {
public:
  using value_type = T;

private:
  value_type _y;

public:
  constexpr basic_y_type() noexcept : _y{} {}

  constexpr basic_y_type(value_type const v) noexcept : _y(v) {}

  constexpr basic_y_type(basic_y_type const& y) noexcept : _y(y._y) {}

  constexpr basic_y_type(basic_y_type const&& y) noexcept : _y(y._y) {}

  constexpr ~basic_y_type() noexcept {}

  constexpr auto value() const noexcept -> value_type const& { return _y; }

  constexpr auto operator<=>(value_type   const& v) const noexcept -> std::strong_ordering { return _y <=> v;    }
  constexpr auto operator<=>(basic_y_type const& y) const noexcept -> std::strong_ordering { return _y <=> y._y; }

  constexpr auto operator+=(value_type const& v) noexcept -> basic_y_type& { _y += v; return *this; }
  constexpr auto operator-=(value_type const& v) noexcept -> basic_y_type& { _y -= v; return *this; }
  constexpr auto operator*=(value_type const& v) noexcept -> basic_y_type& { _y *= v; return *this; }
  constexpr auto operator/=(value_type const& v) noexcept -> basic_y_type& { _y /= v; return *this; }

  constexpr auto operator=(value_type const& v) noexcept -> basic_y_type& { _y = v; return *this; }

  constexpr auto operator=(basic_y_type const& y) noexcept -> basic_y_type&
  { if (this != &y) _y = y._y; return *this; }

  constexpr auto operator+=(basic_y_type const& y) noexcept -> basic_y_type& { _y += y._y; return *this; }
  constexpr auto operator-=(basic_y_type const& y) noexcept -> basic_y_type& { _y -= y._y; return *this; }
  constexpr auto operator*=(basic_y_type const& y) noexcept -> basic_y_type& { _y *= y._y; return *this; }
  constexpr auto operator/=(basic_y_type const& y) noexcept -> basic_y_type& { _y /= y._y; return *this; }

  constexpr auto operator++() noexcept -> basic_y_type& { ++_y; return *this; }
  constexpr auto operator--() noexcept -> basic_y_type& { --_y; return *this; }

  constexpr auto operator++(int) noexcept -> basic_y_type { auto const old = *this; operator++(); return old; }
  constexpr auto operator--(int) noexcept -> basic_y_type { auto const old = *this; operator--(); return old; }

  friend constexpr auto operator>>(std::istream&, basic_y_type<T>&) noexcept -> std::istream&;
};

template <typename T>
constexpr auto operator+(basic_y_type<T> const& ylhs, basic_y_type<T> const& yrhs) noexcept -> basic_y_type<T>
{ return ylhs.value() + yrhs.value(); }

template <typename T>
constexpr auto operator-(basic_y_type<T> const& ylhs, basic_y_type<T> const& yrhs) noexcept -> basic_y_type<T>
{ return ylhs.value() - yrhs.value(); }

template <typename T>
constexpr auto operator*(basic_y_type<T> const& ylhs, basic_y_type<T> const& yrhs) noexcept -> basic_y_type<T>
{ return ylhs.value() * yrhs.value(); }

template <typename T>
constexpr auto operator/(basic_y_type<T> const& ylhs, basic_y_type<T> const& yrhs) noexcept -> basic_y_type<T>
{ return ylhs.value() / yrhs.value(); }

template<typename T>
constexpr auto operator+(basic_y_type<T> const& ylhs, typename basic_y_type<T>::value_type const& vrhs) noexcept -> basic_y_type<T>
{ return ylhs.value() + vrhs; }

template<typename T>
constexpr auto operator-(basic_y_type<T> const& ylhs, typename basic_y_type<T>::value_type const& vrhs) noexcept -> basic_y_type<T>
{ return ylhs.value() - vrhs; }

template<typename T>
constexpr auto operator*(basic_y_type<T> const& ylhs, typename basic_y_type<T>::value_type const& vrhs) noexcept -> basic_y_type<T>
{ return ylhs.value() * vrhs; }

template<typename T>
constexpr auto operator/(basic_y_type<T> const& ylhs, typename basic_y_type<T>::value_type const& vrhs) noexcept -> basic_y_type<T>
{ return ylhs.value() / vrhs; }

template <typename T>
constexpr auto operator>>(std::istream& is, basic_y_type<T>& y) noexcept -> std::istream&
{ return is >> y._y; }


template <typename T>
requires std::is_arithmetic_v<T>
class basic_z_type final {
public:
  using value_type = T;

private:
  value_type _z;

public:
  constexpr basic_z_type() noexcept : _z{} {}

  constexpr basic_z_type(value_type const v) noexcept : _z(v) {}

  constexpr basic_z_type(basic_z_type const& z) noexcept : _z(z._z) {}

  constexpr basic_z_type(basic_z_type const&& z) noexcept : _z(z._z) {}

  constexpr ~basic_z_type() noexcept {}

  constexpr auto value() const noexcept -> value_type const& { return _z; }

  constexpr auto operator<=>(value_type   const& v) const noexcept -> std::strong_ordering { return _z <=> v;    }
  constexpr auto operator<=>(basic_z_type const& z) const noexcept -> std::strong_ordering { return _z <=> z._z; }

  constexpr auto operator=(value_type const& value) noexcept -> basic_z_type& { _z = value; return *this; }

  constexpr auto operator=(basic_z_type const& z) noexcept -> basic_z_type&
  { if (this != &z) _z = z._z; return *this; }

  constexpr auto operator+=(basic_z_type const& z) noexcept -> basic_z_type& { _z += z._z; return *this; }
  constexpr auto operator-=(basic_z_type const& z) noexcept -> basic_z_type& { _z -= z._z; return *this; }
  constexpr auto operator*=(basic_z_type const& z) noexcept -> basic_z_type& { _z *= z._z; return *this; }
  constexpr auto operator/=(basic_z_type const& z) noexcept -> basic_z_type& { _z /= z._z; return *this; }

  constexpr auto operator++() noexcept -> basic_z_type& { ++_z; return *this; }
  constexpr auto operator--() noexcept -> basic_z_type& { --_z; return *this; }

  constexpr auto operator++(int) noexcept -> basic_z_type { auto const old = *this; operator++(); return old; }
  constexpr auto operator--(int) noexcept -> basic_z_type { auto const old = *this; operator--(); return old; }

  friend constexpr auto operator>>(std::istream& is, basic_z_type<T>& z) noexcept -> std::istream&;
};

template <typename T>
constexpr auto operator+(basic_z_type<T> const lhs, basic_z_type<T> const& rhs) noexcept -> basic_z_type<T>
{ return lhs.value() + rhs.value(); }

template <typename T>
constexpr auto operator-(basic_z_type<T> const lhs, basic_z_type<T> const& rhs) noexcept -> basic_z_type<T>
{ return lhs.value() - rhs.value(); }

template <typename T>
constexpr auto operator*(basic_z_type<T> const lhs, basic_z_type<T> const& rhs) noexcept -> basic_z_type<T>
{ return lhs.value() * rhs.value(); }

template <typename T>
constexpr auto operator/(basic_z_type<T> const lhs, basic_z_type<T> const& rhs) noexcept -> basic_z_type<T>
{ return lhs.value() / rhs.value(); }

template<typename T>
constexpr auto operator+(basic_z_type<T> const z, typename basic_z_type<T>::value_type const& rhs) noexcept -> basic_z_type<T>
{ return z.value() + rhs; }

template<typename T>
constexpr auto operator-(basic_z_type<T> const z, typename basic_z_type<T>::value_type const& rhs) noexcept -> basic_z_type<T>
{ return z.value() - rhs; }

template<typename T>
constexpr auto operator*(basic_z_type<T> const z, typename basic_z_type<T>::value_type const& rhs) noexcept -> basic_z_type<T>
{ return z.value() * rhs; }

template<typename T>
constexpr auto operator/(basic_z_type<T> const z, typename basic_z_type<T>::value_type const& rhs) noexcept -> basic_z_type<T>
{ return z.value() / rhs; }

template <typename T>
constexpr auto operator>>(std::istream& is, basic_z_type<T>& z) noexcept -> std::istream&
{ return is >> z._z; }

template <typename T>
class basic_xy_type final {
public:
  using x_type = basic_x_type<T>;
  using y_type = basic_y_type<T>;

  struct initializer final {
    x_type const x;
    y_type const y;
  };

private:
  x_type _x;
  y_type _y;

public:
  constexpr basic_xy_type() noexcept
  : _x{},
    _y{} {}

  constexpr basic_xy_type(initializer const init) noexcept
  : _x(init.x),
    _y(init.y) {}

  constexpr basic_xy_type(basic_xy_type const& xy) noexcept
  : _x(xy._x),
    _y(xy._y) {}

  constexpr ~basic_xy_type() noexcept {}

  constexpr auto x() const noexcept -> x_type const& { return _x; }
  constexpr auto y() const noexcept -> y_type const& { return _y; }

  constexpr auto xy() const noexcept -> basic_xy_type { return *this; }
  constexpr auto yx() const noexcept -> basic_xy_type { return {{.x = _y.value(), .y = _x.value()}}; }

  constexpr auto operator==(basic_xy_type const& xy) const noexcept -> bool
  { return _x == xy._x && _y == xy._y; }

  constexpr auto operator<(basic_xy_type const& xy) const noexcept -> bool
  { return _x < xy._x && _y < xy._y; }

  constexpr auto operator!=(basic_xy_type const& xy) const noexcept -> bool { return !operator==(xy); }
  constexpr auto operator>=(basic_xy_type const& xy) const noexcept -> bool { return !operator< (xy); }
  constexpr auto operator<=(basic_xy_type const& xy) const noexcept -> bool { return  operator< (xy) &&  operator==(xy); }
  constexpr auto operator> (basic_xy_type const& xy) const noexcept -> bool { return !operator==(xy) && !operator< (xy); }

  constexpr auto operator=(basic_xy_type const& xy) const noexcept -> basic_xy_type&
  { if (this != &xy) { _x = xy._x; _y = xy._y; } return *this; }

  constexpr auto operator+=(basic_xy_type const& xy) const noexcept -> basic_xy_type&
  { _x += xy._x; _y += xy._y; return *this; }

  constexpr auto operator-=(basic_xy_type const& xy) const noexcept -> basic_xy_type&
  { _x -= xy._x; _y -= xy._y; return *this; }

  constexpr auto operator*=(basic_xy_type const& xy) const noexcept -> basic_xy_type&
  { _x *= xy._x; _y *= xy._y; return *this; }

  constexpr auto operator/=(basic_xy_type const& xy) const noexcept -> basic_xy_type&
  { _x /= xy._x; _y /= xy._y; return *this; }

  constexpr auto operator++() const noexcept -> basic_xy_type& { ++_x; ++_y; return *this; }
  constexpr auto operator--() const noexcept -> basic_xy_type& { --_x; --_y; return *this; }

  constexpr auto operator++(int) const noexcept -> basic_xy_type { auto old = *this; operator++(); return old; }
  constexpr auto operator--(int) const noexcept -> basic_xy_type { auto old = *this; operator--(); return old; }
};

template <typename T>
constexpr auto operator+(basic_xy_type<T> const lhs, basic_xy_type<T> const& rhs) noexcept -> basic_xy_type<T>
{ return {{.x = lhs.x() + rhs.x(), .y = lhs.y() + rhs.y()}}; }

template <typename T>
constexpr auto operator-(basic_xy_type<T> const lhs, basic_xy_type<T> const& rhs) noexcept -> basic_xy_type<T>
{ return {{.x = lhs.x() - rhs.x(), .y = lhs.y() - rhs.y()}}; }

template <typename T>
constexpr auto operator*(basic_xy_type<T> const lhs, basic_xy_type<T> const& rhs) noexcept -> basic_xy_type<T>
{ return {{.x = lhs.x() * rhs.x(), .y = lhs.y() * rhs.y()}}; }

template <typename T>
constexpr auto operator/(basic_xy_type<T> const lhs, basic_xy_type<T> const& rhs) noexcept -> basic_xy_type<T>
{ return {{.x = lhs.x() / rhs.x(), .y = lhs.y() / rhs.y()}}; }

template <typename T>
class basic_xz_type final {
public:
  using x_type = basic_x_type<T>;
  using z_type = basic_z_type<T>;

  struct initializer final {
    x_type const x;
    z_type const z;
  };

private:
  x_type _x;
  z_type _z;

public:
  constexpr basic_xz_type() noexcept
  : _x{},
    _z{} {}

  constexpr basic_xz_type(initializer const init) noexcept
  : _x(init.x),
    _z(init.z) {}

  constexpr basic_xz_type(basic_xz_type const& xz) noexcept
  : _x(xz._x),
    _z(xz._z) {}

  constexpr ~basic_xz_type() noexcept {}

  constexpr auto x() const noexcept -> x_type const& { return _x; }
  constexpr auto z() const noexcept -> z_type const& { return _z; }

  constexpr auto xz() const noexcept -> basic_xz_type { return *this; }
  constexpr auto zx() const noexcept -> basic_xz_type { return {{.x = _z.value(), .z = _x.value()}}; }

  constexpr auto operator==(basic_xz_type const& xz) const noexcept -> bool
  { return _x == xz._x && _z == xz._z; }

  constexpr auto operator<(basic_xz_type const& xz) const noexcept -> bool
  { return _x < xz._x && _z < xz._z; }

  constexpr auto operator!=(basic_xz_type const& xz) const noexcept -> bool { return !operator==(xz); }
  constexpr auto operator>=(basic_xz_type const& xz) const noexcept -> bool { return !operator< (xz); }
  constexpr auto operator<=(basic_xz_type const& xz) const noexcept -> bool { return  operator< (xz) &&  operator==(xz); }
  constexpr auto operator> (basic_xz_type const& xz) const noexcept -> bool { return !operator==(xz) && !operator< (xz); }

  constexpr auto operator=(basic_xz_type const& xz) const noexcept -> basic_xz_type&
  { if (this != &xz) { _x = xz._x; _z = xz._z; } return *this; }

  constexpr auto operator+=(basic_xz_type const& xz) const noexcept -> basic_xz_type&
  { _x += xz._x; _z += xz._z; return *this; }

  constexpr auto operator-=(basic_xz_type const& xz) const noexcept -> basic_xz_type&
  { _x -= xz._x; _z -= xz._z; return *this; }

  constexpr auto operator*=(basic_xz_type const& xz) const noexcept -> basic_xz_type&
  { _x *= xz._x; _z *= xz._z; return *this; }

  constexpr auto operator/=(basic_xz_type const& xz) const noexcept -> basic_xz_type&
  { _x /= xz._x; _z /= xz._z; return *this; }

  constexpr auto operator++() const noexcept -> basic_xz_type& { ++_x; ++_z; return *this; }
  constexpr auto operator--() const noexcept -> basic_xz_type& { --_x; --_z; return *this; }

  constexpr auto operator++(int) const noexcept -> basic_xz_type { auto old = *this; operator++(); return old; }
  constexpr auto operator--(int) const noexcept -> basic_xz_type { auto old = *this; operator--(); return old; }
};

template <typename T>
constexpr auto operator+(basic_xz_type<T> const lhs, basic_xz_type<T> const& rhs) noexcept -> basic_xz_type<T>
{ return {{.x = lhs.x() + rhs.x(), .z = lhs.z() + rhs.z()}}; }

template <typename T>
constexpr auto operator-(basic_xz_type<T> const lhs, basic_xz_type<T> const& rhs) noexcept -> basic_xz_type<T>
{ return {{.x = lhs.x() - rhs.x(), .z = lhs.z() - rhs.z()}}; }

template <typename T>
constexpr auto operator*(basic_xz_type<T> const lhs, basic_xz_type<T> const& rhs) noexcept -> basic_xz_type<T>
{ return {{.x = lhs.x() * rhs.x(), .z = lhs.z() * rhs.z()}}; }

template <typename T>
constexpr auto operator/(basic_xz_type<T> const lhs, basic_xz_type<T> const& rhs) noexcept -> basic_xz_type<T>
{ return {{.x = lhs.x() / rhs.x(), .z = lhs.z() / rhs.z()}}; }

template <typename T>
class basic_yz_type final {
public:
  using y_type = basic_y_type<T>;
  using z_type = basic_z_type<T>;

  struct initializer final {
    y_type const y;
    z_type const z;
  };

private:
  y_type _y;
  z_type _z;

public:
  constexpr basic_yz_type() noexcept
  : _y{},
    _z{} {}

  constexpr basic_yz_type(initializer const init) noexcept
  : _y(init.y),
    _z(init.z) {}

  constexpr basic_yz_type(basic_yz_type const& yz) noexcept
  : _y(yz._y),
    _z(yz._z) {}

  constexpr ~basic_yz_type() noexcept {}

  constexpr auto y() const noexcept -> y_type const& { return _y; }
  constexpr auto z() const noexcept -> z_type const& { return _z; }

  constexpr auto yz() const noexcept -> basic_yz_type { return *this; }
  constexpr auto zy() const noexcept -> basic_yz_type { return {{.y = _z.value(), .z = _y.value()}}; }

  constexpr auto operator==(basic_yz_type const& yz) const noexcept -> bool
  { return _y == yz._y && _z == yz._z; }

  constexpr auto operator<(basic_yz_type const& yz) const noexcept -> bool
  { return _y < yz._y && _z < yz._z; }

  constexpr auto operator!=(basic_yz_type const& yz) const noexcept -> bool { return !operator==(yz); }
  constexpr auto operator>=(basic_yz_type const& yz) const noexcept -> bool { return !operator< (yz); }
  constexpr auto operator<=(basic_yz_type const& yz) const noexcept -> bool { return  operator< (yz) &&  operator==(yz); }
  constexpr auto operator> (basic_yz_type const& yz) const noexcept -> bool { return !operator==(yz) && !operator< (yz); }

  constexpr auto operator=(basic_yz_type const& yz) const noexcept -> basic_yz_type&
  { if (this != &yz) { _y = yz._y; _z = yz._z; } return *this; }

  constexpr auto operator+=(basic_yz_type const& yz) const noexcept -> basic_yz_type&
  { _y += yz._y; _z += yz._z; return *this; }

  constexpr auto operator-=(basic_yz_type const& yz) const noexcept -> basic_yz_type&
  { _y -= yz._y; _z -= yz._z; return *this; }

  constexpr auto operator*=(basic_yz_type const& yz) const noexcept -> basic_yz_type&
  { _y *= yz._y; _z *= yz._z; return *this; }

  constexpr auto operator/=(basic_yz_type const& yz) const noexcept -> basic_yz_type&
  { _y /= yz._y; _z /= yz._z; return *this; }

  constexpr auto operator++() const noexcept -> basic_yz_type& { ++_y; ++_z; return *this; }
  constexpr auto operator--() const noexcept -> basic_yz_type& { --_y; --_z; return *this; }

  constexpr auto operator++(int) const noexcept -> basic_yz_type { auto old = *this; operator++(); return old; }
  constexpr auto operator--(int) const noexcept -> basic_yz_type { auto old = *this; operator--(); return old; }
};

template <typename T>
constexpr auto operator+(basic_yz_type<T> const lhs, basic_yz_type<T> const& rhs) noexcept -> basic_yz_type<T>
{ return {{.y = lhs.y() + rhs.y(), .z = lhs.z() + rhs.z()}}; }

template <typename T>
constexpr auto operator-(basic_yz_type<T> const lhs, basic_yz_type<T> const& rhs) noexcept -> basic_yz_type<T>
{ return {{.y = lhs.y() - rhs.y(), .z = lhs.z() - rhs.z()}}; }

template <typename T>
constexpr auto operator*(basic_yz_type<T> const lhs, basic_yz_type<T> const& rhs) noexcept -> basic_yz_type<T>
{ return {{.y = lhs.y() * rhs.y(), .z = lhs.z() * rhs.z()}}; }

template <typename T>
constexpr auto operator/(basic_yz_type<T> const lhs, basic_yz_type<T> const& rhs) noexcept -> basic_yz_type<T>
{ return {{.y = lhs.y() / rhs.y(), .z = lhs.z() / rhs.z()}}; }

template <typename T>
class basic_point_type final {
public:
  using x_type = basic_x_type<T>;
  using y_type = basic_y_type<T>;
  using z_type = basic_z_type<T>;

  using xy_type = basic_xy_type<T>;
  using xz_type = basic_xz_type<T>;
  using yz_type = basic_yz_type<T>;

  struct initializer final {
    x_type const x;
    y_type const y;
    z_type const z;
  };

private:
  x_type _x;
  y_type _y;
  z_type _z;

public:
  constexpr basic_point_type() noexcept
  : _x{},
    _y{},
    _z{} {}

  constexpr basic_point_type(initializer const init) noexcept
  : _x(init.x),
    _y(init.y),
    _z(init.z) {}

  constexpr basic_point_type(basic_point_type const& other) noexcept
  : _x(other._x),
    _y(other._y),
    _z(other._z) {}

  constexpr ~basic_point_type() noexcept {}

  constexpr auto x() const noexcept -> x_type const& { return _x; }
  constexpr auto y() const noexcept -> y_type const& { return _y; }
  constexpr auto z() const noexcept -> z_type const& { return _z; }

  constexpr auto xy() const noexcept -> xy_type { return {{.x = _x.value(), .y = _y.value()}}; }
  constexpr auto yx() const noexcept -> xy_type { return {{.x = _y.value(), .y = _x.value()}}; }
  constexpr auto yz() const noexcept -> yz_type { return {{.y = _y.value(), .z = _z.value()}}; }
  constexpr auto zy() const noexcept -> xz_type { return {{.z = _z.value(), .y = _y.value()}}; }
  constexpr auto xz() const noexcept -> xz_type { return {{.x = _x.value(), .z = _z.value()}}; }
  constexpr auto zx() const noexcept -> xz_type { return {{.z = _z.value(), .x = _x.value()}}; }

  constexpr auto xyz() const noexcept -> basic_point_type { return *this; }
  constexpr auto xzy() const noexcept -> basic_point_type { return {{.x = _x.value(), .y = _z.value(), .z = _y.value()}}; }
  constexpr auto yxz() const noexcept -> basic_point_type { return {{.x = _y.value(), .y = _x.value(), .z = _z.value()}}; }
  constexpr auto yzx() const noexcept -> basic_point_type { return {{.x = _y.value(), .y = _z.value(), .z = _x.value()}}; }
  constexpr auto zxy() const noexcept -> basic_point_type { return {{.x = _z.value(), .y = _x.value(), .z = _y.value()}}; }
  constexpr auto zyx() const noexcept -> basic_point_type { return {{.x = _z.value(), .y = _y.value(), .z = _x.value()}}; }

  constexpr auto xxx() const noexcept -> basic_point_type { return {{.x = _x.value(), .y = _x.value(), .z = _x.value()}}; }
  constexpr auto xxy() const noexcept -> basic_point_type { return {{.x = _x.value(), .y = _x.value(), .z = _y.value()}}; }
  constexpr auto xyx() const noexcept -> basic_point_type { return {{.x = _x.value(), .y = _y.value(), .z = _x.value()}}; }
  constexpr auto yxx() const noexcept -> basic_point_type { return {{.x = _y.value(), .y = _x.value(), .z = _x.value()}}; }
  constexpr auto xxz() const noexcept -> basic_point_type { return {{.x = _x.value(), .y = _x.value(), .z = _z.value()}}; }
  constexpr auto xzx() const noexcept -> basic_point_type { return {{.x = _x.value(), .y = _z.value(), .z = _x.value()}}; }
  constexpr auto zxx() const noexcept -> basic_point_type { return {{.x = _z.value(), .y = _x.value(), .z = _x.value()}}; }

  constexpr auto yyy() const noexcept -> basic_point_type { return {{.x = _y.value(), .y = _y.value(), .z = _y.value()}}; }
  constexpr auto yyx() const noexcept -> basic_point_type { return {{.x = _y.value(), .y = _y.value(), .z = _x.value()}}; }
  constexpr auto yxy() const noexcept -> basic_point_type { return {{.x = _y.value(), .y = _x.value(), .z = _y.value()}}; }
  constexpr auto xyy() const noexcept -> basic_point_type { return {{.x = _x.value(), .y = _y.value(), .z = _y.value()}}; }
  constexpr auto yyz() const noexcept -> basic_point_type { return {{.x = _y.value(), .y = _y.value(), .z = _z.value()}}; }
  constexpr auto yzy() const noexcept -> basic_point_type { return {{.x = _y.value(), .y = _z.value(), .z = _y.value()}}; }
  constexpr auto zyy() const noexcept -> basic_point_type { return {{.x = _z.value(), .y = _y.value(), .z = _y.value()}}; }

  constexpr auto zzz() const noexcept -> basic_point_type { return {{.x = _z.value(), .y = _z.value(), .z = _z.value()}}; }
  constexpr auto zzx() const noexcept -> basic_point_type { return {{.x = _z.value(), .y = _z.value(), .z = _x.value()}}; }
  constexpr auto zxz() const noexcept -> basic_point_type { return {{.x = _z.value(), .y = _x.value(), .z = _z.value()}}; }
  constexpr auto xzz() const noexcept -> basic_point_type { return {{.x = _x.value(), .y = _z.value(), .z = _z.value()}}; }
  constexpr auto zzy() const noexcept -> basic_point_type { return {{.x = _z.value(), .y = _z.value(), .z = _y.value()}}; }
  constexpr auto zyz() const noexcept -> basic_point_type { return {{.x = _z.value(), .y = _y.value(), .z = _z.value()}}; }
  constexpr auto yzz() const noexcept -> basic_point_type { return {{.x = _y.value(), .y = _z.value(), .z = _z.value()}}; }

  constexpr auto operator<=>(basic_point_type const& point) const noexcept -> std::strong_ordering
  { return _x <=> point._x && _y <=> point._y && _z <=> point._z; }

  constexpr auto operator=(basic_point_type const& point) noexcept -> basic_point_type&
  { if (this != &point) { _x = point._x; _y = point._y; _z = point._z; } return *this; }

  constexpr auto operator+=(basic_point_type const& point) const noexcept -> basic_point_type&
  { _x += point._x; _y += point._y; _z += point._z; return *this; }

  constexpr auto operator-=(basic_point_type const& point) const noexcept -> basic_point_type&
  { _x -= point._x; _y -= point._y; _z -= point._z; return *this; }

  constexpr auto operator*=(basic_point_type const& point) const noexcept -> basic_point_type&
  { _x *= point._x; _y *= point._y; _z *= point._z; return *this; }

  constexpr auto operator/=(basic_point_type const& point) const noexcept -> basic_point_type&
  { _x /= point._x; _y /= point._y; _z /= point._z; return *this; }

};

template <typename T>
constexpr auto operator+(basic_point_type<T> const lhs, basic_point_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() + rhs.x(), .y = lhs.y() + rhs.y(), .z = lhs.z() + rhs.z()}}; }

template <typename T>
constexpr auto operator-(basic_point_type<T> const lhs, basic_point_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() - rhs.x(), .y = lhs.y() - rhs.y(), .z = lhs.z() - rhs.z()}}; }

template <typename T>
constexpr auto operator*(basic_point_type<T> const lhs, basic_point_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() * rhs.x(), .y = lhs.y() * rhs.y(), .z = lhs.z() * rhs.z()}}; }

template <typename T>
constexpr auto operator/(basic_point_type<T> const lhs, basic_point_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() / rhs.x(), .y = lhs.y() / rhs.y(), .z = lhs.z() / rhs.z()}}; }

template <typename T>
constexpr auto operator+(basic_point_type<T> const lhs, basic_xy_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() + rhs.x(), .y = lhs.y() + rhs.y(), .z = lhs.z()}}; }

template <typename T>
constexpr auto operator-(basic_point_type<T> const lhs, basic_xy_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() - rhs.x(), .y = lhs.y() - rhs.y(), .z = lhs.z()}}; }

template <typename T>
constexpr auto operator*(basic_point_type<T> const lhs, basic_xy_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() * rhs.x(), .y = lhs.y() * rhs.y(), .z = lhs.z()}}; }

template <typename T>
constexpr auto operator/(basic_point_type<T> const lhs, basic_xy_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() / rhs.x(), .y = lhs.y() / rhs.y(), .z = lhs.z()}}; }

template <typename T>
constexpr auto operator+(basic_point_type<T> const lhs, basic_xz_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() + rhs.x(), .y = lhs.y(), .z = lhs.z() + rhs.z()}}; }

template <typename T>
constexpr auto operator-(basic_point_type<T> const lhs, basic_xz_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() - rhs.x(), .y = lhs.y(), .z = lhs.z() - rhs.z()}}; }

template <typename T>
constexpr auto operator*(basic_point_type<T> const lhs, basic_xz_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() * rhs.x(), .y = lhs.y(), .z = lhs.z() * rhs.z()}}; }

template <typename T>
constexpr auto operator/(basic_point_type<T> const lhs, basic_xz_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() / rhs.x(), .y = lhs.y(), .z = lhs.z() / rhs.z()}}; }

template <typename T>
constexpr auto operator+(basic_point_type<T> const lhs, basic_yz_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x(), .y = lhs.y() + rhs.y(), .z = lhs.z() + rhs.z()}}; }

template <typename T>
constexpr auto operator-(basic_point_type<T> const lhs, basic_yz_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x(), .y = lhs.y() - rhs.y(), .z = lhs.z() - rhs.z()}}; }

template <typename T>
constexpr auto operator*(basic_point_type<T> const lhs, basic_yz_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x(), .y = lhs.y() * rhs.y(), .z = lhs.z() * rhs.z()}}; }

template <typename T>
constexpr auto operator/(basic_point_type<T> const lhs, basic_yz_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x(), .y = lhs.y() / rhs.y(), .z = lhs.z() / rhs.z()}}; }

template <typename T>
constexpr auto operator+(basic_point_type<T> const lhs, basic_x_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() + rhs, .y = lhs.y(), .z = lhs.z()}}; }

template <typename T>
constexpr auto operator-(basic_point_type<T> const lhs, basic_x_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() - rhs, .y = lhs.y(), .z = lhs.z()}}; }

template <typename T>
constexpr auto operator*(basic_point_type<T> const lhs, basic_x_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() * rhs, .y = lhs.y(), .z = lhs.z()}}; }

template <typename T>
constexpr auto operator/(basic_point_type<T> const lhs, basic_x_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x() / rhs, .y = lhs.y(), .z = lhs.z()}}; }

template <typename T>
constexpr auto operator+(basic_point_type<T> const lhs, basic_y_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x(), .y = lhs.y() + rhs, .z = lhs.z()}}; }

template <typename T>
constexpr auto operator-(basic_point_type<T> const lhs, basic_y_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x(), .y = lhs.y() - rhs, .z = lhs.z()}}; }

template <typename T>
constexpr auto operator*(basic_point_type<T> const lhs, basic_y_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x(), .y = lhs.y() * rhs, .z = lhs.z()}}; }

template <typename T>
constexpr auto operator/(basic_point_type<T> const lhs, basic_y_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x(), .y = lhs.y() / rhs, .z = lhs.z()}}; }

template <typename T>
constexpr auto operator+(basic_point_type<T> const lhs, basic_z_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x(), .y = lhs.y(), .z = lhs.z() + rhs}}; }

template <typename T>
constexpr auto operator-(basic_point_type<T> const lhs, basic_z_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x(), .y = lhs.y(), .z = lhs.z() - rhs}}; }

template <typename T>
constexpr auto operator*(basic_point_type<T> const lhs, basic_z_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x(), .y = lhs.y(), .z = lhs.z() * rhs}}; }

template <typename T>
constexpr auto operator/(basic_point_type<T> const lhs, basic_z_type<T> const rhs) noexcept -> basic_point_type<T>
{ return {{.x = lhs.x(), .y = lhs.y(), .z = lhs.z() / rhs}}; }

using x_type = basic_x_type<float>;
using y_type = basic_y_type<float>;
using z_type = basic_z_type<float>;

using xy_type = basic_xy_type<float>;
using xz_type = basic_xz_type<float>;
using yz_type = basic_yz_type<float>;

using point_type = basic_point_type<float>;

}
