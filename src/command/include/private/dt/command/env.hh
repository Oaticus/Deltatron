#pragma once

#include <algorithm>
#include <optional>
#include <string>
#include <string_view>

namespace dt {

class env final {
public:
  using const_pointer  = char const*;
  using const_iterator = const_pointer const*;

private:
  const_iterator const _begin;
  const_iterator const _end;

public:
  constexpr env(const_iterator ep) noexcept
  : _begin(ep),
    _end(_find_end(ep)) {}

  bool contains(std::string const& s) const noexcept
  { return std::any_of(_begin, _end, [&](auto const& m) constexpr { return s == _name(m); }); }

  std::optional<std::string> value_of(std::string const& s) const noexcept {
    if (const_iterator iter = std::find_if(_begin, _end, [&](auto m) { return s == _name(m); }); iter != _end)
      if (auto m = *iter, v = _name_value_border(m) + 1; v < m + std::strlen(m))
        return v;

    return nullptr;
  }

private:
  std::string_view _name(const_pointer const m) const noexcept
  { return std::string_view(m, static_cast<std::size_t>(_name_value_border(m) - m)); }

  constexpr const_pointer _name_value_border(const_pointer const m) const noexcept
  { return std::find_if(m, m + _strlen(m), [](char const c) constexpr { return c == '='; }); }

  constexpr const_iterator _find_end(const_iterator ep) const noexcept
  { while (*(++ep)) {} return ep; }

  constexpr std::size_t _strlen(const_pointer const& str) const noexcept {
    for (std::size_t len{}; true; ++len)
      if (*(str + len) == '\0')
        return len;

    return -1;
  }
};

}
