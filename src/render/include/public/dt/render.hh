#pragma once

#include <dt/command.hh>
#include <dt/filesystem.hh>

#include <memory>

namespace dt {

class render_imp;

class render final {
  std::unique_ptr<render_imp> const _render;

public:
  render(command const&, filesystem const&);

  ~render() noexcept;
};

}
