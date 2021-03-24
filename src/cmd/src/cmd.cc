#include <dt/cmd.hh>
#include <dt/cmd_imp.hh>

dt::cmd::cmd(int const ac, char const* const* const av, char const* const* const ep)
: _cmd(std::make_unique<cmd_imp>(ac, av, ep)) {}

dt::cmd::~cmd() noexcept { }

bool dt::cmd::arg_passed(flag const f) const noexcept
{ return _cmd->arg_passed(f); }

std::vector<std::string_view> dt::cmd::arg_view() const noexcept
{ return _cmd->arg_view(); }

std::optional<std::string_view> dt::cmd::arg_at(std::size_t const idx) const noexcept
{ return _cmd->arg_at(idx); }

std::optional<std::string> dt::cmd::env_value_of(std::string const& s) const noexcept
{ return _cmd->env_value_of(s); }


