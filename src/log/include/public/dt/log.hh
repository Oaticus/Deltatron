#pragma once

#include <dt/log/level.hh>

#include <dt/cmd.hh>
#include <dt/fs.hh>

#include <string>

#include <fstream>

namespace dt {

class log_imp;

class log final {
  std::string const _file_name;
  directory   const _directory;

public:
  log(directory const& log_dir, std::string const& file_name);

  ~log() noexcept;

  void write(log_level const level, std::string const& message) const noexcept;
};

}
