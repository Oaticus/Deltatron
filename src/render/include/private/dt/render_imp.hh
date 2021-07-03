#pragma once

#include <dt/render/gpu.hh>
#include <dt/render/config.hh>

#include <dt/command.hh>
#include <dt/filesystem.hh>

namespace dt {

class render_imp final {
  render_config       _config;
  gpu           const _gpu;

public:
  render_imp(command const& cmd, filesystem const& fs)
  : _config(cmd, fs),
    _gpu(_config) { }
};

}
