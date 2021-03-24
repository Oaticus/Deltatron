#pragma once

#include <exception>
#include <string>

#include <cstdint>

namespace dt {

class json_error final : public std::exception {
  std::string const _msg;

public:
  json_error(std::string const& id, std::size_t const& line, std::string const& msg) noexcept;

  ~json_error() noexcept;

  char const* what() const noexcept override;
};

}
