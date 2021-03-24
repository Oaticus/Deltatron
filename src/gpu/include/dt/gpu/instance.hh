#pragma once

#include <dt/gpu/instance/validation_layers.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>
#include <dt/log.hh>

#include <dt/gpu/error.hh>

#include <optional>
#include <string>

#include <vulkan/vulkan.h>

namespace dt {

class vk_instance final {
  VkApplicationInfo    const  _app_info;
  vk_validation_layers const  _validation_layers;
  VkInstanceCreateInfo const  _create_info;
  VkInstance           const  _instance;

public:
  vk_instance(cmd const&, fs const&);

  ~vk_instance() noexcept;

  constexpr auto instance()         const noexcept -> VkInstance                  { return _instance;    }
  constexpr auto application_info() const noexcept -> VkApplicationInfo    const& { return _app_info;    }
  constexpr auto create_info()      const noexcept -> VkInstanceCreateInfo const& { return _create_info; }

private:
  constexpr VkApplicationInfo _create_app_info() const noexcept {
    VkApplicationInfo app_info{};

    app_info.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    app_info.pApplicationName   = "deltatron";
    app_info.applicationVersion = VK_MAKE_VERSION(1, 2, 0);
    app_info.pEngineName        = "delta_engine";
    app_info.engineVersion      = VK_MAKE_VERSION(1, 2, 0);
    app_info.apiVersion         = VK_API_VERSION_1_0;

    return app_info;
  }

  std::vector<VkLayerProperties> _get_validation_layers(cmd const&) const;

  std::string _vulkan_layer_support_str(std::vector<VkLayerProperties> const&) const noexcept;

  VkInstanceCreateInfo _create_create_info() const noexcept;

  std::vector<char const*> _enabled_validation_layer_names(cmd const&) const noexcept;

  VkInstance _create_instance() const;

  std::string _get_result_str(VkResult const&) const noexcept;
};

}
