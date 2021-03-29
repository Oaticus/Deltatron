#include <dt/deltatron.hh>

#include <thread>

dt::deltatron::deltatron(int const ac, char const* const* const av, char const* const* const ep)
: _cmd(ac, av, ep),
  _fs(_cmd),
  _win(_cmd, _fs) {}

dt::deltatron::~deltatron() noexcept {}

void dt::deltatron::run() const {
  auto win_thread = std::thread([&] { _win.run(); });

  win_thread.join();
}
