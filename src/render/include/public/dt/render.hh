#pragma once

#include <dt/cmd.hh>
#include <dt/fs.hh>

#include <memory>

namespace dt {

class render_imp;

class render final {
  std::unique_ptr<render_imp> const _render;

public:
  render(cmd const&, fs const&);

  ~render() noexcept;
};

}
