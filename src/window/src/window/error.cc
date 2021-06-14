#include <dt/window/error.hh>

#include <string>

dt::window_error::window_error(std::string const& message) noexcept
: _message("win: " + message) {}

dt::window_error::~window_error() noexcept {}

char const* dt::window_error::what() const noexcept { return _message.c_str(); }
