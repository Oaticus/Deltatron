#pragma once

#include <exception>
#include <string>

namespace dt {

class filesystem_error final : public std::exception {
  std::string _error_message;

public:
  filesystem_error(std::string const& error_message) noexcept;

  char const* what() const noexcept override;
};

}
