#pragma once

#include <dt/json/stream/create_stream/lexer/state.hh>

namespace dt {

constexpr bool is_numerical_char(char const c) noexcept
{ return '0' <= c && c <= '9'; }

constexpr std::optional<token_type> is_char_token(lexer_state& state) noexcept {
  switch (*state.current_char()) {
    case ':': [[fallthrough]];
    case ',': [[fallthrough]];
    case '{': [[fallthrough]];
    case '}': [[fallthrough]];
    case '[': [[fallthrough]];
    case ']': return to_token_type(*state.current_char());
    default:  return std::nullopt;
  }
}

std::optional<std::string> is_string(lexer_state& state);

constexpr std::optional<int> is_integer(lexer_state& state) noexcept {
  if (auto const c = *state.current_char(); !is_numerical_char(c) && c != '-')
    return std::nullopt;

  auto const integer_start = state.current_char();
  auto       integer_end   = integer_start + 1;

  while (integer_end < state.end() && is_numerical_char(*integer_end))
    ++integer_end;

  int integer_value{};

  if (auto const result = std::from_chars(integer_start, integer_end, integer_value);
    result.ec != std::errc() || *integer_end == '.')
      return std::nullopt;

  state.set_current_char(integer_end - 1);

  return integer_value;
}

std::optional<float> is_float(lexer_state& state) noexcept;

constexpr bool is_true(lexer_state& state) noexcept {
  bool const b = state.current_char() + 3 <= state.end()
    && *(state.current_char() + 0) == 't'
    && *(state.current_char() + 1) == 'r'
    && *(state.current_char() + 2) == 'u'
    && *(state.current_char() + 3) == 'e';

  return b ? state.shift_current_char(3), b : b;
}

constexpr bool is_false(lexer_state& state) noexcept {
  bool const b = state.current_char() + 4 <= state.end()
    && *(state.current_char() + 0) == 'f'
    && *(state.current_char() + 1) == 'a'
    && *(state.current_char() + 2) == 'l'
    && *(state.current_char() + 3) == 's'
    && *(state.current_char() + 4) == 'e';

  return b ? state.shift_current_char(4), b : b;
}

constexpr bool is_null(lexer_state& state) noexcept {
  bool const b = state.current_char() + 3 <= state.end()
    && *(state.current_char() + 0) == 'n'
    && *(state.current_char() + 1) == 'u'
    && *(state.current_char() + 2) == 'l'
    && *(state.current_char() + 3) == 'l';

  return b ? state.shift_current_char(3), b : b;
}

constexpr void ignore_comment(lexer_state& state) noexcept {
  if (state.current_char() > state.end() - 2 || *state.current_char() != '/' || *(state.current_char() + 1) != '/')
    return;

  state.shift_current_char(2);

  for (; !state.eof(); state.shift_current_char(1))
    if (*state.current_char() == '\n')
      break;

  if (!state.eof()) {
    state.increment_line();
    state.skip_whitespace();
  }
}

}
