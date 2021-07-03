#pragma once

#include <dt/yaml/document/node.hh>

#include <utility>
#include <vector>

namespace dt {

template <yaml_CharType CharT>
class basic_yaml_document final {
public:
  using node_type      = basic_yaml_node<CharT>;
  using node_list_type = std::vector<node_type>;

private:
  node_list_type _nodes;

public:
  constexpr basic_yaml_document()
  : _nodes{} {}

  constexpr basic_yaml_document(node_list_type&& nodes)
  : _nodes(std::forward<node_list_type>(nodes)) {}

  friend constexpr auto operator+(basic_yaml_document<CharT> const&, basic_yaml_document<CharT> const&);
};

template <typename T>
constexpr auto operator+(basic_yaml_document<T> const& lhs, basic_yaml_document<T> const& rhs)
{ return lhs._nodes + rhs._nodes; }


using yaml_document    = basic_yaml_document<char>;
using yaml_wdocument   = basic_yaml_document<wchar_t>;
using yaml_u8document  = basic_yaml_document<char8_t>;
using yaml_u16document = basic_yaml_document<char16_t>;
using yaml_u32document = basic_yaml_document<char32_t>;

}
