#pragma once

#include <dt/render/gpu/instance.hh>
#include <dt/render/gpu/physical_devices.hh>

#include <dt/render/config.hh>

namespace dt {

class gpu final {
  gpu_vk_instance         const _instance;
  gpu_vk_physical_devices const _physical_devices;

public:
  gpu(render_config& config)
  : _instance(config),
    _physical_devices(config, _instance.instance()) {}
};

}
