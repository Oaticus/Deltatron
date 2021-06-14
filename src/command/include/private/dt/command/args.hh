#pragma once

#include <algorithm>
#include <optional>
#include <string_view>
#include <vector>

namespace dt {

class args final {
public:
  using const_iterator = char const* const*;

  struct initializer final {
    int            const arg_size;
    const_iterator const arg_list;
  };

private:
  const_iterator const _begin;
  const_iterator const _end;

public:
  constexpr args(initializer const init) noexcept
  : _begin(init.arg_list),
    _end(init.arg_list + init.arg_size) {}

  constexpr bool contains(std::string_view const s) const noexcept
  { return std::any_of(_begin, _end, [&s](auto m) constexpr { return s == m; }); }

  constexpr std::optional<std::string_view> next_to(std::string_view const s) const noexcept {
    if (auto const iter = std::find_if(_begin, _end, [&s](auto m) constexpr { return s == m; }); iter < _end - 1)
      return std::string_view(*(iter + 1));

    return std::nullopt;
  }

  constexpr auto begin() const noexcept { return _begin; }
  constexpr auto end()   const noexcept { return _end; }

  constexpr std::optional<std::string_view> at(int const idx) const noexcept {
    if (idx < static_cast<int>(_end - _begin))
      return std::string_view(*(_begin + idx));

    return std::nullopt;
  }
};

}
