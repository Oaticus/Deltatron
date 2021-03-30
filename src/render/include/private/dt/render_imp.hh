#pragma once

#include <dt/render/gpu.hh>

namespace dt {

class render_imp final {
  gpu const _gpu;

public:
  render_imp()
  : _gpu() {}
};

}
