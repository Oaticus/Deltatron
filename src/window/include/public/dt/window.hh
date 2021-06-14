#pragma once

#include <dt/command.hh>
#include <dt/filesystem.hh>

#include <memory>

namespace dt {

class window_imp;

class window final {
  std::unique_ptr<window_imp> const _window;

public:
  window(command const&, filesystem const&);

  ~window() noexcept;

  void run() const noexcept;
};

}
