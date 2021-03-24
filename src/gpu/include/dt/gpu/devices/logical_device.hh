#pragma once

#include <dt/gpu/devices/logical_device/queue_info.hh>
#include <dt/gpu/devices/physical_device.hh>

#include <vector>

namespace dt {

class vk_logical_device final {
  vk_physical_device   const& _physical_device;
  vk_device_queue_info const  _device_queue_info;
  VkDeviceCreateInfo   const  _create_info;
  VkDevice             const  _device;
  std::vector<VkQueue> const  _queues;

public:
  vk_logical_device(vk_physical_device const& physical_device, vk_device_queue_request_list_t const& requested_queues);

  ~vk_logical_device() noexcept;

  constexpr auto const& queues() const noexcept { return _queues; }

private:
  VkDeviceCreateInfo _create_create_info() const noexcept;

  VkDevice _create_device() const;

  std::vector<VkQueue> _get_queues() const noexcept;
};

}
