#pragma once

#include <dt/json/lexical_analysis/token.hh>
#include <dt/json/error.hh>

#include <charconv>
#include <optional>
#include <string>

namespace dt {

class lexer final {
public:
  using iterator = char const*;

private:
  std::string   const& _id;
  iterator      const  _data_begin;
  iterator      const  _data_end;
  iterator             _data_head;
  std::uint32_t        _line;

private:
  lexer(std::string const& id, std::string const& text_data) noexcept
  : _id(id),
    _data_begin(text_data.data()),
    _data_end(_data_begin + text_data.size()),
    _data_head(_data_begin),
    _line(1) {}

  constexpr bool done() const noexcept
  { return _data_head >= _data_end; }

  constexpr lexer& operator++() noexcept {
    do {
      if (*_data_head == '\n')
        ++_line;

      ++_data_head;

    } while (!done() && *_data_head <= ' ');

    return *this;
  }

  void append_token(token::stream_type& stream) {
    using namespace std::string_literals;

    if (auto const opt_token = is_char_token(); opt_token)
      stream.push_back({*opt_token, _line});

    else if (auto const opt_string = is_string(); opt_string)
      stream.push_back({token_type::String, _line, *opt_string});

    else if (auto const opt_integer = is_integer(); opt_integer)
      stream.push_back({token_type::Integer, _line, *opt_integer});

    else if (auto const opt_float = is_float(); opt_float)
      stream.push_back({token_type::Float, _line, *opt_float});

    else if (auto const is_true_kwd = is_true(); is_true_kwd)
      stream.push_back({token_type::Bool, _line, true});

    else if (auto const is_false_kwd = is_false(); is_false_kwd)
      stream.push_back({token_type::Bool, _line, false});

    else if (auto const is_null_kwd = is_null(); is_null_kwd)
      stream.push_back({token_type::Null, _line});

    else
      throw json_error(_id, _line, "unknown character sequence encountered");
  }

  constexpr std::optional<token_type> is_char_token() const noexcept {
    switch (*_data_head) {
      case ':': [[fallthrough]];
      case ',': [[fallthrough]];
      case '{': [[fallthrough]];
      case '}': [[fallthrough]];
      case '[': [[fallthrough]];
      case ']':
        return char_to_enum(*_data_head);
      default:
        return std::nullopt;
    }
  }

  constexpr std::optional<std::string_view> is_string() {
    if (*_data_head != '"')
      return std::nullopt;

    auto const string_start = _data_head + 1;
    auto       string_end   = string_start;

    for (; string_end < _data_end && *string_end != '"'; ++string_end) {
      if (*string_end == '\\')
        ++string_end;
      else if (*string_end == '\n')
        ++_line;
    }

    if (string_end == _data_end)
      throw json_error(_id, _line, "reached end of text data while evaluating string");

    _data_head = string_end;

    return std::string_view(string_start, static_cast<std::string_view::size_type>(string_end - string_start));
  }

  std::optional<int> is_integer() noexcept {
    if (auto const c = *_data_head; !_is_numerical_char(c) && c != '-')
      return std::nullopt;

    auto const integer_start = _data_head;
    auto       integer_end   = integer_start + 1;

    while (integer_end < _data_end && _is_numerical_char(*integer_end))
      ++integer_end;

    if (*integer_end == '.')
      return std::nullopt;

    int integer_value;
    if (auto const res = std::from_chars(integer_start, integer_end, integer_value); res.ec != std::errc())
      return std::nullopt;

    _data_head = integer_end - 1;

    return integer_value;
  }

  std::optional<float> is_float() noexcept {
    if (auto const c = *_data_head; !_is_numerical_char(c) && c != '-' && c != '.')
      return std::nullopt;

    auto const float_start = _data_head;
    auto       float_end   = float_start + 1;

    while (float_end < _data_end && (_is_numerical_char(*float_end) || *float_end == '.'))
      ++float_end;

    float float_value;
#ifndef __GNUC__
    if (auto const res = std::from_chars(float_start, float_end, float_value); res.ec != std::errc())
      return std::nullopt;
#else
    // GCC 10.2: no implementation for from_chars floating-point overloads
    // TODO: integrate ryu floating-point conversion library (https://github.com/ulfjack/ryu)
    try {
      float_value = std::stof(std::string(float_start, static_cast<std::string::size_type>(float_end - float_start)));
    } catch (...) { return std::nullopt; }
#endif

    _data_head = float_end - 1;

    return float_value;
  }

  constexpr bool _is_numerical_char(char const c) const noexcept
  { return '0' <= c && c <= '9'; }

  constexpr bool is_true() noexcept {
    bool const b = _data_head + 3 <= _data_end
      && *(_data_head + 0) == 't'
      && *(_data_head + 1) == 'r'
      && *(_data_head + 2) == 'u'
      && *(_data_head + 3) == 'e';

    return b ? _data_head += 3, b : b;
  }

  constexpr bool is_false() noexcept {
    bool const b = _data_head + 4 <= _data_end
      && *(_data_head + 0) == 'f'
      && *(_data_head + 1) == 'a'
      && *(_data_head + 2) == 'l'
      && *(_data_head + 3) == 's'
      && *(_data_head + 4) == 'e';

    return b ? _data_head += 4, b : b;
  }

  constexpr bool is_null() noexcept {
    bool const b = _data_head + 3 <= _data_end
      && *(_data_head + 0) == 'n'
      && *(_data_head + 1) == 'u'
      && *(_data_head + 2) == 'l'
      && *(_data_head + 3) == 'l';

    return b ? _data_head += 3, b : b;
  }

public:
  static token::stream_type create_stream(std::string const& id, std::string const& text_data) {
    token::stream_type stream{};

    for (lexer lx(id, text_data); !lx.done(); ++lx)
      lx.append_token(stream);

    //dbg::raw_printout(stream);

    return stream;
  }
};

}
