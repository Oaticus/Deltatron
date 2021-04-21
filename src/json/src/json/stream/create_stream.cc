#include <dt/json/stream.hh>

#include <dt/json/token.hh>
#include <dt/json/comment.hh>
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
  std::size_t          _index;
  std::size_t          _line;

public:
  lexer_state(std::string const& id, std::string const& text_data)
  : _id(id),
    _text_data(text_data),
    _end(text_data.data() + text_data.size()),
    _current_char(text_data.data()),
    _index(0),
    _line(1) {}

  constexpr bool eof() const noexcept { return _current_char >= _end; }

  constexpr const_pointer end() const noexcept { return _end; }

  constexpr const_pointer& current_char() noexcept { return _current_char; }

  constexpr std::size_t& line() noexcept { return _line; }

  constexpr std::size_t& index() noexcept { return _index; }

  constexpr std::string const& id() const noexcept { return _id; }

  constexpr void skip_whitespace() noexcept {
    do {
      ++_current_char;

      if (*_current_char == '\n')
        ++_line;

    } while (!eof() && *_current_char <= ' ');
  }
};

constexpr bool is_numerical_char(char const c) noexcept
{ return '0' <= c && c <= '9'; }

constexpr std::optional<token_type> is_char_token(lexer_state& state) noexcept {
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

  auto const string_begin = state.current_char() + 1;
  auto       string_end   = string_begin;

  for (; string_end < state.end() && *string_end != '"'; ++string_end) {
    if (*string_end == '\\')
      ++string_end;
    else if (*string_end == '\n')
      ++state.line();
  }

  if (string_end == state.end())
    throw json_error(state.id(), state.line(), "reached end of text data while evaluating string");

  state.current_char() = string_end;

  return std::string(string_begin, static_cast<std::string::size_type>(string_end - string_begin));
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
  if (auto const result = std::from_chars(integer_start, integer_end, integer_value); result.ec != std::errc())
    return std::nullopt;

  state.current_char() = integer_end - 1;

  return integer_value;
}

std::optional<float> is_float(lexer_state& state) noexcept {
  if (auto const c = *state.current_char(); !is_numerical_char(c) && c != '-' && c != '.')
    return std::nullopt;

  auto const float_begin = state.current_char();
  auto       float_end   = float_begin + 1;

  while (float_end < state.end() && (is_numerical_char(*float_end) || *float_end == '.'))
    ++float_end;

  float float_value;
#ifndef __GNUC__
  if (auto const res = std::from_chars(float_begin, float_end - 1, float_value); res.ec != std::errc())
    return std::nullopt;

#else
  // GCC 10.2: No implementation for from_chars floating-point overloads
  // TODO: Integrate Ryu floating-point library (https://github.com/ulfjack/ryu)
  try {
    auto const float_string_size = static_cast<std::string::size_type>(float_end - float_begin);
    auto const float_string      = std::string(float_begin, float_string_size);

    float_value = std::stof(float_string);

  } catch (...) { return std::nullopt; }

#endif // __GNUC__

  state.current_char() = float_end - 1;

  return float_value;
}

bool is_true(lexer_state& state) noexcept {
  bool const b = state.current_char() + 3 <= state.end()
    && *(state.current_char() + 0) == 't'
    && *(state.current_char() + 1) == 'r'
    && *(state.current_char() + 2) == 'u'
    && *(state.current_char() + 3) == 'e';

  return b ? state.current_char() += 3, b : b;
}

bool is_false(lexer_state& state) noexcept {
  bool const b = state.current_char() + 4 <= state.end()
    && *(state.current_char() + 0) == 'f'
    && *(state.current_char() + 1) == 'a'
    && *(state.current_char() + 2) == 'l'
    && *(state.current_char() + 3) == 's'
    && *(state.current_char() + 4) == 'e';

  return b ? state.current_char() += 4, b : b;
}

bool is_null(lexer_state& state) noexcept {
  bool const b = state.current_char() + 3 <= state.end()
    && *(state.current_char() + 0) == 'n'
    && *(state.current_char() + 1) == 'u'
    && *(state.current_char() + 2) == 'l'
    && *(state.current_char() + 3) == 'l';

  return b ? state.current_char() += 3, b : b;
}

void ignore_comment(lexer_state& state) noexcept {
  if (state.current_char() > state.end() - 2 || *state.current_char() != '/' || *(state.current_char() + 1) != '/')
    return;

  state.current_char() += 2;

  for (; !state.eof(); ++state.current_char())
    if (*state.current_char() == '\n')
      break;

  if (!state.eof()) {
    ++state.line();
    state.skip_whitespace();
  }
}

std::optional<std::string> is_comment(lexer_state& state) noexcept {
  if (state.current_char() > state.end() - 2 || *state.current_char() != '/' || *(state.current_char() + 1) != '/')
    return std::nullopt;

  auto const string_begin = state.current_char();
  auto       string_end   = state.current_char() + 2;

  for (; string_end < state.end(); ++string_end)
    if (*string_end == '\n')
      break;

  if (string_end < state.end())
    ++string_end;

  state.current_char() = string_end - 1;

  return std::string(string_begin, static_cast<std::string::size_type>(string_end - string_begin));
}

void append_token(lexer_state& state, token::stream_type& tokens, comment::stream_type& comments) {
  if (auto const opt_comment = is_comment(state); opt_comment)
    comments.push_back({state.index()++, *opt_comment});

  if (auto const opt_token = is_char_token(state); opt_token)
    tokens.push_back({*opt_token, state.line(), state.index()++});

  else if (auto const opt_string = is_string(state); opt_string)
    tokens.push_back({token_type::String, state.line(), state.index()++, *opt_string});

  else if (auto const opt_integer = is_integer(state); opt_integer)
    tokens.push_back({token_type::Integer, state.line(), state.index()++, *opt_integer});

  else if (auto const opt_float = is_float(state); opt_float)
    tokens.push_back({token_type::Float, state.line(), state.index()++, *opt_float});

  else if (auto const is_true_kwd = is_true(state); is_true_kwd)
    tokens.push_back({token_type::Bool, state.line(), state.index()++, true});

  else if (auto const is_false_kwd = is_false(state); is_false_kwd)
    tokens.push_back({token_type::Bool, state.line(), state.index()++, false});

  else if (auto const is_null_kwd = is_null(state); is_null_kwd)
    tokens.push_back({token_type::Null, state.line(), state.index()++});

  else
    throw json_error(state.id(), state.line(), "unknown character sequence encountered");
}

}


dt::json_stream dt::create_stream(std::string const& id, std::string const& text_data) {
  auto token_stream   = token::stream_type{};
  auto comment_stream = comment::stream_type{};

  for (auto state = lexer_state(id, text_data); !state.eof(); state.skip_whitespace())
    append_token(state, token_stream, comment_stream);

  return json_stream(token_stream, comment_stream);
}
