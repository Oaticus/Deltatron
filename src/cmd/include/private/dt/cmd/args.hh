#pragma once

#include <algorithm>
#include <optional>
#include <string_view>
#include <vector>

namespace dt {

class args final {
public:
  using const_pointer = char const* const*;

private:
  const_pointer const _beg;
  const_pointer const _end;
  std::size_t   const _size;

public:
  constexpr args(int const ac, const_pointer const av) noexcept
  : _beg(av),
    _end(av + ac),
    _size(ac) {}

  bool contains(std::string_view const s) const noexcept
  { return std::any_of(_beg, _end, [&s](auto m) { return s == m; }); }

  std::optional<std::string_view> next_to(std::string_view const s) const noexcept {
    if (auto const iter = std::find_if(_beg, _end, [&s](auto m) { return s == m; }); iter < _end - 1)
      return std::string_view(*(iter + 1));

    return std::nullopt;
  }

  constexpr std::size_t size() const noexcept { return _size; }

  constexpr std::optional<std::string_view> at(std::size_t idx) const noexcept {
    if (idx < _size)
      return std::string_view(*(_beg + idx));

    return std::nullopt;
  }

  std::vector<std::string_view> view() const noexcept {
    std::vector<std::string_view> view(_size);

    std::for_each(_beg, _end, [&view](auto cstr) mutable { view.push_back(std::string_view(cstr)); });

    return view;
  }
};

}
