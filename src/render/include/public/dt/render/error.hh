#pragma once

#include <exception>
#include <string>

namespace dt {

class render_error final : std::exception {
  std::string const _message;

public:
  render_error(std::string const& message) noexcept;

  ~render_error() noexcept;

  char const* what() const noexcept override;
};

}
