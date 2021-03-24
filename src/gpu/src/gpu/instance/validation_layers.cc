#include <dt/gpu/instance/validation_layers.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>

#include <sstream>
#include <string>
#include <vector>

#include <vulkan/vulkan.h>

dt::vk_validation_layers::vk_validation_layers(cmd const& c, fs const& f)
: _vk_log_directory(f.root().mkdir("log").cd("log")),
  _validation_layers(_get_validation_layers(c)),
  _enabled_validation_layer_names(_get_enabled_validation_layer_names(c)) {}

dt::vk_validation_layers::~vk_validation_layers() noexcept {}

std::vector<VkLayerProperties> dt::vk_validation_layers::_get_validation_layers(cmd const& c) const {
  auto layer_count = std::uint32_t{};
  vkEnumerateInstanceLayerProperties(&layer_count, nullptr);

  auto validation_layers = std::vector<VkLayerProperties>(layer_count);
  vkEnumerateInstanceLayerProperties(&layer_count, validation_layers.data());

  if (c.arg_passed(flag::print_vulkan_layers_supported))
    throw termflag_passed(_vulkan_layer_support_str(validation_layers));

  return validation_layers;
}

std::string dt::vk_validation_layers::_vulkan_layer_support_str(std::vector<VkLayerProperties> const& validation_layers) const noexcept {
  auto layer_support_stream = std::stringstream{};

  for (auto const& validation_layer : validation_layers)
    layer_support_stream << validation_layer.layerName  << std::endl << validation_layer.description << std::endl << std::endl;

  return layer_support_stream.str();
}

std::vector<char const*> dt::vk_validation_layers::_get_enabled_validation_layer_names(cmd const& c) const noexcept {
  // auto enabled_layer_names = std::vector<char const*>(_validation_layers.size());
  //
  // auto layer_index = std::uint32_t{};
  // for (auto const& layer : _validation_layers)
  //   enabled_layer_names[layer_index++] = layer.layerName;

  auto const enabled_layer_names = std::vector<char const*>{"VK_LAYER_KHRONOS_validation"};

  return enabled_layer_names;
}
