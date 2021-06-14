#include <dt/json/token.hh>

#include <iomanip>  // std::setprecision
#include <iostream> // std::ostream
#include <string>

dt::token::token(std::string string_value, size_type line) noexcept
: _type(token_type::String),
  _line(line),
  _value(string_value) {}

std::ostream& dt::operator<<(std::ostream& os, token const& t) noexcept {
  switch (t.type()) {
    case token_type::String:  return os << '"' << *t.value_as<std::string>() << "\" ";
    case token_type::Integer: return os << *t.value_as<int>() << ' ';
    case token_type::Float:   return os << std::setprecision(3) << *t.value_as<float>() << ' ';
    case token_type::Bool:    return os << std::boolalpha << *t.value_as<bool>() << ' ';
    case token_type::Null:    return os << "Null ";
    default:                  return os << to_char(t.type()) << ' ';
  }
}
