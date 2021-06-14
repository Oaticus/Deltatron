#pragma once

#include <dt/command.hh>
#include <dt/filesystem.hh>
#include <dt/json.hh>

#include <string>
#include <vector>

#include <cstdint> // std::uint32_t

namespace dt {

class render_config final {
  struct _render_config_values final {
    std::uint32_t            physical_device_index;
    std::uint32_t            version_major;
    std::uint32_t            version_minor;
    std::vector<std::string> enabled_extension_names;
    std::vector<std::string> enabled_layer_names;
  };

  directory             const _config_directory;
  file                  const _config_file;
  json                        _config_data;
  _render_config_values       _config_values;

public:
  render_config(command const&, filesystem const&);

  render_config(render_config&) = delete;

  render_config(render_config&&) = delete;

  ~render_config() noexcept;

  render_config operator=(render_config&) = delete;

  render_config& operator=(render_config&&) = delete;

  constexpr auto physical_device_index() const noexcept { return _config_values.physical_device_index; }

  constexpr auto vulkan_version_major() const noexcept { return _config_values.version_major; }

  constexpr auto vulkan_version_minor() const noexcept { return _config_values.version_minor; }

  std::vector<std::string::pointer> vulkan_enabled_extension_names() noexcept;

  std::vector<std::string::pointer> vulkan_enabled_layer_names() noexcept;

private:
  _render_config_values _get_config_values() const;

  void _write_default_data() const;
};

}
