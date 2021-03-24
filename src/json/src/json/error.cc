#include <dt/json/error.hh>

dt::json_error::json_error(std::string const& id, std::size_t const& line, std::string const& msg) noexcept
: std::exception(),
  _msg(id + ':' + std::to_string(line) + ": " + msg) {}

dt::json_error::~json_error() noexcept {}

char const* dt::json_error::what() const noexcept
{ return _msg.c_str(); }
