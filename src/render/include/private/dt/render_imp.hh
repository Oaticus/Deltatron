#pragma once

#include <dt/gpu.hh>
#include <dt/render/device.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>

namespace dt {

class render_imp final {
  gpu           const _gpu;
  render_device const _device;

public:
  render_imp(cmd const& c, fs const& f)
  : _gpu(c, f),
    _device(_gpu, c) {}
};

}
