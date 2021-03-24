#pragma once

#include <exception>
#include <string>

namespace dt {

class fs_error final : public std::exception {
  std::string _error_message;

public:
  fs_error(std::string const& error_message) noexcept;

  char const* what() const noexcept override;
};

}
