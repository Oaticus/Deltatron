#include <dt/fs_imp.hh>

namespace dt {

stdfs::path _init_root(cmd const& c) noexcept {

#ifdef _WIN32
  return stdfs::path(*c.arg_at(0)).remove_filename();

#else
  stdfs::path root{};

  if (auto home = c.env_value_of("HOME"); home)
    ((root /= *home) /= ".config") /= "deltatron";

  return root;
#endif
}

}

dt::fs_imp::fs_imp(cmd const& c) noexcept
  : _root(_init_root(c))
  {
    if (!stdfs::exists(_root))
      stdfs::create_directories(_root);
  }

dt::directory dt::fs_imp::root() const noexcept
{ return dt::directory(_root.string(), nullptr); }
