#pragma once

#include <dt/command/termflag_passed.hh>
#include <dt/command/flag.hh>

#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace dt {

class command_imp;

class command final {
public:
  struct initializer final {
    int                const arg_size;
    char const* const* const arg_list;
    char const* const* const env_list;
  };

private:
  std::unique_ptr<command_imp> const _command;

public:
  command(initializer const);

  command(command const&) = delete;

  ~command() noexcept;

  command operator=(command const&) = delete;

  bool arg_passed(flag const) const noexcept;

  std::optional<std::string_view> arg_at(std::size_t const idx) const noexcept;

  std::optional<std::string> env_value_of(std::string const&) const noexcept;
};

}
