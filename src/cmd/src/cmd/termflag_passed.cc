#include <dt/cmd/termflag_passed.hh>

dt::termflag_passed::termflag_passed(std::string const& msg) noexcept
: std::exception(),
  _msg(msg) {}

char const* dt::termflag_passed::what() const noexcept { return _msg.c_str(); }
