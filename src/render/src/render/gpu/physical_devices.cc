#include <dt/render/gpu/physical_devices.hh>

#include <dt/render/error.hh>
#include <dt/render/gpu/util/result_to_string.hh>

#include <vector>

#include <vulkan/vulkan.h>

#include <cstdint> // std::uint32_t

dt::gpu_vk_physical_devices::gpu_vk_physical_devices(VkInstance const& instance)
: _devices(_get_physical_devices(instance)),
  _device_properties(_get_physical_device_properties()) {}

dt::gpu_vk_physical_devices::~gpu_vk_physical_devices() noexcept {}

std::vector<VkPhysicalDevice> dt::gpu_vk_physical_devices::_get_physical_devices(VkInstance const& instance) const {
  auto count            = _get_physical_device_count(instance);
  auto physical_devices = std::vector<VkPhysicalDevice>(count);

  if (VkResult const result = vkEnumeratePhysicalDevices(instance, &count, physical_devices.data()); result != VK_SUCCESS)
    throw render_error("could not obtain physical device list: " + vk_result_to_string(result));

  return physical_devices;
}

std::uint32_t dt::gpu_vk_physical_devices::_get_physical_device_count(VkInstance const& instance) const {
  auto count = std::uint32_t{};

  if (VkResult const result = vkEnumeratePhysicalDevices(instance, &count, nullptr); result != VK_SUCCESS)
    throw render_error("could not obtain physical device count: " + vk_result_to_string(result));

  if (count == 0)
    throw render_error("could not find physical device with vulkan support");

  return count;
}

std::vector<VkPhysicalDeviceProperties> dt::gpu_vk_physical_devices::_get_physical_device_properties() const noexcept {
  auto physical_device_properties = std::vector<VkPhysicalDeviceProperties>(_devices.size());

  auto current_idx = std::uint32_t{};
  for (auto const& device : _devices)
    vkGetPhysicalDeviceProperties(device, physical_device_properties.data() + current_idx++);

  return physical_device_properties;
}
