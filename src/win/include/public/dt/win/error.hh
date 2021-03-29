#pragma once

#include <exception>
#include <string>

namespace dt {

class win_error final : public std::exception {
  std::string const _message;

public:
  win_error(std::string const& message) noexcept;

  ~win_error() noexcept;

  char const* what() const noexcept override;
};

}
