#pragma once

#include <dt/render/gpu.hh>
#include <dt/render/config.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>

namespace dt {

class render_imp final {
  render_config       _config;
  gpu           const _gpu;

public:
  render_imp(cmd const& c, fs const& f)
  : _config(c, f),
    _gpu(_config) {}
};

}
