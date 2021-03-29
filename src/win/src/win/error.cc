#include <dt/win/error.hh>

#include <string>

dt::win_error::win_error(std::string const& message) noexcept
: _message("win: " + message) {}

dt::win_error::~win_error() noexcept {}

char const* dt::win_error::what() const noexcept { return _message.c_str(); }
