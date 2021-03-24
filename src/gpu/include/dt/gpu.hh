#pragma once

#include <dt/gpu/instance.hh>
#include <dt/gpu/devices.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>
#include <dt/log.hh>

#include <vector>

namespace dt {

class gpu final {
  log         const _log;
  vk_instance const _instance;
  vk_devices  const _devices;

public:
  gpu(cmd const& c, fs const& f);

  ~gpu() noexcept;

  constexpr auto const& physical_devices() const noexcept { return _devices.physical_devices(); }

  vk_logical_device create_logical_device(vk_physical_device const&, vk_device_queue_request_list_t const&) const;
};

}
