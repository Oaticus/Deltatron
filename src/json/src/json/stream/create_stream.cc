#include <dt/json/stream.hh>

#include <dt/json/token.hh>
#include <dt/json/error.hh>

#include <charconv>
#include <optional>

namespace dt {

class lexer_state final {
public:
  using const_pointer = std::string::const_pointer;

private:
  std::string   const& _id;
  std::string   const& _text_data;
  const_pointer const  _end;
  const_pointer        _current_char;
  std::uint32_t        _line;

public:
  lexer_state(std::string const& id, std::string const& text_data)
  : _id(id),
    _text_data(text_data),
    _end(text_data.data() + text_data.size()),
    _current_char(text_data.data()),
    _line(1) {}

  constexpr bool eof() const noexcept { return _current_char >= _end; }

  constexpr const_pointer end() const noexcept { return _end; }

  constexpr const_pointer& current_char() noexcept { return _current_char; }

  constexpr std::uint32_t& line() noexcept { return _line; }

  constexpr std::string const& id() const noexcept { return _id; }
};

constexpr bool is_numerical_char(char const c)noexcept
{ return '0' <= c && c <= '9'; }

std::optional<token_type> is_char_token(lexer_state& state) noexcept {
  switch (*state.current_char()) {
    case ':': [[fallthrough]];
    case ',': [[fallthrough]];
    case '{': [[fallthrough]];
    case '}': [[fallthrough]];
    case '[': [[fallthrough]];
    case ']': return char_to_enum(*state.current_char());
    default:  return std::nullopt;
  }
}

std::optional<std::string> is_string(lexer_state& state) {
  if (*state.current_char() != '"')
    return std::nullopt;

  auto const string_start = state.current_char() + 1;
  auto       string_end   = string_start;

  for (; string_end < state.end() && *string_end != '"'; ++string_end) {
    if (*string_end == '\\')
      ++string_end;
    else if (*string_end == '\n')
      ++state.line();
  }

  if (string_end == state.end())
    throw json_error(state.id(), state.line(), "reached end of text data while evaluating string");

  state.current_char() = string_end;

  return std::string(string_start, static_cast<std::string::size_type>(string_end - string_start));
}

std::optional<int> is_integer(lexer_state& state) noexcept {
  if (auto const c = *state.current_char(); !is_numerical_char(c) && c != '-')
    return std::nullopt;

  auto const integer_start = state.current_char();
  auto       integer_end   = integer_start + 1;

  while (integer_end < state.end() && is_numerical_char(*integer_end))
    ++integer_end;

  if (*integer_end == '.')
    return std::nullopt;

  int integer_value;
  if (auto const res = std::from_chars(integer_start, integer_end, integer_value); res.ec != std::errc())
    return std::nullopt;

  state.current_char() = integer_end - 1;

  return integer_value;
}

std::optional<float> is_float(lexer_state& state) noexcept {
  if (auto const c = *state.current_char(); !is_numerical_char(c) && c != '-' && c != '.')
    return std::nullopt;

  auto const float_start = state.current_char();
  auto       float_end   = float_start + 1;

  while (float_end < state.end() && (is_numerical_char(*float_end) || *float_end == '.'))
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

  state.current_char() = float_end - 1;

  return float_value;
}



constexpr bool is_true(lexer_state& state) noexcept {
  bool const b = state.current_char() + 3 <= state.end()
    && *(state.current_char() + 0) == 't'
    && *(state.current_char() + 1) == 'r'
    && *(state.current_char() + 2) == 'u'
    && *(state.current_char() + 3) == 'e';

  return b ? state.current_char() += 3, b : b;
}

constexpr bool is_false(lexer_state& state) noexcept {
  bool const b = state.current_char() + 4 <= state.end()
    && *(state.current_char() + 0) == 'f'
    && *(state.current_char() + 1) == 'a'
    && *(state.current_char() + 2) == 'l'
    && *(state.current_char() + 3) == 's'
    && *(state.current_char() + 4) == 'e';

  return b ? state.current_char() += 4, b : b;
}

constexpr bool is_null(lexer_state& state) noexcept {
  bool const b = state.current_char() + 3 <= state.end()
    && *(state.current_char() + 0) == 'n'
    && *(state.current_char() + 1) == 'u'
    && *(state.current_char() + 2) == 'l'
    && *(state.current_char() + 3) == 'l';

  return b ? state.current_char() += 3, b : b;
}

  void append_token(lexer_state& state, token::stream_type& stream) {
    if (auto const opt_token = is_char_token(state); opt_token)
      stream.push_back({*opt_token, state.line()});

    else if (auto const opt_string = is_string(state); opt_string)
      stream.push_back({token_type::String, state.line(), *opt_string});

    else if (auto const opt_integer = is_integer(state); opt_integer)
      stream.push_back({token_type::Integer, state.line(), *opt_integer});

    else if (auto const opt_float = is_float(state); opt_float)
      stream.push_back({token_type::Float, state.line(), *opt_float});

    else if (auto const is_true_kwd = is_true(state); is_true_kwd)
      stream.push_back({token_type::Bool, state.line(), true});

    else if (auto const is_false_kwd = is_false(state); is_false_kwd)
      stream.push_back({token_type::Bool, state.line(), false});

    else if (auto const is_null_kwd = is_null(state); is_null_kwd)
      stream.push_back({token_type::Null, state.line()});

    else
      throw json_error(state.id(), state.line(), "unknown character sequence encountered");
  }

}

dt::token::stream_type dt::create_stream(std::string const& id, std::string const& text_data) {
  auto stream = token::stream_type{};

  for (auto state = lexer_state(id, text_data); state.eof();)
    append_token(state, stream);

  return stream;
}
