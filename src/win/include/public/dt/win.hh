#pragma once

#include <dt/cmd.hh>
#include <dt/fs.hh>

#include <memory>

namespace dt {

class win_imp;

class win final {
  std::unique_ptr<win_imp> const _win;

public:
  win(cmd const&, fs const&);

  ~win() noexcept;

  void begin_processing() const noexcept;
};

}
