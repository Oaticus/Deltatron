#include <dt/deltatron.hh>

#include <thread>

dt::deltatron::deltatron(int const ac, char const* const* const av, char const* const* const ep)
: _cmd(ac, av, ep),
  _fs(_cmd),
  _render(_cmd, _fs),
  _win(_cmd, _fs) {}

dt::deltatron::~deltatron() noexcept {}

void dt::deltatron::run() const {
  std::thread([this] { _win.run(); }).join();
}
