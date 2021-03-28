#pragma once

#include <string>

namespace dt {

class directory;

class file final {
  friend class dt::directory;

  std::string   const  _name;
  std::string   const  _data;

public:
  file(file const&) noexcept;

  ~file() noexcept;

  constexpr auto const& name()      const noexcept { return _name;      }
  constexpr auto const& data()      const noexcept { return _data;      }

private:
  file(std::string const& name, std::string const& data);
};


}
