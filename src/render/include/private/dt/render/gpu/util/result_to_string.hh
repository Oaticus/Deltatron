#pragma once

#include <string>

#include <vulkan/vulkan.h>

namespace dt {

std::string vk_result_to_string(VkResult const& result) noexcept;

}
