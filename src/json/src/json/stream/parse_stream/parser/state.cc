#include <dt/json/stream/parse_stream/parser/state.hh>

dt::parser_state::parser_state(std::string const& id, token::stream_type& stream) noexcept
: _id(id),
  _current_token(stream.data()),
  _end(_current_token + stream.size()) {}

[[noreturn]] void dt::parser_state::throw_error(char const* message) const
{ throw json_error(_id, current_token_line(), message); }

void dt::parser_state::try_increment() {
  ++_current_token;

  if (eof())
    throw_error("Unexpected end of file while parsing JSON data");
}
