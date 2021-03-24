#pragma once

#include <string>

namespace dt {

class file final {
  std::string const _name;
  std::string const _data;

public:
  file(std::string const& name, std::string const& data = "");

  ~file() noexcept;

  constexpr auto const& name() const noexcept { return _name; }

  constexpr auto const& data() const noexcept { return _data; }
};


}
