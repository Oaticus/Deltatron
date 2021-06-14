#include <dt/json/stream/create_stream/lexer/state.hh>

dt::lexer_state::lexer_state(std::string const& id, std::string const& text_data) noexcept
: _id(id),
  _text_data(text_data),
  _end(text_data.data() + text_data.size()),
  _current_char(text_data.data()),
  _line(1) {}

[[noreturn]] void dt::lexer_state::throw_error(char const* message) const
{ throw json_error(_id, _line, message); }
