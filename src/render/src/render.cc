#include <dt/render.hh>
#include <dt/render_imp.hh>

dt::render::render(cmd const& c, fs const& f)
: _render(std::make_unique<render_imp>(c, f)) {}

dt::render::~render() noexcept {}
