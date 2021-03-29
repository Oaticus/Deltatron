#include <dt/win.hh>
#include <dt/win_imp.win32.hh>

#include <memory>

dt::win::win(cmd const& c, fs const& f)
: _win(std::make_unique<win_imp>(c, f)) {}

dt::win::~win() noexcept {}

void dt::win::begin_processing() const noexcept
{ _win->begin_processing(); }
