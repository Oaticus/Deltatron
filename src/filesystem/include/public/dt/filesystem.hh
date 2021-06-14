#pragma once

#include <dt/command.hh>

#include <dt/filesystem/error.hh>
#include <dt/filesystem/directory.hh>

#include <memory>

namespace dt {

class filesystem_imp;

class filesystem final {
  std::unique_ptr<filesystem_imp> _filesystem;

public:
  filesystem(command const&);

  filesystem(filesystem const&) = delete;

  ~filesystem() noexcept;

  filesystem operator=(filesystem const&) = delete;

  directory root() const noexcept;
};

}
