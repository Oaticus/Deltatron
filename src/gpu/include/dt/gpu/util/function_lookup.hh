#pragma once

#include <dt/gpu/error.hh>

#include <vulkan/vulkan.h>

namespace dt {

template <typename FunctionType>
FunctionType vk_function_lookup(VkInstance const& instance, char const* function_name) {
  if (auto const function = FunctionType(vkGetInstanceProcAddr(instance, function_name)); function)
    return function;

  throw gpu_error(std::string("could not find function ") + "\"" + function_name + "\"");
}

}
