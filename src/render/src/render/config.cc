#include <dt/render/config.hh>

#include <dt/command.hh>
#include <dt/filesystem.hh>

dt::render_config::render_config(command const&, filesystem const& fs)
: _config_directory(fs.root().cd("cfg")),
  _config_file(_config_directory.load_file("render.json")),
  _config_data(_config_file.name(), _config_file.data()),
  _config_values(_get_config_values()) {}

dt::render_config::~render_config() noexcept {}

std::vector<std::string::pointer> dt::render_config::vulkan_enabled_extension_names() noexcept {
  auto enabled_extension_names = std::vector<std::string::pointer>(_config_values.enabled_extension_names.size(), nullptr);
  auto index                   = std::vector<std::string>::size_type{};

  for (auto& name_str : _config_values.enabled_extension_names)
    enabled_extension_names.data()[index++] = name_str.data();

  return enabled_extension_names;
}

std::vector<std::string::pointer> dt::render_config::vulkan_enabled_layer_names() noexcept {
  auto enabled_layer_names = std::vector<std::string::pointer>(_config_values.enabled_layer_names.size(), nullptr);
  auto index               = std::vector<std::string>::size_type{};

  for (auto& name_str : _config_values.enabled_layer_names)
    enabled_layer_names.data()[index++] = name_str.data();

  return enabled_layer_names;
}

dt::render_config::_render_config_values dt::render_config::_get_config_values() const {
  auto config_values = _render_config_values{};

  if (auto const root = _config_data.root(); root.is_object()) {
    if (auto const opt_pdev_idx = root.integer_at("physical_device_index"); opt_pdev_idx)
      config_values.physical_device_index = static_cast<std::uint32_t>(*opt_pdev_idx);

    if (auto const opt_vk_ver_major = root.integer_at("vulkan_version_major"); opt_vk_ver_major)
      config_values.version_major = static_cast<std::uint32_t>(*opt_vk_ver_major);

    if (auto const opt_vk_ver_minor = root.integer_at("vulkan_version_minor"); opt_vk_ver_minor)
      config_values.version_minor = static_cast<std::uint32_t>(*opt_vk_ver_minor);

  } else _write_default_data();

  return config_values;
}

void dt::render_config::_write_default_data() const {
  constexpr char const* const default_data =
    "// Deltatron default render configuration\n"
    "{\n"
    "  \"physical_device_index\": -1,\n"
    "  \"vulkan_version_major\": 1,\n"
    "  \"vulkan_version_minor\": 0\n"
    "}\n";

  _config_directory.write_file("render.json", default_data);
}
