#pragma once

#include <dt/gpu/devices/logical_device/queue_info/requested_queues.hh>
#include <dt/gpu/devices/logical_device/queue_info/priorities.hh>

#include <dt/gpu/devices/physical_device.hh>

#include <vector>

#include <cstdint>

namespace dt {

class vk_device_queue_info final {
  vk_physical_device                      const& _physical_device;
  vk_device_queue_request_list_t          const  _requested_queues;
  std::vector<vk_device_queue_priorities> const  _priorities;
  std::vector<VkDeviceQueueCreateInfo>    const  _queue_create_infos;
  std::vector<VkQueue>                    const  _device_queues;

public:
  vk_device_queue_info(vk_physical_device const& physical_device, vk_device_queue_request_list_t const& requested_queues);

  ~vk_device_queue_info() noexcept;

  constexpr auto const& create_info() const noexcept { return _queue_create_infos; }

private:
  std::vector<vk_device_queue_priorities> _create_priorities() const noexcept;

  std::vector<VkDeviceQueueCreateInfo> _create_queue_create_infos() const noexcept;

};

}
