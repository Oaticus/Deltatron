#include <dt/json/error.hh>

#include <exception>
#include <string>

dt::json_error::json_error(std::string const& id, std::size_t const& line, std::string const& message) noexcept
: std::exception(),
  _message(id + ':' + std::to_string(line) + ": " + message) {}

dt::json_error::~json_error() noexcept {}

char const* dt::json_error::what() const noexcept
{ return _message.c_str(); }
