#include <dt/render.hh>
#include <dt/render_imp.hh>

#include <dt/command.hh>
#include <dt/filesystem.hh>

#include <memory>

dt::render::render(command const& cmd, filesystem const& fs)
: _render(std::make_unique<render_imp>(cmd, fs)) {}

dt::render::~render() noexcept {}
