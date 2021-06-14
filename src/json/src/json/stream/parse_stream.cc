#include <dt/json/stream.hh>

#include <dt/json/stream/parse_stream/parser.hh>

dt::json_container_imp dt::parse_stream(std::string const& id, token::stream_type stream) {
  if (stream.empty())
    return {};

  auto state = parser_state(id, stream);

  switch (stream.begin()->type()) {
    case token_type::String:  [[fallthrough]];
    case token_type::Null:    [[fallthrough]];
    case token_type::Bool:    [[fallthrough]];
    case token_type::Float:   [[fallthrough]];
    case token_type::Integer: return json_container_imp(*stream.begin());

    case token_type::LBrace:  return json_container_imp(parse_object(state));

    case token_type::LBrack:  return json_container_imp(parse_array(state));

    default:                  state.throw_error("Invalid token encountered");
  }
}
