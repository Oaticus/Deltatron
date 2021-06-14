#pragma once

#include <dt/command.hh>
#include <dt/filesystem/directory.hh>

#include <filesystem>

namespace dt {

namespace stdfs = std::filesystem;

class filesystem_imp final {
  stdfs::path const _root;

public:
  filesystem_imp(command const&) noexcept;

  directory root() const noexcept;
};

}
