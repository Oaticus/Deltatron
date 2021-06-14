#include <dt/window.hh>
#include <dt/window_imp.win32.hh>

#include <memory>

dt::window::window(command const& cmd, filesystem const& fs)
: _window(std::make_unique<window_imp>(cmd, fs)) {}

dt::window::~window() noexcept {}

void dt::window::run() const noexcept
{ _window->run(); }
