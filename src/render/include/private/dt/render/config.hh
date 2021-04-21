#pragma once

#include <dt/cmd.hh>
#include <dt/fs.hh>
#include <dt/json.hh>


namespace dt {

class render_config final {
  struct _render_config_values final {
    int physical_device_index;
    int vulkan_version_major;
    int vulkan_version_minor;
  };

  directory             const _config_directory;
  file                  const _config_file;
  json                        _config_data;
  _render_config_values       _config_values;


public:
  render_config(cmd const&, fs const& f);

  render_config(render_config&) = delete;

  render_config(render_config&&) = delete;

  ~render_config() noexcept;

  render_config operator=(render_config&) = delete;

  render_config& operator=(render_config&&) = delete;

  constexpr auto physical_device_index() const noexcept { return _config_values.physical_device_index; }

  constexpr auto vulkan_version_major() const noexcept { return _config_values.vulkan_version_major; }

  constexpr auto vulkan_version_minor() const noexcept { return _config_values.vulkan_version_minor; }

  constexpr render_config& physical_device_index(int index) noexcept {
    _config_values.physical_device_index = index;
    return *this;
  }

  constexpr render_config& vulkan_version_major(int const version_major) noexcept {
    _config_values.vulkan_version_major = version_major;
    return *this;
  }

  constexpr render_config& vulkan_version_minor(int const version_minor) noexcept {
    _config_values.vulkan_version_minor = version_minor;
    return *this;
  }

private:
  _render_config_values _get_config_values() const;

  void _write_default_data() const;
};

}
