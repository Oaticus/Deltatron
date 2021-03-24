#pragma once

#include <exception>
#include <string>

namespace dt {

class termflag_passed final : public std::exception {
  std::string const _msg;

public:
  termflag_passed(std::string const& msg) noexcept;

  char const* what() const noexcept override;
};

}
