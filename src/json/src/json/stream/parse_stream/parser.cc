#include <dt/json/stream/parse_stream/parser.hh>

dt::json_object dt::parse_object(parser_state& state) {
  auto new_obj = json_object{};

  state.try_increment();

  while (true) {
    if (!state.current_token().has_type(token_type::String))
      state.throw_error("Expected object entry or end of object");

    auto new_key = *state.current_token().value_as<std::string>();

    state.try_increment();

    if (!state.current_token().has_type(token_type::Colon))
      state.throw_error("Expected colon after object key");

    state.try_increment();

    switch(state.current_token().type()) {
      case token_type::Bool:    [[fallthrough]];
      case token_type::Null:    [[fallthrough]];
      case token_type::Float:   [[fallthrough]];
      case token_type::String:  [[fallthrough]];
      case token_type::Integer: new_obj.emplace(new_key, json_container_imp(state.current_token())); break;

      case token_type::LBrace:  new_obj.emplace(new_key, json_container_imp(parse_object(state))); break;

      case token_type::LBrack:  new_obj.emplace(new_key, json_container_imp(parse_array(state))); break;

      default:                  state.throw_error("Expected object entry value after colon");
    }

    state.try_increment();

    if (!state.current_token().has_type(token_type::Comma)) {
      if (!state.current_token().has_type(token_type::RBrace))
        state.throw_error("Expected end of object or comma");

      break;
    }

    state.try_increment();
  }

  return new_obj;
}

dt::json_array dt::parse_array(parser_state& state) {
  auto new_arr = json_array{};

  state.try_increment();

  while (true) {
    switch (state.current_token().type()) {
      case token_type::Bool:    [[fallthrough]];
      case token_type::Null:    [[fallthrough]];
      case token_type::Float:   [[fallthrough]];
      case token_type::String:  [[fallthrough]];
      case token_type::Integer: new_arr.push_back(json_container_imp(state.current_token())); break;

      case token_type::LBrace:  new_arr.push_back(json_container_imp(parse_object(state))); break;

      case token_type::LBrack:  new_arr.push_back(json_container_imp(parse_array(state))); break;

      default:                  state.throw_error("Expected array entry value or end of array");
    }

    if (!state.current_token().has_type(token_type::Comma)) {
      if (!state.current_token().has_type(token_type::RBrack))
        state.throw_error("Expected end of array or comma");

      break;
    }

    state.try_increment();
  }

  return new_arr;
}
