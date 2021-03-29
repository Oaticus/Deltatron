#include <dt/deltatron.hh>

dt::deltatron::deltatron(int const ac, char const* const* const av, char const* const* const ep)
: _cmd(ac, av, ep),
  _fs(_cmd),
  _win(_cmd, _fs) {}

dt::deltatron::~deltatron() noexcept {}

void dt::deltatron::run() const {

  _win.begin_processing();

}
