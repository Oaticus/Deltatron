#pragma once

#include <exception>
#include <string>

namespace dt {

class win_error final : public std::exception {
  std::string const _msg;

public:
  win_error(std::string const& msg) noexcept;

  ~win_error() noexcept;

  char const* what() const noexcept override;
};

}
