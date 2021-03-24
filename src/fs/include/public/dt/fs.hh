#pragma once

#include <dt/cmd.hh>

#include <dt/fs/error.hh>
#include <dt/fs/directory.hh>

#include <memory>

namespace dt {

class fs_imp;

class fs final {
  std::unique_ptr<fs_imp> _fs;

public:
  fs(cmd const& c);

  fs(fs const&) = delete;

  ~fs() noexcept;

  fs operator=(fs const&) = delete;

  directory root() const noexcept;
};

}
