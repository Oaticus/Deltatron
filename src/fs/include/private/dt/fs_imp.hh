#pragma once

#include <dt/cmd.hh>
#include <dt/fs/directory.hh>

#include <filesystem>

namespace dt {

namespace stdfs = std::filesystem;

class fs_imp final {
  stdfs::path _root;

public:
  fs_imp(cmd const& c) noexcept;

  directory root() const noexcept;
};

}
