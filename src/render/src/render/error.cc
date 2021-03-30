#include <dt/render/error.hh>

#include <exception>
#include <string>

dt::render_error::render_error(std::string const& message) noexcept
: std::exception(),
  _message("render: " + message) {}

dt::render_error::~render_error() noexcept {}

char const* dt::render_error::what() const noexcept { return _message.c_str(); }
