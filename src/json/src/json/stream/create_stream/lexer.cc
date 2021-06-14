#include <dt/json/stream/create_stream/lexer.hh>

std::optional<std::string> dt::is_string(lexer_state& state) {
  if (*state.current_char() != '"')
    return std::nullopt;

  auto const string_begin = state.current_char() + 1;
  auto       string_end   = string_begin;

  for (; string_end < state.end() && *string_end != '"'; ++string_end) {
    if (*string_end == '\\')
      ++string_end;

    else if (*string_end == '\n')
      state.increment_line();

  }

  if (string_end == state.end())
    state.throw_error("reached end of text data while evaluating string");

  state.set_current_char(string_end);

  return std::string(string_begin, static_cast<std::string::size_type>(string_end - string_begin));
}

std::optional<float> dt::is_float(lexer_state& state) noexcept {
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

  state.set_current_char(float_end - 1);

  return float_value;
}
