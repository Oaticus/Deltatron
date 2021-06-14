#pragma once

#include <dt/render/config.hh>

#include <string>

#include <vulkan/vulkan.h>

namespace dt {

class gpu_vk_instance final {
  std::string          const _app_name;
  std::string          const _engine_name;
  VkApplicationInfo    const _app_info;
  VkInstanceCreateInfo const _create_info;
  VkInstance           const _instance;

public:
  gpu_vk_instance(render_config const&);

  ~gpu_vk_instance() noexcept;

  constexpr auto const& instance() const noexcept { return _instance; }

private:
  auto _create_app_info(render_config const&)    const noexcept -> VkApplicationInfo;
  auto _create_create_info(render_config const&) const noexcept -> VkInstanceCreateInfo;
  auto _create_instance()                        const          -> VkInstance;
};

}
