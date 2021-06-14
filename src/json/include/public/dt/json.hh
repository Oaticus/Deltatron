#pragma once

#include <dt/json/error.hh>
#include <dt/json/container.hh>

#include <string>
#include <memory>

namespace dt {

class json_imp;

class json final {
  std::unique_ptr<json_imp> const _json;

public:
  json(std::string const& id, std::string const& text_data);

  ~json() noexcept;

  json_container root() const noexcept;

  std::string str() const noexcept;

  std::string fast_str() const noexcept;
};

}
