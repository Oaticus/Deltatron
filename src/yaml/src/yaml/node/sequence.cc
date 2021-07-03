#include <dt/yaml.hh>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// char

template <>
dt::optional_reference<dt::basic_yaml_node<char> const>
dt::basic_yaml_node<char>::map_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& map_node = _as_sequence()[idx]; map_node.is_map())
      return map_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char> const>
dt::basic_yaml_node<char>::sequence_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& sequence_node = _as_sequence()[idx]; sequence_node.is_sequence())
      return sequence_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char> const>
dt::basic_yaml_node<char>::scalar_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& scalar_node = _as_sequence()[idx]; scalar_node.is_map())
      return scalar_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char>>
dt::basic_yaml_node<char>::map_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& map_node = _as_sequence()[idx]; map_node.is_map())
      return map_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char>>
dt::basic_yaml_node<char>::sequence_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& sequence_node = _as_sequence()[idx]; sequence_node.is_sequence())
      return sequence_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char>>
dt::basic_yaml_node<char>::scalar_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& scalar_node = _as_sequence()[idx]; scalar_node.is_sequence())
      return scalar_node;

  return {};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// wchar_t

template <>
dt::optional_reference<dt::basic_yaml_node<wchar_t> const>
dt::basic_yaml_node<wchar_t>::map_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& map_node = _as_sequence()[idx]; map_node.is_map())
      return map_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<wchar_t> const>
dt::basic_yaml_node<wchar_t>::sequence_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& sequence_node = _as_sequence()[idx]; sequence_node.is_sequence())
      return sequence_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<wchar_t> const>
dt::basic_yaml_node<wchar_t>::scalar_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& scalar_node = _as_sequence()[idx]; scalar_node.is_map())
      return scalar_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<wchar_t>>
dt::basic_yaml_node<wchar_t>::map_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& map_node = _as_sequence()[idx]; map_node.is_map())
      return map_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<wchar_t>>
dt::basic_yaml_node<wchar_t>::sequence_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& sequence_node = _as_sequence()[idx]; sequence_node.is_sequence())
      return sequence_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<wchar_t>>
dt::basic_yaml_node<wchar_t>::scalar_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& scalar_node = _as_sequence()[idx]; scalar_node.is_sequence())
      return scalar_node;

  return {};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// char8_t

template <>
dt::optional_reference<dt::basic_yaml_node<char8_t> const>
dt::basic_yaml_node<char8_t>::map_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& map_node = _as_sequence()[idx]; map_node.is_map())
      return map_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char8_t> const>
dt::basic_yaml_node<char8_t>::sequence_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& sequence_node = _as_sequence()[idx]; sequence_node.is_sequence())
      return sequence_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char8_t> const>
dt::basic_yaml_node<char8_t>::scalar_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& scalar_node = _as_sequence()[idx]; scalar_node.is_map())
      return scalar_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char8_t>>
dt::basic_yaml_node<char8_t>::map_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& map_node = _as_sequence()[idx]; map_node.is_map())
      return map_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char8_t>>
dt::basic_yaml_node<char8_t>::sequence_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& sequence_node = _as_sequence()[idx]; sequence_node.is_sequence())
      return sequence_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char8_t>>
dt::basic_yaml_node<char8_t>::scalar_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& scalar_node = _as_sequence()[idx]; scalar_node.is_sequence())
      return scalar_node;

  return {};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// char16_t

template <>
dt::optional_reference<dt::basic_yaml_node<char16_t> const>
dt::basic_yaml_node<char16_t>::map_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& map_node = _as_sequence()[idx]; map_node.is_map())
      return map_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char16_t> const>
dt::basic_yaml_node<char16_t>::sequence_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& sequence_node = _as_sequence()[idx]; sequence_node.is_sequence())
      return sequence_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char16_t> const>
dt::basic_yaml_node<char16_t>::scalar_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& scalar_node = _as_sequence()[idx]; scalar_node.is_map())
      return scalar_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char16_t>>
dt::basic_yaml_node<char16_t>::map_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& map_node = _as_sequence()[idx]; map_node.is_map())
      return map_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char16_t>>
dt::basic_yaml_node<char16_t>::sequence_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& sequence_node = _as_sequence()[idx]; sequence_node.is_sequence())
      return sequence_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char16_t>>
dt::basic_yaml_node<char16_t>::scalar_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& scalar_node = _as_sequence()[idx]; scalar_node.is_sequence())
      return scalar_node;

  return {};
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// char32_t

template <>
dt::optional_reference<dt::basic_yaml_node<char32_t> const>
dt::basic_yaml_node<char32_t>::map_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& map_node = _as_sequence()[idx]; map_node.is_map())
      return map_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char32_t> const>
dt::basic_yaml_node<char32_t>::sequence_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& sequence_node = _as_sequence()[idx]; sequence_node.is_sequence())
      return sequence_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char32_t> const>
dt::basic_yaml_node<char32_t>::scalar_at(size_type const& idx) const noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto const& scalar_node = _as_sequence()[idx]; scalar_node.is_map())
      return scalar_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char32_t>>
dt::basic_yaml_node<char32_t>::map_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& map_node = _as_sequence()[idx]; map_node.is_map())
      return map_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char32_t>>
dt::basic_yaml_node<char32_t>::sequence_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& sequence_node = _as_sequence()[idx]; sequence_node.is_sequence())
      return sequence_node;

  return {};
}

template <>
dt::optional_reference<dt::basic_yaml_node<char32_t>>
dt::basic_yaml_node<char32_t>::scalar_at(size_type const& idx) noexcept {
  if (is_sequence() && idx < _as_sequence().size())
    if (auto& scalar_node = _as_sequence()[idx]; scalar_node.is_sequence())
      return scalar_node;

  return {};
}
