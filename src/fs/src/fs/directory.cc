#include <dt/fs/directory.hh>
#include <dt/fs/error.hh>
#include <dt/fs_imp.hh>

#include <fstream>
#include <optional>
#include <string>

dt::directory::directory(std::string const& directory_path) noexcept
: _path_str(directory_path) {}

dt::directory::~directory() noexcept {}

dt::directory dt::directory::cd(std::string const& directory_name) const {
  if (auto const p = stdfs::path(_path_str) /= directory_name; stdfs::exists(p) && stdfs::is_directory(p))
    return directory(p.string());

  else if (!stdfs::exists(p))
    return stdfs::create_directory(p), directory(p.string());

  else
    throw fs_error(std::string("file entity already bound to directory name (\"") + p.string() + "\")");
}

dt::file dt::directory::load_file(std::string const& file_name, std::string const& default_data) const {
  auto const p = stdfs::path(_path_str) / file_name;

  if (!stdfs::exists(p))
    write_file(file_name, default_data);

  auto in_stream = std::ifstream(p, std::ios::binary | std::ios::ate);
  auto file_data = std::string(static_cast<std::string::size_type>(in_stream.tellg()), '\0');

  in_stream.seekg(0);
  in_stream.read(file_data.data(), file_data.size());

  return file(file_name, file_data);
}

dt::directory const& dt::directory::write_file(std::string const& file_name, std::string const& file_data) const {
  if (std::ofstream ostrm(stdfs::path(_path_str) /= file_name, std::ios::binary | std::ios::trunc); ostrm.is_open())
    ostrm.write(file_data.data(), file_data.size());

  return *this;
}

dt::directory const& dt::directory::append_file(std::string const& file_name, std::string const& file_data) const {
  if (std::ofstream ostrm(stdfs::path(_path_str) /= file_name, std::ios::binary | std::ios::ate); ostrm.is_open())
    ostrm << file_data;

  return *this;
}
