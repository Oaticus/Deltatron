#pragma once

#include <dt/cmd.hh>
#include <dt/fs.hh>
#include <dt/render.hh>
#include <dt/win.hh>

namespace dt {

class deltatron final {
  cmd    const _cmd;
  fs     const _fs;
  render const _render;
  win    const _win;

public:
  deltatron(int const ac, char const* const* const av, char const* const* const ep);

  ~deltatron() noexcept;

  void run() const;
};

}
