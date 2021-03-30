#pragma once

#include <memory>

namespace dt {

class render_imp;

class render final {
  std::unique_ptr<render_imp> const _render;

public:
  render();

  ~render() noexcept;
};

}
