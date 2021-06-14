#pragma once

#include <dt/command.hh>
#include <dt/filesystem.hh>

#include <string>

namespace dt {

class window_config final {
  bool _window_is_fullscreen;
  int  _window_width;
  int  _window_height;

public:
  window_config(command const& cmd, filesystem const& fs);

  ~window_config() noexcept;

  constexpr bool window_is_fullscreen() const noexcept { return _window_is_fullscreen; }

  constexpr int window_width() const noexcept { return _window_width; }

  constexpr int window_height() const noexcept { return _window_height; }

private:
  void _write_default_data(std::string const& config_file_name, directory const& config_directory) const;
};

}
