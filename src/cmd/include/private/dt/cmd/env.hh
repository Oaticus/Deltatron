#pragma once

#include <algorithm>
#include <optional>
#include <string>
#include <string_view>

#include <cstring>

namespace dt {

class env final {
  using const_pointer  = std::string_view::const_pointer;
  using const_iterator = const_pointer const*;

  const_iterator const _beg;
  const_iterator const _end;

public:
  constexpr env(const_iterator ep) noexcept
  : _beg(ep),
    _end([ep]() mutable { while (*(++ep)) {} return ep; }()) {}

  bool contains(std::string const& s) const noexcept
  { return std::any_of(_beg, _end, [&](auto const& m) { return s == _name(m); }); }

  std::optional<std::string> value_of(std::string const& s) const noexcept {
    if (const_iterator iter = std::find_if(_beg, _end, [&](auto m) { return s == _name(m); }); iter != _end)
      if (auto m = *iter, v = _name_value_border(m) + 1; v < m + std::strlen(m))
        return v;

    return nullptr;
  }

private:
  std::string_view _name(const_pointer const m) const noexcept
  { return std::string_view(m, static_cast<std::size_t>(_name_value_border(m) - m)); }

  const_pointer _name_value_border(const_pointer const m) const noexcept
  { return std::find_if(m, m + std::strlen(m), [](char const c) { return c == '='; }); }
};

}
