#include <dt/deltatron.hh>

dt::deltatron::deltatron(int const ac, char const* const* const av, char const* const* const ep)
: _cmd(ac, av, ep),
  _fs(_cmd) {}

dt::deltatron::~deltatron() noexcept {}

void dt::deltatron::run() const {}
