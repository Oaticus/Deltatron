#pragma once

#include <dt/yaml/document.hh>

#include <algorithm>
#include <utility>
#include <vector>

namespace dt {

template <yaml_CharType CharT>
class basic_yaml_stream final {
public:
  using document_type      = basic_yaml_document<CharT>;
  using document_list_type = std::vector<document_type>;
  using size_type          = typename document_list_type::size_type;
  using iterator           = typename document_list_type::iterator;
  using const_iterator     = typename document_list_type::const_iterator;

private:
  document_list_type _document_list;

public:
  constexpr basic_yaml_stream()
  : _document_list{} {}

  constexpr basic_yaml_stream(document_list_type&& documents)
  : _document_list(std::forward<document_list_type>(documents)) {}

  constexpr auto documents() const noexcept -> document_list_type const& { return _document_list; }

  constexpr auto size() const noexcept -> size_type { return _document_list.size(); }

  constexpr auto begin()        noexcept -> iterator       { return _document_list.begin();  }
  constexpr auto cbegin() const noexcept -> const_iterator { return _document_list.cbegin(); }

  constexpr auto end()        noexcept -> iterator       { return _document_list.end();  }
  constexpr auto cend() const noexcept -> const_iterator { return _document_list.cend(); }
};

template <yaml_CharType CharT>
constexpr auto operator+(basic_yaml_stream<CharT> const& lhs, basic_yaml_stream<CharT> const& rhs) -> basic_yaml_stream<CharT> {
  using stream_type        = basic_yaml_stream<CharT>;
  using document_type      = typename stream_type::document_type;
  using document_list_type = typename stream_type::document_list_type;

  auto new_stream = document_list_type(lhs.size() + rhs.size(), document_type{});

  std::copy(lhs.begin(), lhs.end(), new_stream.begin());
  std::copy(rhs.begin(), rhs.end(), new_stream.begin() + lhs.size());

  return new_stream;
}

using yaml_stream    = basic_yaml_stream<char>;
using yaml_wstream   = basic_yaml_stream<wchar_t>;
using yaml_u8stream  = basic_yaml_stream<char8_t>;
using yaml_u16stream = basic_yaml_stream<char16_t>;
using yaml_u32stream = basic_yaml_stream<char32_t>;

}
