#pragma once

#include <dt/yaml/document/node/type_definitions.hh>

#include <dt/utility/optional_reference.hh>

#include <compare>
#include <functional>
#include <utility>

namespace dt {

template <yaml_CharType CharT>
class basic_yaml_node final {
public:
  using string_type   = std::basic_string<CharT>;
  using scalar_type   = basic_yaml_scalar<CharT>;
  using sequence_type = basic_yaml_sequence<CharT>;
  using map_type      = basic_yaml_map<CharT>;

  using value_type    = std::variant<scalar_type, map_type, sequence_type>;

  using size_type       = std::size_t;
  using key_type        = typename map_type::key_type;
  using difference_type = std::ptrdiff_t;

  struct file_initializer final {
    string_type const& name;
    string_type const& data;
  };

private:
  value_type  _value;
  string_type _anchor;

public:
  constexpr basic_yaml_node() noexcept
  : _value(std::nullopt),
    _anchor{} {}

  basic_yaml_node(file_initializer const);

  template <yaml_NodeConstructible<CharT> T>
  // requires yaml_NodeConstructible<T, CharT>
  constexpr basic_yaml_node(T&& value, string_type&& anchor = {})
  : _value(std::forward<T>(value)),
    _anchor(std::forward<string_type>(anchor)) {}

  basic_yaml_node(basic_yaml_node const&) = default;

  basic_yaml_node(basic_yaml_node&&) = default;

  constexpr ~basic_yaml_node() noexcept {};

  constexpr auto operator=(basic_yaml_node const& node) -> basic_yaml_node&
  { if (this != &node) _value = node._value; return *this; }

  constexpr auto operator=(basic_yaml_node&& node) -> basic_yaml_node&
  { if (this != &node) _value = std::exchange(node._value, std::nullopt); return *this; }

  constexpr operator bool() const noexcept { return !_scalar_holds<std::nullopt_t>(); }
  constexpr auto has_value() const noexcept -> bool { return operator bool(); }

  constexpr auto operator==(basic_yaml_node const& node) const noexcept -> bool
  { return _value == node._value && _anchor = node._anchor; }

  constexpr auto operator!=(basic_yaml_node const& node) const noexcept -> bool { return !operator==(node); }

  constexpr auto operator< (basic_yaml_node const&) const noexcept -> bool = delete;
  constexpr auto operator> (basic_yaml_node const&) const noexcept -> bool = delete;
  constexpr auto operator<=(basic_yaml_node const&) const noexcept -> bool = delete;
  constexpr auto operator>=(basic_yaml_node const&) const noexcept -> bool = delete;

  constexpr auto is_map()      const noexcept -> bool { return std::holds_alternative<map_type>(_value);      }
  constexpr auto is_sequence() const noexcept -> bool { return std::holds_alternative<sequence_type>(_value); }
  constexpr auto is_scalar()   const noexcept -> bool { return std::holds_alternative<scalar_type>(_value);   }

  template <typename T>
  requires yaml_ScalarType<T, CharT>
  constexpr auto scalar_as() const noexcept -> optional_reference<T const>
  { if (_scalar_holds<T>()) return std::get<T>(_as_scalar()); return {}; }

  template <typename T>
  requires yaml_ScalarType<T, CharT>
  constexpr auto scalar_as() noexcept -> optional_reference<T>
  { if (_scalar_holds<T>()) return std::get<T>(_as_scalar()); return {}; }

  auto map_at(key_type const& key)       const noexcept -> optional_reference<basic_yaml_node const>;
  auto sequence_at(key_type const& key)  const noexcept -> optional_reference<basic_yaml_node const>;
  auto scalar_at(key_type const& key)    const noexcept -> optional_reference<basic_yaml_node const>;
  auto map_at(key_type const& key)             noexcept -> optional_reference<basic_yaml_node      >;
  auto sequence_at(key_type const& key)        noexcept -> optional_reference<basic_yaml_node      >;
  auto scalar_at(key_type const& key)          noexcept -> optional_reference<basic_yaml_node      >;

  auto map_at(size_type const& idx)      const noexcept -> optional_reference<basic_yaml_node const>;
  auto sequence_at(size_type const& idx) const noexcept -> optional_reference<basic_yaml_node const>;
  auto scalar_at(size_type const& idx)   const noexcept -> optional_reference<basic_yaml_node const>;
  auto map_at(size_type const& idx)            noexcept -> optional_reference<basic_yaml_node      >;
  auto sequence_at(size_type const& idx)       noexcept -> optional_reference<basic_yaml_node      >;
  auto scalar_at(size_type const& idx)         noexcept -> optional_reference<basic_yaml_node      >;

private:
  constexpr auto _as_map()      const noexcept -> map_type      const& { return std::get<map_type     >(_value); }
  constexpr auto _as_sequence() const noexcept -> sequence_type const& { return std::get<sequence_type>(_value); }
  constexpr auto _as_scalar()   const noexcept -> scalar_type   const& { return std::get<scalar_type  >(_value); }

  constexpr auto _as_map()            noexcept -> map_type           & { return std::get<map_type     >(_value); }
  constexpr auto _as_sequence()       noexcept -> sequence_type      & { return std::get<sequence_type>(_value); }
  constexpr auto _as_scalar()         noexcept -> scalar_type        & { return std::get<scalar_type  >(_value); }

  template <typename T>
  constexpr auto _scalar_holds() const noexcept -> bool { return is_scalar() && std::holds_alternative<T>(_as_scalar()); }
};

using yaml_node    = basic_yaml_node<char>;
using yaml_wnode   = basic_yaml_node<wchar_t>;
using yaml_u8node  = basic_yaml_node<char8_t>;
using yaml_u16node = basic_yaml_node<char16_t>;
using yaml_u32node = basic_yaml_node<char32_t>;

}
