#include <dt/gpu/devices/physical_device.hh>

#include <dt/gpu/error.hh>

#include <vector>

#include <vulkan/vulkan.h>

dt::vk_physical_device::vk_physical_device() noexcept
: _device(),
  _properties(),
  _features(),
  _queue_family_properties() {}

dt::vk_physical_device::vk_physical_device(VkPhysicalDevice const device) noexcept
: _device(device),
  _properties(_get_properties()),
  _features(_get_features()),
  _queue_family_properties(_get_queue_families()) {}

dt::vk_physical_device::~vk_physical_device() noexcept {}

VkPhysicalDeviceProperties dt::vk_physical_device::_get_properties() const noexcept {
  VkPhysicalDeviceProperties properties{};

  vkGetPhysicalDeviceProperties(_device, &properties);

  return properties;
}

VkPhysicalDeviceFeatures dt::vk_physical_device::_get_features() const noexcept {
  VkPhysicalDeviceFeatures features{};

  vkGetPhysicalDeviceFeatures(_device, &features);

  return features;
}

std::vector<VkQueueFamilyProperties> dt::vk_physical_device::_get_queue_families() const noexcept {
  std::uint32_t count;
  vkGetPhysicalDeviceQueueFamilyProperties(_device, &count, nullptr);

  std::vector<VkQueueFamilyProperties> queue_properties(count);
  vkGetPhysicalDeviceQueueFamilyProperties(_device, &count, queue_properties.data());

  return queue_properties;
}
