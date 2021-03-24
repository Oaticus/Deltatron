#include <dt/gpu/devices/logical_device/queue_info.hh>

dt::vk_device_queue_info::vk_device_queue_info(vk_physical_device const& physical_device, vk_device_queue_request_list_t const& requested_queues)
: _physical_device(physical_device),
  _requested_queues(requested_queues),
  _priorities(_create_priorities()),
  _queue_create_infos(_create_queue_create_infos()) {}

dt::vk_device_queue_info::~vk_device_queue_info() noexcept {}

std::vector<dt::vk_device_queue_priorities> dt::vk_device_queue_info::_create_priorities() const noexcept {
  auto priorities = std::vector<vk_device_queue_priorities>{};

  for (auto const& requested_family : _requested_queues)
    priorities.push_back(requested_family.queue_count());

  priorities.shrink_to_fit();

  return priorities;
}

std::vector<VkDeviceQueueCreateInfo> dt::vk_device_queue_info::_create_queue_create_infos() const noexcept {
  auto queue_create_infos = std::vector<VkDeviceQueueCreateInfo>(_requested_queues.size());

  std::uint32_t index{};
  for (auto& queue_create_info : queue_create_infos) {
    queue_create_info.sType            = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
    queue_create_info.queueFamilyIndex = _requested_queues[index].queue_family_index();
    queue_create_info.queueCount       = _requested_queues[index].queue_count();
    queue_create_info.pQueuePriorities = _priorities[index].priorities().data();

    ++index;
  }

  return queue_create_infos;
}
