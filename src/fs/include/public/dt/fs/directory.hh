#pragma once

#include <dt/fs/directory/file.hh>

#include <optional>
#include <string>

namespace dt {

class fs_imp;

class directory final {
  friend class fs_imp;

  std::string const _path_str;

public:
  ~directory() noexcept;

  directory const& mkdir(std::string const& directory_name) const;

  directory cd(std::string const& directory_name) const;

  file load_file(std::string const& file_name, std::string const& default_data = "") const;

  directory const& write_file(std::string const& file_name, std::string const& file_data = "") const;

  directory const& append_file(std::string const& file_name, std::string const& app_data = "") const;

private:
  directory(std::string const& directory_path) noexcept;
};

}
