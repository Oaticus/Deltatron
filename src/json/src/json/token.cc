#include <dt/json/token.hh>

dt::token::token(token_type const type, std::size_t const line, value_type const value) noexcept
: _type(type),
  _line(line),
  _value(value) {}
