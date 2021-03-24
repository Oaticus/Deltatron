#pragma once

#include <exception>
#include <string>

namespace dt {

class gpu_error final : public std::exception{
  std::string const _msg;

public:
  gpu_error(std::string const& message) noexcept;

  ~gpu_error() noexcept;

  char const* what() const noexcept override;
};

}
