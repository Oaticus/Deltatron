#include <dt/gpu/error.hh>

#include <exception>
#include <string>

dt::gpu_error::gpu_error(std::string const& msg) noexcept
: std::exception(),
  _msg(std::string("gpu: ") + msg) {}

dt::gpu_error::~gpu_error() noexcept {}

char const* dt::gpu_error::what() const noexcept { return _msg.c_str(); }
