#include <dt/gpu/devices/logical_device.hh>

#include <dt/gpu/devices/physical_device.hh>
#include <dt/gpu/devices/logical_device/queue_info.hh>

dt::vk_logical_device::vk_logical_device(vk_physical_device const& physical_device, vk_device_queue_request_list_t const& requested_queues)
: _physical_device(physical_device),
  _device_queue_info(_physical_device, requested_queues),
  _create_info(_create_create_info()),
  _device(),
  _queues(_get_queues()) {}

dt::vk_logical_device::~vk_logical_device() noexcept { vkDestroyDevice(_device, nullptr); }

VkDeviceCreateInfo dt::vk_logical_device::_create_create_info() const noexcept {
  auto const& queue_create_info = _device_queue_info.create_info();
  auto        create_info       = VkDeviceCreateInfo{};

  create_info.sType                    = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
  create_info.pNext                    = nullptr;
  create_info.flags                    = VkDeviceCreateFlags{};
  create_info.queueCreateInfoCount     = static_cast<std::uint32_t>(queue_create_info.size());
  create_info.pQueueCreateInfos        = queue_create_info.data();
  create_info.enabledLayerCount        = 0;
  create_info.ppEnabledLayerNames      = nullptr;
  create_info.enabledExtensionCount    = 0;
  create_info.ppEnabledExtensionNames  = nullptr;
  create_info.pEnabledFeatures         = nullptr;

  return create_info;
}

VkDevice dt::vk_logical_device::_create_device() const {
  auto device = VkDevice{};

  if (VkResult result = vkCreateDevice(_physical_device.device(), &_create_info, nullptr, &device); result != VK_SUCCESS)
    throw gpu_error("could not create logical device");

  return device;
}

std::vector<VkQueue> dt::vk_logical_device::_get_queues() const noexcept {
  auto queues = std::vector<VkQueue>{};

  auto const& queue_create_infos = _device_queue_info.create_info();

  for (auto const& queue_create_info : queue_create_infos) {
    for (std::uint32_t queue_index{}; queue_index < queue_create_info.queueCount; ++queue_index) {
      auto queue = VkQueue{};
      vkGetDeviceQueue(_device, queue_create_info.queueFamilyIndex, queue_index, &queue);
      queues.push_back(queue);
    }
  }

  return queues;
}
