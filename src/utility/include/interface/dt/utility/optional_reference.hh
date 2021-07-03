#pragma once

#include <compare>
#include <optional>
#include <utility>

namespace dt {

template <typename T>
class optional_reference final {
public:
  using value_type      = T;
  using pointer         = T*;
  using const_pointer   = T const*;
  using reference       = T&;
  using const_reference = T const&;

private:
  pointer _ptr;

public:

  constexpr optional_reference() noexcept
  : _ptr(nullptr) {}

  constexpr optional_reference(reference ref) noexcept
  : _ptr(&ref) {}

  constexpr optional_reference(optional_reference const& oref) noexcept
  : _ptr(oref._ptr) {}

  constexpr optional_reference(optional_reference&& oref) noexcept
  : _ptr(std::exchange(oref._ptr, nullptr)) {}

  constexpr ~optional_reference() noexcept {}

  constexpr auto operator=(optional_reference const& oref) noexcept
  { if (this != &oref) _ptr = oref._ptr; return *this; }

  constexpr auto operator=(reference ref) noexcept
  { _ptr = &ref; return *this; }

  constexpr auto has_value() const noexcept -> bool
  { return _ptr != nullptr; }

  constexpr operator bool() const noexcept
  { return has_value(); }

  constexpr auto value() const -> const_reference
  { if (has_value()) return *_ptr; throw std::bad_optional_access{}; }

  constexpr auto value() -> reference
  { if (has_value()) return *_ptr; throw std::bad_optional_access{}; }

  constexpr auto operator==(optional_reference const& oref) const -> std::strong_ordering
  { return _ptr <=> oref._ptr; }

  constexpr auto operator&() const -> const_pointer
  { if (has_value()) return _ptr; throw std::bad_optional_access{}; }

  constexpr auto operator&() -> pointer
  { if (has_value()) return _ptr; throw std::bad_optional_access{}; }

  constexpr auto operator*() const -> const_reference
  { if (has_value()) return *_ptr; throw std::bad_optional_access{}; }

  constexpr auto operator*() -> reference
  { if (has_value()) return *_ptr; throw std::bad_optional_access{}; }

  constexpr auto operator->() const -> const_pointer
  { if (has_value()) return _ptr; throw std::bad_optional_access{}; }

  constexpr auto operator->() -> pointer
  { if (has_value()) return _ptr; throw std::bad_optional_access{}; }

  constexpr auto rebind(reference r) noexcept -> optional_reference&
  { _ptr = &r; return *this; }
};

}
