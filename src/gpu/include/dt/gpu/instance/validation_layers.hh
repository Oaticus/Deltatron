#pragma once

#include <dt/cmd.hh>
#include <dt/fs.hh>

#include <vector>
#include <string>

#include <vulkan/vulkan.h>

namespace dt {

class vk_validation_layers final {
  dt::directory                      const _vk_log_directory;
  std::vector<VkLayerProperties>     const _validation_layers;
  std::vector<char const*>           const _enabled_validation_layer_names;

public:
  vk_validation_layers(cmd const& c, fs const& f);

  ~vk_validation_layers() noexcept;

  constexpr auto const& validation_layers() const noexcept { return _validation_layers; }

  constexpr auto const& enabled_validation_layer_names() const noexcept { return _enabled_validation_layer_names; }

private:
  std::vector<char const*> _get_enabled_validation_layer_names(cmd const&) const noexcept;

  std::vector<VkLayerProperties> _get_validation_layers(cmd const&) const;

  std::string _vulkan_layer_support_str(std::vector<VkLayerProperties> const&) const noexcept;
};

}
