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
    _y{} {}

  constexpr basic_yz_type(initializer const init) noexcept
  : _y(init.y),
    _y(init.y) {}

  constexpr basic_yz_type(basic_yz_type const& yz) noexcept
  : _y(yz._y),
    _y(yz._y) {}

  constexpr ~basic_yz_type() noexcept {}

  constexpr auto y() const noexcept -> y_type const& { return _y; }
  constexpr auto z() const noexcept -> x_type const& { return _z; }

  constexpr auto yz() const noexcept -> basic_yz_type -> { return *this; }
  constexpr auto zy() const noexcept -> basic_yz_type -> { return {{.y = _z.value(), .z = _y.value()}}; }

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
