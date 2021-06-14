#pragma once

#include <dt/command/flag.hh>
#include <dt/command/termflag_passed.hh>
#include <dt/command/args.hh>
#include <dt/command/env.hh>
#include <dt/command/flagdb.hh>
#include <dt/cmake_info.hh>

#include <optional>
#include <string>

namespace dt {

class command_imp final {
public:
  struct initializer final {
    int                const arg_size;
    char const* const* const arg_list;
    char const* const* const env_list;
  };

private:
  args   const _args;
  env    const _env;
  flagdb const _flagdb;

public:
  command_imp(initializer const init)
  : _args({.arg_size = init.arg_size, .arg_list = init.arg_list}),
    _env(init.env_list),
    _flagdb()
  {
    if (arg_passed(flag::help))
      throw termflag_passed(_flagdb.gen_helpmenu());

    if (arg_passed(flag::version))
      throw termflag_passed(DT_VERSION_STR);
  }

  std::optional<std::string> env_value_of(std::string const& s) const noexcept
  { return _env.value_of(s); }

  bool arg_passed(flag const f) const noexcept {
    auto const& flag_info = _flagdb.flag_info(f);
    return flag_info.alias.empty() ? _args.contains(flag_info.name.data())
      : _args.contains(flag_info.alias.data()) || _args.contains(flag_info.name.data());
  }

  std::optional<std::string_view> arg_next_to(std::string const& arg) const noexcept
  { return _args.next_to(arg); }

  std::optional<std::string_view> arg_at(std::size_t const idx) const noexcept
  { return _args.at(idx); }
};

}
