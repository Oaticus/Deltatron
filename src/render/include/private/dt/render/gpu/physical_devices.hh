#pragma once

#include <dt/render/config.hh>

#include <dt/render/gpu/util/result_to_string.hh>
#include <dt/render/error.hh>

#include <algorithm> // max_element
#include <vector>

#include <vulkan/vulkan.h>

namespace dt {

class gpu_vk_physical_devices final {
  std::vector<VkPhysicalDevice>           const  _physical_devices;
  std::vector<VkPhysicalDeviceProperties> const  _physical_device_properties;
  std::uint32_t                           const  _chosen_physical_device_idx;

public:
  gpu_vk_physical_devices(render_config& config, VkInstance const& instance)
  : _physical_devices(_get_physical_devices(instance)),
    _physical_device_properties(_get_physical_device_properties()),
    _chosen_physical_device_idx(_choose_physical_device(config)) {}

  constexpr auto const& view() const noexcept { return _physical_devices; }

  std::vector<VkPhysicalDevice> _get_physical_devices(VkInstance const& instance) const {
    auto count            = _get_physical_device_count(instance);
    auto physical_devices = std::vector<VkPhysicalDevice>(count);

    if (VkResult const result = vkEnumeratePhysicalDevices(instance, &count, physical_devices.data()); result != VK_SUCCESS)
      throw render_error("could not obtain physical device list: " + vk_result_to_string(result));

    return physical_devices;
  }

  std::uint32_t _get_physical_device_count(VkInstance const& instance) const {
    auto count = std::uint32_t{};

    if (VkResult const result = vkEnumeratePhysicalDevices(instance, &count, nullptr); result != VK_SUCCESS)
      throw render_error("could not obtain physical device count: " + vk_result_to_string(result));

    if (count == 0)
      throw render_error("could not find physical device with vulkan support");

    return count;
  }

  std::vector<VkPhysicalDeviceProperties> _get_physical_device_properties() const noexcept {
    auto physical_device_properties = std::vector<VkPhysicalDeviceProperties>(_physical_devices.size());

    auto current_idx = std::uint32_t{};
    for (auto const& physical_device : _physical_devices)
      vkGetPhysicalDeviceProperties(physical_device, physical_device_properties.data() + current_idx++);

    return physical_device_properties;
  }

  std::uint32_t _choose_physical_device(render_config& config) {
    if (int const user_index = config.physical_device_index(); user_index != 0) {
      if (user_index >= _physical_devices.size())
        throw render_error("device index provided by config file is out of range");

      return static_cast<std::uint32_t>(user_index);
    }

    auto device_scores = std::vector<std::uint32_t>(_physical_devices.size());
    auto current_idx   = std::uint32_t{};

    for (auto const& properties : _physical_device_properties) {
      switch (properties.deviceType) {
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:   device_scores[current_idx] += 9; break;
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: device_scores[current_idx] += 7; break;
        case VK_PHYSICAL_DEVICE_TYPE_CPU:            device_scores[current_idx] += 5; break;
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:    device_scores[current_idx] += 3; break;
        case VK_PHYSICAL_DEVICE_TYPE_OTHER:          device_scores[current_idx] += 1; break;
        default:                                     device_scores[current_idx] += 0;
      }

      ++current_idx;
    }

    auto const chosen_index = *std::max_element(device_scores.begin(), device_scores.end());

    config.physical_device_index(static_cast<int>(chosen_index));

    return chosen_index;
  }

};

}
