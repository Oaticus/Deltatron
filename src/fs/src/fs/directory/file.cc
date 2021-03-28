#include <dt/fs/directory/file.hh>

dt::file::file(std::string const& name, std::string const& data)
: _name(name),
  _data(data) {}

dt::file::file(file const& f) noexcept
: _name(f._name),
  _data(f._data) {}

dt::file::~file() noexcept {}
