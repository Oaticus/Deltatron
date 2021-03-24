#pragma once

#include <dt/cmd/flag.hh>
#include <dt/cmd/termflag_passed.hh>
#include <dt/cmd/args.hh>
#include <dt/cmd/env.hh>
#include <dt/cmd/flagdb.hh>
#include <dt/cmake_info.hh>

#include <optional>
#include <string>

namespace dt {

class cmd_imp final {
  args   const _args;
  env    const _env;
  flagdb const _db;

public:
  cmd_imp(int ac, char const* const* av, char const* const* ep)
  : _args(ac, av),
    _env(ep),
    _db()
  {
    if (arg_passed(flag::help))
      throw termflag_passed(_db.gen_helpmenu());

    if (arg_passed(flag::version))
      throw termflag_passed(DT_VERSION_STR);
  }

  std::optional<std::string> env_value_of(std::string const& s) const noexcept
  { return _env.value_of(s); }

  bool arg_passed(flag const f) const noexcept {
    auto const& flag_info = _db.flag_info(f);
    return flag_info.alias.empty() ? _args.contains(flag_info.name.data())
      : _args.contains(flag_info.alias.data()) || _args.contains(flag_info.name.data());
  }

  std::optional<std::string_view> arg_next_to(std::string const& arg) const noexcept
  { return _args.next_to(arg); }

  std::vector<std::string_view> arg_view() const noexcept
  { return _args.view(); }

  std::optional<std::string_view> arg_at(std::size_t const idx) const noexcept
  { return _args.at(idx); }
};

}
