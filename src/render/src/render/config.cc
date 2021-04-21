#include <dt/render/config.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>

dt::render_config::render_config(cmd const&, fs const& f)
: _config_directory(f.root().cd("cfg")),
  _config_file(_config_directory.load_file("render.json")),
  _config_data(_config_file.name(), _config_file.data()),
  _config_values(_get_config_values()) {}

dt::render_config::~render_config() noexcept {}

dt::render_config::_render_config_values dt::render_config::_get_config_values() const {
  auto config_values = _render_config_values{};

  if (auto const root = _config_data.root(); root.is_object()) {
    if (auto const opt_pdev_idx = root.integer_at("physical_device_index"); opt_pdev_idx)
      config_values.physical_device_index = *opt_pdev_idx;

    if (auto const opt_vk_ver_major = root.integer_at("vulkan_version_major"); opt_vk_ver_major)
      config_values.vulkan_version_major = *opt_vk_ver_major;

    if (auto const opt_vk_ver_minor = root.integer_at("vulkan_version_minor"); opt_vk_ver_minor)
      config_values.vulkan_version_minor = *opt_vk_ver_minor;

  } else _write_default_data();

  return config_values;
}

void dt::render_config::_write_default_data() const {
  constexpr static char const* const default_data =
    "// Deltatron render configuration\n"
    "{\n"
    "  \"physical_device_index\": 0\n"
    "  \"vulkan_version_major\": 0\n"
    "  \"vulkan_version_minor\": 0\n"
    "}";

  _config_directory.write_file("render.json", default_data);
}
