#include <dt/filesystem/error.hh>

#include <exception>
#include <string>

dt::filesystem_error::filesystem_error(std::string const& error_message) noexcept
: std::exception(),
  _error_message(std::string("fs: ") + error_message) {}

char const* dt::filesystem_error::what() const noexcept
{ return _error_message.c_str(); }
