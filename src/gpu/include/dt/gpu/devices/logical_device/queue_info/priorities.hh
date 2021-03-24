#pragma once

#include <vector>

namespace dt {

class vk_device_queue_priorities final {
  std::vector<float> const _priorities;

public:
  vk_device_queue_priorities(std::uint32_t const queue_count) noexcept;

  ~vk_device_queue_priorities() noexcept;

  constexpr auto const& priorities() const noexcept { return _priorities; }

private:
  std::vector<float> _create_priorities(std::uint32_t const queue_count) const noexcept;
};

}
