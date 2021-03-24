#pragma once

#include <vector>

namespace dt {

class vk_device_queue_info_requested_queues final {
  std::uint32_t const _queue_family_index;
  std::uint32_t const _queue_count;

public:
  constexpr vk_device_queue_info_requested_queues(std::uint32_t queue_family_index, std::uint32_t queue_count) noexcept
  : _queue_family_index(queue_family_index),
    _queue_count(queue_count) {}

  constexpr std::uint32_t queue_family_index() const noexcept { return _queue_family_index; }

  constexpr std::uint32_t queue_count() const noexcept { return _queue_count; }
};

using vk_device_queue_request_list_t = std::vector<vk_device_queue_info_requested_queues>;

}
