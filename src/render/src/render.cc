#include <dt/render.hh>
#include <dt/render_imp.hh>

#include <memory>

dt::render::render()
: _render(std::make_unique<render_imp>()) {}

dt::render::~render() noexcept {}
