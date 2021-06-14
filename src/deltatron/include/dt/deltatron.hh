#pragma once

#include <dt/command.hh>
#include <dt/filesystem.hh>
#include <dt/window.hh>
#include <dt/render.hh>

namespace dt {

class deltatron final {
  command    const _command;
  filesystem const _filesystem;
  window     const _window;
  render     const _render;

public:
  deltatron(command::initializer const);

  ~deltatron() noexcept;

  int run() const;
};

}
