#pragma once

#include <dt/gpu.hh>
#include <dt/cmd.hh>

#include <algorithm>
#include <sstream>
#include <string>
#include <vector>

namespace dt {

class render_device final {
  vk_physical_device             const& _physical_device;
  vk_device_queue_request_list_t const  _requested_queues;
  vk_logical_device              const  _device;

public:
  render_device(gpu const& g, cmd const& c)
  : _physical_device(_choose_physical_device(g, c)),
    _requested_queues(_choose_device_queues()),
    _device(g.create_logical_device(_physical_device, _requested_queues)) {}

private:
  vk_physical_device const& _choose_physical_device(gpu const& g, cmd const& c) const {
    auto const& physical_devices = g.physical_devices();

    auto scores = std::vector<std::uint8_t>(physical_devices.size());
    auto index = std::uint32_t{};
    for (auto const& physical_device : physical_devices) {
      switch (physical_device.properties().deviceType) {
        case VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU:   scores[index] += 9; break;
        case VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU: scores[index] += 7; break;
        case VK_PHYSICAL_DEVICE_TYPE_CPU:            scores[index] += 5; break;
        case VK_PHYSICAL_DEVICE_TYPE_VIRTUAL_GPU:    scores[index] += 3; break;
        case VK_PHYSICAL_DEVICE_TYPE_OTHER:          scores[index] += 1; break;
        default:                                     scores[index] += 0;
      }

      ++index;
    }

    auto const max_score_idx = std::max_element(scores.begin(), scores.end(), [](auto&& max, auto&& oth) { return max < oth; });
    auto const chosen_physical_device_idx = max_score_idx - scores.begin();

    if (c.arg_passed(flag::print_gpu_info))
      throw termflag_passed(_device_info_str(physical_devices[chosen_physical_device_idx]));

    return physical_devices[chosen_physical_device_idx];
  }

  vk_device_queue_request_list_t _choose_device_queues() const noexcept {
    auto device_queue_request_list = vk_device_queue_request_list_t{};

    auto const& queue_families = _physical_device.queue_family_properties();

    auto queue_family_index = std::uint32_t{};
    for (auto const& queue_family : queue_families) {
      if (queue_family.queueFlags | VK_QUEUE_GRAPHICS_BIT) {
        device_queue_request_list.push_back({queue_family_index, 1});
        break;
      }

      ++queue_family_index;
    }

    return device_queue_request_list;
  }

  std::string _device_info_str(vk_physical_device const& physical_device) const noexcept {
    auto physical_device_info_stream = std::stringstream{};

    physical_device_info_stream << "Name: " << physical_device.properties().deviceName << std::endl;

    return physical_device_info_stream.str();
  }
};

}
