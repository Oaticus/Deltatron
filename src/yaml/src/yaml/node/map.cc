#include <dt/yaml.hh>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// char

template <>
dt::optional_reference<dt::basic_yaml_node<char> const>
dt::basic_yaml_node<char>::map_at(key_type const& key) const noexcept {
 if (is_map())
   if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_map())
     return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char> const>
dt::basic_yaml_node<char>::sequence_at(key_type const& key) const noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_sequence())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char> const>
dt::basic_yaml_node<char>::scalar_at(key_type const& key) const noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_scalar())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char>>
dt::basic_yaml_node<char>::map_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_map())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char>>
dt::basic_yaml_node<char>::sequence_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_sequence())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char>>
dt::basic_yaml_node<char>::scalar_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_scalar())
      return iterator->second;

  return {};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// wchar_t

template <>
dt::optional_reference<dt::basic_yaml_node<wchar_t> const>
dt::basic_yaml_node<wchar_t>::map_at(key_type const& key) const noexcept {
 if (is_map())
   if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_map())
     return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<wchar_t> const>
dt::basic_yaml_node<wchar_t>::sequence_at(key_type const& key) const noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_sequence())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<wchar_t> const>
dt::basic_yaml_node<wchar_t>::scalar_at(key_type const& key) const noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_scalar())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<wchar_t>>
dt::basic_yaml_node<wchar_t>::map_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_map())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<wchar_t>>
dt::basic_yaml_node<wchar_t>::sequence_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_sequence())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<wchar_t>>
dt::basic_yaml_node<wchar_t>::scalar_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_scalar())
      return iterator->second;

  return {};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// char8_t

template <>
dt::optional_reference<dt::basic_yaml_node<char8_t> const>
dt::basic_yaml_node<char8_t>::map_at(key_type const& key) const noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_map())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char8_t> const>
dt::basic_yaml_node<char8_t>::sequence_at(key_type const& key) const noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_sequence())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char8_t> const>
dt::basic_yaml_node<char8_t>::scalar_at(key_type const& key) const noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_scalar())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char8_t>>
dt::basic_yaml_node<char8_t>::map_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_map())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char8_t>>
dt::basic_yaml_node<char8_t>::sequence_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_sequence())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char8_t>>
dt::basic_yaml_node<char8_t>::scalar_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_scalar())
      return iterator->second;

  return {};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// char16_t

template <>
dt::optional_reference<dt::basic_yaml_node<char16_t> const>
dt::basic_yaml_node<char16_t>::map_at(key_type const& key) const noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_map())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char16_t> const>
dt::basic_yaml_node<char16_t>::sequence_at(key_type const& key) const noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_sequence())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char16_t> const>
dt::basic_yaml_node<char16_t>::scalar_at(key_type const& key) const noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_scalar())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char16_t>>
dt::basic_yaml_node<char16_t>::map_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_map())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char16_t>>
dt::basic_yaml_node<char16_t>::sequence_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_sequence())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char16_t>>
dt::basic_yaml_node<char16_t>::scalar_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_scalar())
      return iterator->second;

  return {};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// char32_t

template <>
dt::optional_reference<dt::basic_yaml_node<char32_t> const>
dt::basic_yaml_node<char32_t>::map_at(key_type const& key) const noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_map())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char32_t> const>
dt::basic_yaml_node<char32_t>::sequence_at(key_type const& key) const noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_sequence())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char32_t> const>
dt::basic_yaml_node<char32_t>::scalar_at(key_type const& key) const noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_scalar())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char32_t>>
dt::basic_yaml_node<char32_t>::map_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_map())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char32_t>>
dt::basic_yaml_node<char32_t>::sequence_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_sequence())
      return iterator->second;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char32_t>>
dt::basic_yaml_node<char32_t>::scalar_at(key_type const& key) noexcept {
  if (is_map())
    if (auto const& iterator = _as_map().find(key); iterator != _as_map().end() && iterator->second.is_scalar())
      return iterator->second;

  return {};
}
