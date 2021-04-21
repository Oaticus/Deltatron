#include <dt/json/token.hh>

dt::token::token(token_type const type, std::size_t const line, std::size_t const index, value_type const value) noexcept
: _type(type),
  _line(line),
  _index(index),
  _value(value) {}
