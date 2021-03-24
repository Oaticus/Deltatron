#include <dt/fs/error.hh>

#include <exception>
#include <string>

dt::fs_error::fs_error(std::string const& error_message) noexcept
: std::exception(),
  _error_message(std::string("fs: ") + error_message) {}

char const* dt::fs_error::what() const noexcept
{ return _error_message.c_str(); }
