#include <dt/fs/directory.hh>
#include <dt/fs/error.hh>
#include <dt/fs_imp.hh>

#include <fstream>
#include <string>

dt::directory::directory(std::string const directory_name, directory const* parent)
: _name(directory_name),
  _parent(parent) {}

dt::directory const& dt::directory::mkdir(std::string const& directory_name) const {
  if (stdfs::path p(_name); !stdfs::exists(p /= directory_name))
    stdfs::create_directory(p);

  else if (!stdfs::is_directory(p))
    throw fs_error(std::string("file entity already bound to directory name (\"") + p.string() + "\")");

  return *this;
}

dt::directory dt::directory::cd(std::string const& directory_name) const {
  if (stdfs::path const p(_name); stdfs::exists(p) && stdfs::is_directory(p))
    return directory(directory_name, this);

  throw fs_error(std::string("attempting to cd into non-existing directory (\"") + directory_name + "\")");
}

dt::file dt::directory::load_file(std::string const& name, std::string const& default_data) const {
  auto const p = stdfs::path(_name) / name;

  if (!stdfs::exists(p))
    write_file(name, default_data);

  auto istrm = std::ifstream(p, std::ios::binary | std::ios::ate);
  auto fdata = std::string(static_cast<std::string::size_type>(istrm.tellg()), '\0');

  istrm.seekg(0);
  istrm.read(fdata.data(), fdata.size());

  return file(name, fdata);
}

dt::directory const& dt::directory::write_file(std::string const& name, std::string const& fdata) const {
  if (std::ofstream ostrm(stdfs::path(_name) /= name, std::ios::binary | std::ios::trunc); ostrm.is_open())
    ostrm.write(fdata.data(), fdata.size());

  return *this;
}

dt::directory const& dt::directory::append_file(std::string const& name, std::string const& appdata) const {
  if (std::ofstream ostrm(stdfs::path(_name) /= name, std::ios::binary | std::ios::ate); ostrm.is_open())
    ostrm.write(appdata.data(), appdata.size());

  return *this;
}
