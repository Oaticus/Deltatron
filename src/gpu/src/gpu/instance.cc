#include <dt/gpu/instance.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>

#include <sstream>

dt::vk_instance::vk_instance(cmd const& c, fs const& f)
: _app_info(_create_app_info()),
  _validation_layers(c, f),
  _create_info(_create_create_info()),
  _instance(_create_instance()) {}

dt::vk_instance::~vk_instance() noexcept { vkDestroyInstance(_instance, nullptr); }

VkInstance dt::vk_instance::_create_instance() const {
  auto instance = VkInstance{};

  if (VkResult const result = vkCreateInstance(&_create_info, nullptr, &instance); result != VK_SUCCESS)
    throw gpu_error(std::string("cannot create vulkan instance (" + _get_result_str(result) + ")"));

  return instance;
}

VkInstanceCreateInfo dt::vk_instance::_create_create_info() const noexcept {
  auto create_info = VkInstanceCreateInfo{};

  create_info.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  create_info.pApplicationInfo = &_app_info;

  if (auto const& enabled_names = _validation_layers.enabled_validation_layer_names(); !enabled_names.empty()) {
    create_info.enabledLayerCount   = static_cast<std::uint32_t>(enabled_names.size());
    create_info.ppEnabledLayerNames = enabled_names.data();
  }

  return create_info;
}

std::string dt::vk_instance::_get_result_str(VkResult const& result) const noexcept {
  switch (result) {
    case VK_ERROR_OUT_OF_HOST_MEMORY:    return "out of host memory";
    case VK_ERROR_OUT_OF_DEVICE_MEMORY:  return "out of device memory";
    case VK_ERROR_INITIALIZATION_FAILED: return "initialization failed";
    case VK_ERROR_LAYER_NOT_PRESENT:     return "layer not present";
    case VK_ERROR_EXTENSION_NOT_PRESENT: return "extension not present";
    case VK_ERROR_INCOMPATIBLE_DRIVER:   return "incompatible driver";
    default:                             return "unknown result";
  }
}
