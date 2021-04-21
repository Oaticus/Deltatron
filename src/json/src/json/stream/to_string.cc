#include <dt/json/stream.hh>

#include <charconv>
#include <sstream>
#include <string>

#include <cstring>

namespace dt {

class json_stringstream final {
  class _json_stringstream_indent final {
    std::size_t const _base;
    std::size_t       _current;

  public:
    _json_stringstream_indent(std::size_t const base) noexcept
    : _base(base),
      _current(0) {}

    constexpr void decrease() noexcept { _current -= _base; }
    constexpr void increase() noexcept { _current += _base; }

    char const* chars() const noexcept {
      static auto indent_mem = std::string(_base * 4, '\0');

      if (indent_mem.capacity() < _current + 1)
        indent_mem.resize(_current * 2, '\0');

      if (indent_mem.length() < _current)
        std::memset(indent_mem.data(), ' ', _current);

      indent_mem.data()[_current + 1] = '\0';

      return indent_mem.data();
    }
  };

  std::stringstream         _stream;
  _json_stringstream_indent _indent;

public:
  json_stringstream(std::size_t const indent_base)
  : _stream(),
    _indent(indent_base) {}

  std::string str() const noexcept { return _stream.str(); }

  void add_first_token(token const& t) noexcept {
    switch (t.type()) {
      case token_type::LBrace: [[fallthrough]];
      case token_type::LBrack:
        _stream << enum_to_char(t.type());
        _indent.increase();
        break;

      case token_type::String:
        _stream << *t.value_as<std::string>();
        break;

      case token_type::Integer:
        _stream << *t.value_as<int>();
        break;

      case token_type::Float:
        _stream << *t.value_as<float>();
        break;

      case token_type::Bool:
        _stream << _indent.chars() << std::boolalpha << *t.value_as<bool>();
        break;

      case token_type::Null:
        _stream << "null";
        break;

      default: return;
    }
  }

  void add_first_comment(comment const& c) noexcept
  { _stream << c.string(); }

  void add_token(token const& t) noexcept {
    switch (t.type()) {
      case token_type::LBrace: [[fallthrough]];
      case token_type::LBrack:
        _add_newline();
        _stream << enum_to_char(t.type());
        _indent.increase();
        break;

      case token_type::RBrace: [[fallthrough]];
      case token_type::RBrack:
        _add_newline();
        _stream << enum_to_char(t.type());
        _indent.decrease();
        break;

      case token_type::Colon: [[fallthrough]];
      case token_type::Comma:
        _stream << enum_to_char(t.type()) << ' ';
        break;

      case token_type::String:
        _add_newline();
        _stream << *t.value_as<std::string>();
        break;

      case token_type::Integer:
        _add_newline();
        _stream << *t.value_as<int>();
        break;

      case token_type::Float:
        _add_newline();
        _stream << *t.value_as<float>();
        break;

      case token_type::Bool:
        _add_newline();
        _stream << _indent.chars() << std::boolalpha << *t.value_as<bool>();
        break;

      case token_type::Null:
        _add_newline();
        _stream << "null";
    }
  }

  void add_comment(comment const& c) noexcept {
    _add_newline();
    _stream << c.string();
  }

private:
  void _add_newline() noexcept
  { _stream << std::endl << _indent.chars(); }
};

}

std::string dt::to_string(json_stream const& stream) noexcept {
  if (stream.tokens.empty() && stream.comments.empty())
    return {};

  auto jss           = json_stringstream(2);
  auto tokens_iter   = stream.tokens.data();
  auto comments_iter = stream.comments.data();

  if (tokens_iter->index() == 0)
    jss.add_first_token(*tokens_iter++);

  else jss.add_first_comment(*comments_iter++);

  for (std::size_t idx = 1, size = stream.size(); idx < size; ++idx) {
    if (tokens_iter->index() == idx)
      jss.add_token(*tokens_iter++);

    else if (comments_iter->index() == idx)
      jss.add_comment(*comments_iter++);
  }

  return jss.str();
}
