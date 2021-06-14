#include <dt/json/stream.hh>

#include <dt/json/stream/create_stream/lexer.hh>

// #ifdef DT_DEBUG
// #include <iostream>
// #endif

namespace dt {

void append_token(lexer_state& state, token::stream_type& tokens) {
  ignore_comment(state);

  if (auto const opt_token = is_char_token(state); opt_token)
    tokens.push_back({*opt_token, state.line()});

  else if (auto const opt_string = is_string(state); opt_string)
    tokens.push_back({*opt_string, state.line()});

  else if (auto const opt_integer = is_integer(state); opt_integer)
    tokens.push_back({*opt_integer, state.line()});

  else if (auto const opt_float = is_float(state); opt_float)
    tokens.push_back({*opt_float, state.line()});

  else if (auto const is_true_kwd = is_true(state); is_true_kwd)
    tokens.push_back({true, state.line()});

  else if (auto const is_false_kwd = is_false(state); is_false_kwd)
    tokens.push_back({false, state.line()});

  else if (auto const is_null_kwd = is_null(state); is_null_kwd)
    tokens.push_back({token_type::Null, state.line()});

  else
    state.throw_error("unknown character sequence encountered");
}

}

dt::token::stream_type dt::create_stream(std::string const& id, std::string const& text_data) {
  auto token_stream = token::stream_type{};

  for (auto state = lexer_state(id, text_data); !state.eof(); state.skip_whitespace())
    append_token(state, token_stream);

// #ifdef DT_DEBUG
//   std::cout << "JSON token stream for " << id << std::endl;

//   for (auto const& token : token_stream)
//     std::cout << token;

//   std::cout << std::endl << std::endl;
// #endif

  return token_stream;
}
