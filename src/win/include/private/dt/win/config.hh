#pragma once

#include <dt/cmd.hh>
#include <dt/fs.hh>

#include <string>

namespace dt {

class win_config final {
  std::string _window_name;
  bool        _window_is_fullscreen;
  int         _window_width;
  int         _window_height;

public:
  win_config(cmd const&, fs const&);

  ~win_config() noexcept;

  constexpr std::string const& window_name() const noexcept { return _window_name; }

  constexpr bool window_is_fullscreen() const noexcept { return _window_is_fullscreen; }

  constexpr int window_width() const noexcept { return _window_width; }

  constexpr int window_height() const noexcept { return _window_height; }

  constexpr win_config& set_fullscreen() noexcept {
    _window_is_fullscreen = true;

    return *this;
  }

  constexpr win_config& unset_fullscreen() noexcept {
    _window_is_fullscreen = false;

    return *this;
  }

  constexpr win_config& set_window_width(int const width) noexcept {
    _window_width = width;

    return *this;
  }

  constexpr win_config& set_window_height(int const height) noexcept {
    _window_height = height;

    return *this;
  }

private:
  void _write_default_data(std::string const& config_file_name, directory const& config_directory) const;
};

}
