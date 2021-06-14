#include <dt/command.hh>
#include <dt/command_imp.hh>

dt::command::command(initializer const init)
: _command(std::make_unique<command_imp>(command_imp::initializer{.arg_size = init.arg_size, .arg_list = init.arg_list, .env_list = init.env_list})) {}

dt::command::~command() noexcept { }

bool dt::command::arg_passed(flag const f) const noexcept
{ return _command->arg_passed(f); }

std::optional<std::string_view> dt::command::arg_at(std::size_t const idx) const noexcept
{ return _command->arg_at(idx); }

std::optional<std::string> dt::command::env_value_of(std::string const& s) const noexcept
{ return _command->env_value_of(s); }
