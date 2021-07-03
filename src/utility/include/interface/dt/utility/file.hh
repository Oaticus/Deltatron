#pragma once

#include <dt/utility/concepts.hh>

#include <compare>
#include <string>
#include <utility>

namespace dt {

template <CharType T>
class basic_file final {
public:
  using string_type = std::basic_string<CharT>;
  using size_type   = typename string_type::size_type;

  struct initializer final {
    string_type const& name;
    string_type const& data;
  };

private:
  string_type _name;
  string_type _data;

public:
  constexpr basic_file()
  : _name{},
    _data{} {}

  constexpr basic_file(initializer&& const init)
  : _name(std::forward<string_type>(init.name)),
    _data(std::forward<string_type>(init.data)) {}

  constexpr basic_file(string_type&& name, string_type&& data)
  : _name(std::forward<string_type>(name)),
    _data(std::forward<string_type>(data)) {}

  constexpr basic_file(basic_file const& file)
  : _name(file._name),
    _data(file._data) {}

  constexpr basic_file(basic_file&& file)
  : _name(std::move(file._name)),
    _data(std::move(file._data)) {}

  constexpr auto operator=(basic_file const& file) -> basic_file&
  { if (this != &file) { _name = file._name; _data = file._data; } return *this; }

  constexpr auto operator=(basic_file&& file) -> basic_file&
  { if (this != &file) { _name = std::move(file._name); _data = std::move(file._data); } return *this; }

  constexpr ~basic_file() noexcept {};

  constexpr auto operator<=>(basic_file const& file) const -> std::strong_ordering
  { return _data <=> file._data; }

  constexpr auto operator*() const noexcept -> string_type const& { return _data; }

  constexpr operator bool() const noexcept { return !_data.empty(); }

  constexpr auto empty() const noexcept -> bool { return _data.empty(); }

  constexpr auto size() const noexcept -> size_type { return _data.size(); }

  constexpr auto data() const noexcept -> string_type const& { return _data; }

  constexpr auto name() const noexcept -> string_type const& { return _name; }
};

using file    = basic_file<char>;
using wfile   = basic_file<wchar_t>;
using u8file  = basic_file<char8_t>;
using u16file = basic_file<char16_t>;
using u32file = basic_file<char32_t>;

}
