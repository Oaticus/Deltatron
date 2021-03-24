#pragma once

#include <dt/gpu/error.hh>

#include <vector>

#include <vulkan/vulkan.h>

namespace dt {

class vk_physical_device final {
  VkPhysicalDevice                        const _device;
  VkPhysicalDeviceProperties              const _properties;
  VkPhysicalDeviceFeatures                const _features;
  std::vector<VkQueueFamilyProperties>    const _queue_family_properties;

public:
  vk_physical_device() noexcept;

  vk_physical_device(VkPhysicalDevice const device) noexcept;

  ~vk_physical_device() noexcept;

  constexpr auto device()     const noexcept -> VkPhysicalDevice           const& { return _device;     }
  constexpr auto properties() const noexcept -> VkPhysicalDeviceProperties const& { return _properties; }
  constexpr auto features()   const noexcept -> VkPhysicalDeviceFeatures   const& { return _features;   }

  constexpr auto const& queue_family_properties() const noexcept { return _queue_family_properties; }

private:
  VkPhysicalDeviceProperties _get_properties() const noexcept;

  VkPhysicalDeviceFeatures _get_features() const noexcept;

  std::vector<VkQueueFamilyProperties> _get_queue_families() const noexcept;
};

}
