#pragma once

#include <exception>
#include <string>

namespace dt {

class window_error final : public std::exception {
  std::string const _message;

public:
  window_error(std::string const& message) noexcept;

  ~window_error() noexcept;

  char const* what() const noexcept override;
};

}
