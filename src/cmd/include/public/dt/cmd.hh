#pragma once

#include <dt/cmd/termflag_passed.hh>
#include <dt/cmd/flag.hh>

#include <memory>
#include <optional>
#include <string>
#include <vector>

namespace dt {

class cmd_imp;

class cmd final {
  std::unique_ptr<cmd_imp> const _cmd;

public:
  cmd(int const ac, char const* const* const av, char const* const* const ep);

  cmd(cmd const&) = delete;

  ~cmd() noexcept;

  cmd operator=(cmd const&) = delete;

  bool arg_passed(flag const) const noexcept;

  std::vector<std::string_view> arg_view() const noexcept;

  std::optional<std::string_view> arg_at(std::size_t const idx) const noexcept;

  std::optional<std::string> env_value_of(std::string const&) const noexcept;
};

}
