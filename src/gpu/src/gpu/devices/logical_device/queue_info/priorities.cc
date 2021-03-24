#include <dt/gpu/devices/logical_device/queue_info/priorities.hh>

dt::vk_device_queue_priorities::vk_device_queue_priorities(std::uint32_t const queue_count) noexcept
: _priorities(_create_priorities(queue_count)) {}

dt::vk_device_queue_priorities::~vk_device_queue_priorities() noexcept {}

std::vector<float> dt::vk_device_queue_priorities::_create_priorities(std::uint32_t const queue_count) const noexcept {
  auto priorities       = std::vector<float>(queue_count);
  auto current_priority = float{1.0f};

  for (auto& priority : priorities)
    priority = (current_priority -= .01f);

  return priorities;
}
