#include <dt/render/gpu/instance.hh>

#include <dt/render/error.hh>
#include <dt/render/config.hh>
#include <dt/render/gpu/util/result_to_string.hh>

#include <string>

#include <vulkan/vulkan.h>

dt::gpu_vk_instance::gpu_vk_instance(render_config const& config)
: _app_name("Deltatron"),
  _engine_name("delta_engine"),
  _app_info(_create_app_info(config)),
  _create_info(_create_create_info(config)),
  _instance(_create_instance()) {}

dt::gpu_vk_instance::~gpu_vk_instance() noexcept {
  if (_instance != nullptr)
    vkDestroyInstance(_instance, nullptr);
}

VkApplicationInfo dt::gpu_vk_instance::_create_app_info(render_config const&) const noexcept {
  auto app_info = VkApplicationInfo{};

  app_info.sType              = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  app_info.pApplicationName   = _app_name.c_str();
  app_info.applicationVersion = 0;                  // TODO: convert project version to value consumable by VkApplicationInfo::applicationVersion
  app_info.pEngineName        = _engine_name.c_str();
  app_info.engineVersion      = 0;                  // See previous comment regarding VkApplicationInfo::applicationVersion
  app_info.apiVersion         = VK_API_VERSION_1_0; // TODO: Eventually support higher versions of vulkan dynamically

  return app_info;
}

VkInstanceCreateInfo dt::gpu_vk_instance::_create_create_info(render_config const&) const noexcept {
  auto create_info = VkInstanceCreateInfo{};

  create_info.sType                   = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  create_info.pApplicationInfo        = &_app_info;
  create_info.enabledExtensionCount   = 0;       // TODO: Eventually support dynamic extension loading
  create_info.ppEnabledExtensionNames = nullptr;
  create_info.enabledLayerCount       = 0;       // TODO: Eventually support dynamic layer loading
  create_info.ppEnabledLayerNames     = nullptr;

  return create_info;
}

VkInstance dt::gpu_vk_instance::_create_instance() const {
  auto instance = VkInstance{};

  if (VkResult const result = vkCreateInstance(&_create_info, nullptr, &instance); result != VK_SUCCESS)
    throw render_error("could not create vulkan instance: " + vk_result_to_string(result));

  return instance;
}
