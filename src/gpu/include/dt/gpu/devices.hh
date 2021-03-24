#pragma once

#include <dt/gpu/devices/physical_device.hh>
#include <dt/gpu/devices/logical_device.hh>
#include <dt/gpu/instance.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>

#include <algorithm>
#include <vector>

namespace dt {

class vk_devices final {
  std::vector<vk_physical_device> const _physical_devices;

public:
  vk_devices(vk_instance const& instance, cmd const&, fs const&);

  ~vk_devices() noexcept;

  vk_logical_device create_device(vk_physical_device const& physical_device, vk_device_queue_request_list_t const& requested_queues) const;

  constexpr auto const& physical_devices() const noexcept { return _physical_devices; }

private:
  std::vector<vk_physical_device> _find_physical_devices(VkInstance const&) const;
};

}
