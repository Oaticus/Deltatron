#include <dt/gpu/devices.hh>

#include <dt/gpu/error.hh>
#include <dt/gpu/instance.hh>
#include <dt/cmd.hh>
#include <dt/fs.hh>

#include <vector>

dt::vk_devices::vk_devices(vk_instance const& instance, cmd const&, fs const&)
: _physical_devices(_find_physical_devices(instance.instance())) {}

dt::vk_devices::~vk_devices() noexcept {}

dt::vk_logical_device dt::vk_devices::create_device(vk_physical_device const& physical_device, vk_device_queue_request_list_t const& requested_queues) const
{ return vk_logical_device(physical_device, requested_queues); }

std::vector<dt::vk_physical_device> dt::vk_devices::_find_physical_devices(VkInstance const& instance) const {
  auto physical_device_count = std::uint32_t{};
  vkEnumeratePhysicalDevices(instance, &physical_device_count, nullptr);
  if (physical_device_count == 0) throw gpu_error("no physical device with vulkan support found");

  auto raw_physical_devices = std::vector<VkPhysicalDevice>(physical_device_count);
  vkEnumeratePhysicalDevices(instance, &physical_device_count, raw_physical_devices.data());

  auto physical_devices = std::vector<vk_physical_device>{};
  for (auto const& raw_device : raw_physical_devices)
    physical_devices.push_back(raw_device);

  physical_devices.shrink_to_fit();

  return physical_devices;
}
