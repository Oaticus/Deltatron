#pragma once

#include <optional>
#include <type_traits>
#include <string>
#include <unordered_map>
#include <variant>
#include <vector>

namespace dt {

template <typename T>
concept yaml_CharType =
  std::is_same_v<T, char>     ||
  std::is_same_v<T, wchar_t>  ||
  std::is_same_v<T, char8_t>  ||
  std::is_same_v<T, char16_t> ||
  std::is_same_v<T, char32_t>;

template <yaml_CharType CharT>
class basic_yaml_node;

template <yaml_CharType CharT>
using basic_yaml_map = std::unordered_map<std::basic_string<CharT>, basic_yaml_node<CharT>>;

template <yaml_CharType CharT>
using basic_yaml_scalar = std::variant<std::basic_string<CharT>, int, float, bool, std::nullopt_t>;

template <yaml_CharType CharT>
using basic_yaml_sequence = std::vector<basic_yaml_node<CharT>>;

template <typename T, typename CharT>
concept yaml_ScalarType =
  yaml_CharType<CharT> &&
  requires (T&& v) { std::basic_string<CharT>(v); } ||
  std::is_same_v<T, int>                            ||
  std::is_same_v<T, float>                          ||
  std::is_same_v<T, bool>;

template <typename T, typename CharT>
concept yaml_NodeConstructible =
  yaml_ScalarType<T, CharT>                         ||
  requires (T v) { basic_yaml_map<CharT>(v); }      ||
  requires (T v) { basic_yaml_sequence<CharT>(v); };
}
