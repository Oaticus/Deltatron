#include <dt/deltatron.hh>
#include <dt/json.hh>

#include <iostream>

dt::deltatron::deltatron(int const ac, char const* const* const av, char const* const* const ep)
: _cmd(ac, av, ep),
  _fs(_cmd),
  _render(_cmd, _fs) {}

dt::deltatron::~deltatron() noexcept {}

void dt::deltatron::run() const {}
