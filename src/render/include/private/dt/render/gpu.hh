#pragma once

#include <dt/render/gpu/instance.hh>
#include <dt/render/gpu/physical_devices.hh>

namespace dt {

class gpu final {
  gpu_vk_instance         const _instance;
  gpu_vk_physical_devices const _physical_devices;

public:
  gpu()
  : _instance(),
    _physical_devices(_instance.instance()) {}
};

}
