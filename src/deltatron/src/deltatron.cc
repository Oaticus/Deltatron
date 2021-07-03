#include <dt/deltatron.hh>

#include <dt/yaml.hh>

#include <dt/math/point.hh>

#include <thread>

#include <cstdlib>

dt::deltatron::deltatron(command::initializer const init)
: _command(init),
  _filesystem(_command),
  _window(_command, _filesystem),
  _render(_command, _filesystem) {}

dt::deltatron::~deltatron() noexcept {}

int dt::deltatron::run() const {
  std::thread([&] { _window.run(); }).join();

  auto stream_a = yaml_stream{};
  auto stream_b = yaml_stream{};

  // auto stream_c = stream_a + stream_b;

  auto xy_a = point_type{}.xyz().zzz().xxx().zyx();

  return EXIT_SUCCESS;
}
