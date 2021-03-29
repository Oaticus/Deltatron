#include <dt/win/config.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>
#include <dt/json.hh>



dt::win_config::win_config(cmd const&, fs const& f)
: _window_name("Deltatron"),
  _window_is_fullscreen(false),
  _window_width(800),
  _window_height(600)
{
  auto const config_directory = f.root().cd("cfg");
  auto const config_file      = config_directory.load_file("win.json");
  auto const config_data      = json(config_file.name(), config_file.data());

  if (auto const root = config_data.root(); root.is_object()) {
    if (auto const name = root.string_at("name"); name)
      _window_name = *name;

    if (auto const is_fullscreen = root.bool_at("fullscreen"); is_fullscreen)
      _window_is_fullscreen = *is_fullscreen;

    if (auto const width = root.integer_at("width"); width)
      _window_width = *width;

    if (auto const height = root.integer_at("height"); height)
      _window_height = *height;

  } else _write_default_data("win.json", config_directory);
}

dt::win_config::~win_config() noexcept {}

void dt::win_config::_write_default_data(std::string const& config_file_name, directory const& config_directory) const {
  static char const* const default_data =
    "{\n"
    "  \"name\" : \"Deltatron\",\n"
    "  \"fullscreen\" : false,\n"
    "  \"width\" : 800,\n"
    "  \"height\" : 600\n"
    "}\n";

  config_directory.write_file(config_file_name, default_data);
}
