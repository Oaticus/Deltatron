#include <dt/win.hh>

#ifdef _WIN32
#include <dt/win_imp.win32.hh>
#endif

#include <memory>

dt::win::win(cmd const& c, fs const& f)
: _win(std::make_unique<win_imp>(c, f)){}

dt::win::~win() noexcept {}

void dt::win::show() const noexcept
{ _win->show(); }

void dt::win::hide() const noexcept
{ _win->hide(); }

void dt::win::loop() const noexcept
{ _win->loop(); }
