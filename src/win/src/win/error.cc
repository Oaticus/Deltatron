#include <dt/win/error.hh>

#include <string>

dt::win_error::win_error(std::string const& msg) noexcept
: _msg(std::string("win: ") + msg) {}

dt::win_error::~win_error() noexcept {}

char const* dt::win_error::what() const noexcept { return _msg.c_str(); }
