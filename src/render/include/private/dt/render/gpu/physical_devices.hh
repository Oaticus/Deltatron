#pragma once

#include <vector>

#include <vulkan/vulkan.h>

#include <cstdint> // std::uint32_t

namespace dt {

class gpu_vk_physical_devices final {
  std::vector<VkPhysicalDevice>           const _devices;
  std::vector<VkPhysicalDeviceProperties> const _device_properties;

public:
  gpu_vk_physical_devices(VkInstance const& instance);

  ~gpu_vk_physical_devices() noexcept;

  constexpr auto const& device_list() const noexcept { return _devices; }

  constexpr auto const& device_properties_list() const noexcept { return _device_properties; }

private:
  std::vector<VkPhysicalDevice> _get_physical_devices(VkInstance const& instance) const;

  std::uint32_t _get_physical_device_count(VkInstance const& instance) const;

  std::vector<VkPhysicalDeviceProperties> _get_physical_device_properties() const noexcept;
};

}
