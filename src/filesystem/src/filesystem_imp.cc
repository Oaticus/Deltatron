#include <dt/filesystem_imp.hh>

namespace dt {

stdfs::path _init_root(command const& cmd) noexcept {
  if (cmd.arg_passed(flag::local_config))
    return stdfs::path(*cmd.arg_at(0)).remove_filename();

#ifdef _WIN32
  if (auto appdata = cmd.env_value_of("APPDATA"); appdata)
    return stdfs::path(*appdata) / "Deltatron";

#else
  if (auto home = cmd.env_value_of("HOME"); home)
    return stdfs::path(*home) / ".config" / "deltatron";

#endif

  return stdfs::path(*cmd.arg_at(0)).remove_filename();
}

}

dt::filesystem_imp::filesystem_imp(command const& cmd) noexcept
: _root(_init_root(cmd))
  {
    if (!stdfs::exists(_root))
      stdfs::create_directories(_root);
  }

dt::directory dt::filesystem_imp::root() const noexcept
{ return dt::directory(_root.string()); }
